#include <ESP8266WiFi.h>

const char *ssid = "";      // wifi router name
const char *pass = "";    // wifi router password
unsigned long start_time = 0;
unsigned long my_time = 0;
bool has_ran = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);            // initialize serial communication
  delay(1000);
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.mode(WIFI_STA);             // set mode to wifi station
  start_time = millis();
  WiFi.begin(ssid, pass);          // connect to wifi router
  while (WiFi.status() != WL_CONNECTED){ // check status of connection
     delay(50);    
    Serial.print(".");
  }  
  my_time = millis() - start_time;
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");  
  Serial.println(WiFi.localIP());  // print the Ip alocated by router
  Serial.print('\n');
  Serial.println("Time to connect: ");
  Serial.println(my_time);
  //delay(500);
}

void loop() {
  
}
