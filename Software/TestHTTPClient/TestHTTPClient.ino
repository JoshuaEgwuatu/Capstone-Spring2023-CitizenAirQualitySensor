#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* this can be run with an emulated server on host:
        cd esp8266-core-root-dir
        cd tests/host
        make ../../libraries/ESP8266WebServer/examples/PostServer/PostServer
        bin/PostServer/PostServer
   then put your PC's IP address in SERVER_IP below, port 9080 (instead of default 80):
*/
//#define SERVER_IP "10.0.1.7:9080" // PC address with emulation on host
#define SERVER_IP "192.168.225.17"

#ifndef STASSID
#define STASSID "Network ID"
#define STAPSK "Network Password"
#endif

void setup() 
{

  Serial.begin(9600);

  Serial.println();
  Serial.println();
  Serial.println();

  //Connect to Wi-Fi with Network name and Password
  WiFi.begin(STASSID, STAPSK);  

  //Wait for Wi-Fi to be connected
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // wait for WiFi connection
  if (Serial.available())
  {
   if ((WiFi.status() == WL_CONNECTED)) 
   {
      WiFiClient client;
      HTTPClient http;

      Serial.print("[HTTP] begin...\n");
      // configure traged server and url
      http.begin(client, "http://" SERVER_IP "/postplain/");  // HTTP
      http.addHeader("Content-Type", "application/json");     //Type and destination on server

      Serial.print("[HTTP] POST...\n");
      // start connection and send HTTP header and body
      String data = Serial.readStringUntil('\n');
      int httpCode = http.POST(data);               //As far as I can tell, this is how you send the data

      // httpCode will be negative on error
      if (httpCode > 0) 
      {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) 
        {
          const String& payload = http.getString();           //Response from the server
          Serial.println("received payload:\n<<");
          Serial.println(payload);
          Serial.println(">>");
        }
      } 
      else
      {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }

    delay(10000);
  }
}
