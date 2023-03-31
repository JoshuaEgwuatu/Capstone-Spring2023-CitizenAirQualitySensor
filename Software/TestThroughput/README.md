This code was for testing the throughput of the ESP8266 using our device.  This is the client code for sending the alphabet as much asa possible over 1 second to a server that only receives data.

### Functions
1. Connect to the Internet via Wi-Fi
2. Connect to a generic receive server
3. Mark the time of connection and begin testing
4. Send data as fast as possible.
5. Stop after 1 second and repeat the number of transmissions made.

### Dependent Libraries
1. Arduino Community ESP8266 library

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload
