This code was for testing the device's ability to connect to Google Sheets for logging data.  The data was then sent to a Google Site containing the speadsheet for display.

### Functions
1. To initialize USB flash drive for storage.
2. To connect ESP8266 to known local Wi-Fi
3. To connect to Google Sheets
4. Publish data to Google Sheets
5. Write data onto local storage
6. Synchronize transmissions between Arduino and ESP


### Dependent Libraries
1. Arduino's SPI
2. Arduino's Wire
3. Public USB Host Shield V2 library (additional custom version from u/greiman on GitHub)
4. UsbFat by u/greiman (William Greiman developed the USBFat library that is now publicly available.  Our gratitude is great.)
5. HTTPSRedirect by u/StorageB107 and u/electronicsGuy
6. Arduino Community ESP8266 library

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload
