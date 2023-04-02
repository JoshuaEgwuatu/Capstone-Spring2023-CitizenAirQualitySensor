#include <UsbFat.h>
#include <masstorage.h>


// USB host objects.
USB usb;
BulkOnly bulk(&usb);

// File system.
UsbFat key(&bulk);

// File object to open/close/write to
File file;

bool has_ran = 0;
unsigned long start_time = 0;
unsigned long my_time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.flush();
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
  file.open("Data.txt", O_CREAT | O_RDWR | O_APPEND);
  file.close();
  // List the files in the root directory.
  Serial.println();
  key.ls(LS_A | LS_DATE | LS_SIZE);
  Serial.println();
  
  Serial.println(F("Done")); 
  start_time = millis();
}

void loop() {
  if (has_ran == 0)
  {
    file.open("Data.txt", O_WRITE | O_APPEND);
    my_time = millis() - start_time;
    file.close();
    Serial.println(my_time);
    has_ran = 1;
    Serial.flush();
  }
}
