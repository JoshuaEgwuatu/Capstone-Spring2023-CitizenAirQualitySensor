This code is for testing the functionality of an HTTP Client service for the ESP8266.

### Function
1. Connect to local Wi-Fi network (presumably known by the user)
2. Wait for a piece of data to be received via UART (delimeter '\n')
3. Establish connection with server
4. Send received data as a POST request
5. Receive any kind of payload from server and terminate connection to server
6. Await for new data

### Dependent Libraries
1. Arduino Community ESP8266 library

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the ESP8266-Node-Module12E
6. Compile and Upload
