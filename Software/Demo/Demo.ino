#include <SPI.h>
#include <UsbFat.h>
#include <masstorage.h>
#include "Wire.h"

// USB host objects.
USB usb;
BulkOnly bulk(&usb);

// File system.
UsbFat key(&bulk);

// File object to open/close/write to
File file;

const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data
String accelerometer_xS, accelerometer_yS, accelerometer_zS; // variables for accelerometer raw data
String gyro_xS, gyro_yS, gyro_zS; // variables for gyro raw data
String temperatureS; // variables for temperature data
String data;
String something;

char tmp_str[7]; // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial1.begin(9600);
  delay(1000);
  Serial.flush();
  Serial1.flush();
  Serial.print(F("\n\rFreeRam "));
  Serial.println(FreeRam());
  //Serial.println(F("Type any character to begin"));
  //while (Serial.read() < 0) {}
  
  // Initialize the USB bus.
  while (!initUSB(&usb))
  {
    Serial.println(F("initUSB Failed"));
    delay(50);
  }
  // Init the USB key or USB hard drive.
  if (!key.begin()) {
    Serial.println(F("key.begin failed"));
    return;
  }
  Serial.print(F("\r\nVolume Size: "));
  // Avoid 32-bit overflow for large volumes.
  Serial.print((key.volumeBlockCount()/1000)*512/1000);
  Serial.println(F(" MB"));
  
  // Print a line to a test file.
  file.open("Data.txt", O_CREAT | O_RDWR);
  file.println("|  Accel X  ||  Accel Y  ||  Accel Z  ||   Temp   ||  Gyro X  ||  Gyro  Y  ||  Gyro  Z  ||  Distance  |");
  file.close();
  
  // List the files in the root directory.
  Serial.println();
  key.ls(LS_A | LS_DATE | LS_SIZE);
  Serial.println();
  
  Serial.println(F("Done")); 

  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  delay(15000);              //Let ESP warmup and connect to Wi-Fi
}

void fileApp(String buf, File f)
{
  f.open("Data.txt", O_WRITE | O_APPEND);
  
  //f.print(F("\r"));
  f.print(F("\n"));                               //Space out data option
  //f.print(F(","));                              //Optional comma to separate before
  for(int i = 0; i < buf.length(); i++)
  {
    f.print(buf[i]);                              //Print buffer to file character by character
  }
  //f.print(F(","));                              //Optional comma as a delimeter after
  f.println();
  f.close();
}

void loop() {
  // put your main code here, to run repeatedly:
  float volts = 0.0;
  float cm = 0.0;
  int Voltsadc=analogRead(A0);
  volts = Voltsadc*5.0/1023.0;
  cm = 25.826*pow(volts,-1.1);
  String result = (String)cm;
  //Serial.print(cm);Serial.println(" cm");

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

  // print out data
  accelerometer_xS = (convert_int16_to_str(accelerometer_x));
  accelerometer_yS = (convert_int16_to_str(accelerometer_y));
  accelerometer_zS = (convert_int16_to_str(accelerometer_z));
  temperatureS = (convert_int16_to_str(temperature/340.00+36.53));
  gyro_xS = (convert_int16_to_str(gyro_x));
  gyro_yS = (convert_int16_to_str(gyro_y));
  gyro_zS =  (convert_int16_to_str(gyro_z));


  data=("aX = ")+accelerometer_xS+(" aY = ")+accelerometer_yS+(" aZ = ")+accelerometer_zS+(" tmp = ")+temperatureS+(" gX = ")+gyro_xS+(" gY = ")+gyro_yS+(" gZ = ")+gyro_zS+(" Distance = ")+result+('\n');

  Serial.println(data);
  fileApp(data, file);
  Serial1.println(data);  
  // delay for 2 Hz
  delay(500);
}
