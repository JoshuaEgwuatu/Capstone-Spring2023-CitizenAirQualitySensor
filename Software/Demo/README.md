The code used for the Minimal Functionality prototype Arduino Mega 2560.
### Function
1. Samples sensor data from two sensors.
2. Formats and stores the data onto a local USB Fat32 flash drive.  The flash drive is expected to already be inserted on startup.
3. The data is sent as a string to an ESP8266 through UART.
4. Samples rate is set to 2 Hz.

### Dependent Libraries
1. Arduino's SPI
2. Arduino's Wire
3. Public USB Host Shield V2 library (additional custom version from u/greiman on GitHub)
4. UsbFat by u/greiman

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload

