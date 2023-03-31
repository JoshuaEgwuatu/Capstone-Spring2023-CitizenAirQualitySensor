#include <ESP8266WiFi.h>

const char *ssid = "";      // wifi router name
const char *pass = "";    // wifi router password
const char *host = ""; // server IP Address
const int port = 54000;            // server port
int count = 0;
unsigned long start_time = 0;
unsigned long my_time = 0;
WiFiClient client;                      //Client object 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);            // initialize serial communication
  delay(100);
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.mode(WIFI_STA);             // set mode to wifi station
  WiFi.begin(ssid, pass);          // connect to wifi router
  while (WiFi.status() != WL_CONNECTED) // check status of connection
  {
    delay(500);    
    Serial.print(".");
  }  
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");  
  Serial.println(WiFi.localIP());  // print the Ip alocated by router
  delay(500);
    client.connect(host, port);             //Connect to server
    while(!client.connected())              //Make sure client is connected
    {
      delay(50);    
      Serial.print(".");
    }
    Serial.println("Connected to server");
  start_time = millis();
}

void loop() {
  my_time = millis() - start_time;
  if (my_time < 1000)
  {
    if (client.connected())                         //Client connected to server
    { // check if connection exists
      String str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";             
      //str = str + str;                            //Add sets of the alphabet to itself however many times you are testing
      client.println(str);                          //Send str to server
      //client.stop();
      //Serial.println("Disconnected from server");
      count++;
    }  
  }   
  Serial.println(count); 
}
