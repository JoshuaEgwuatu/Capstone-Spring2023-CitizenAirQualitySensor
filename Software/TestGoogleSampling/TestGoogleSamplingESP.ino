// Example Arduino/ESP8266 code to upload data to Google Sheets
// Follow setup instructions found here:
// https://github.com/StorageB/Google-Sheets-Logging
// reddit: u/StorageB107
// email: StorageUnitB@gmail.com
// Modified by TNTECH ECE Capstone Team 1 2022-2023

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"

// Enter network credentials:
const char* ssid     = "NETWORK-NAME-HERE"; //network ID
const char* password = "NETWORK-PASSWORD-HERE"; //Password 

// Enter Google Script Deployment ID:
const char *GScriptId = "GOOGLE-SCRIPT-ID-HERE";

// Enter command (insert_row or append_row) and your Google Sheets sheet name (default is Sheet1):
String payload_base =  "{\"command\": \"insert_row\", \"sheet_name\": \"Sheet1\", \"values\": ";
String payload = "";

// Google Sheets setup (do not edit)
const char* host = "script.google.com";
const int httpsPort = 443;
const char* fingerprint = "";
String url = String("/macros/s/") + GScriptId + "/exec";
HTTPSRedirect* client = nullptr;

String data = ""; //variable that will be published to Google Sheets
void setup() 
{
  Serial.begin(9600);        
  delay(3000);

  //Connect to WiFI
  WiFi.begin(ssid, password);       
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  
  // Use HTTPSRedirect class to create a new TLS connection
  client = new HTTPSRedirect(httpsPort);
  client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");
  
  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i=0; i<5; i++){ 
    int retval = client->connect(host, httpsPort);
    if (retval == 1){
       flag = true;
       Serial.println(); //added to avoid anything put in serial on startup
       Serial.println("Connected");
       break;
    }
  }
  delay(50);
  delete client;    // delete HTTPSRedirect object
  client = nullptr; // delete HTTPSRedirect object
}

void loop() 
{
  if(Serial.available())
  {
    static bool flag = false;
    if (!flag){
      client = new HTTPSRedirect(httpsPort);
      client->setInsecure();
      flag = true;
      client->setPrintResponseBody(true);
      client->setContentTypeHeader("application/json");
    }
    if (client != nullptr){
      if (!client->connected()){
        client->connect(host, httpsPort);
      }
    }
  
    // Create json object string to send to Google Sheets
    data = Serial.readStringUntil('\n'); //read from ardunio 
    payload = payload_base + data;
  
    // Publish data to Google Sheets
    if(client->POST(url, host, payload)){ 
      // do stuff here if publish was successful
    }
    else{
      // do stuff here if publish was not successful
    }
  
    // a delay of several seconds is required before publishing again  
    while(Serial.available()){
      Serial.read();
    }
  }
}
