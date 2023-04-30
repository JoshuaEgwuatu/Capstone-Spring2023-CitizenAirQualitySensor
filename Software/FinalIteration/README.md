This code is the final interation and should be used for sampling, logging, and sending data. The data is sent to a Google Sheet for display. If a user doesn't wish to use a Google Sheet and only use the USB, use [InterruptTest](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/tree/main/Software/InterruptTest)

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
5. HTTPSRedirect by u/StorageB107 and u/electronicsguy
6. Arduino Community ESP8266 library

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload Arduino code
7. Set port target to ESP8266
8. Compile and Upload ESP code
9. Create Google Sheet
10. Attach Google Script to Google Sheets via the Extensions tab
11. Edit Google Script with desired changes
12. Save and deploy script to be public
13. Save and Run script

More detailed instructions for Google Sheets can be found in the HTTPSRedirect library.
