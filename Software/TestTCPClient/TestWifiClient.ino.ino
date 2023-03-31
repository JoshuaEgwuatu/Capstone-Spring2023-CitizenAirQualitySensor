#include <ESP8266WiFi.h>

const char *ssid = "Verizon-SM-S901U-3BF7";      // wifi router name
const char *pass = "mydw318(";    // wifi router password
const char *host = "192.168.225.17"; // server IP Address
const int port = 54000;            // server port
int flag = 1;      // flag to check for connection existance
bool read = 0;
bool connected = 0;
bool run = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);            // initialize serial communication
delay(1000);
Serial.print("Connecting to ");  
Serial.println(ssid);  
WiFi.mode(WIFI_STA);             // set mode to wifi station
WiFi.begin(ssid, pass);          // connect to wifi router
while (WiFi.status() != WL_CONNECTED){ // check status of connection
   delay(500);    
   Serial.print(".");
}  
Serial.println("WiFi connected");  
Serial.println("IP address: ");  
Serial.println(WiFi.localIP());  // print the Ip alocated by router
delay(500);
}

void loop() {
  if (Serial.available())
  {
    WiFiClient client;                      //Client object 
    client.connect(host, port);             //Connect to server
    while(!client.connected())              //Make sure client is connected
    {
      delay(500);    
      Serial.print(".");
    }
    Serial.println("Connected to server");

    if (client.connected())                         //Client connected to server
    { // check if connection exists
      String str = Serial.readStringUntil('\n');             //Read str from UART
      str.trim();                                   //Trim str of extra characters
      client.println(str);                          //Send str to server
      read = 1;
      client.stop();
      Serial.println("Disconnected to server");
    }      
    delay(50);
    run = 0;
  }
}
