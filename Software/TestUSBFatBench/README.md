This code was for testing the USB Host Shield's Writing and Read speeds to a USB Fat32 flash drive. 

### Functions
1. Initialize and prepare the Fat32 for usage.
2. Creating a generic file to write to and read from on a Fat32.  
3. Writing to the file as fast as possible while recording statistical data.
4. Read from the file as fast as possible while recording statistical data.
5. Display statistical data.

### Dependent Libraries
1. 
2. Public USB Host Shield V2 library (additional custom version from u/greiman on GitHub)
3. UsbFat by u/greiman (This test was based on the example code provided by William Greiman in is public USBFat library for Arduino.  Major gratitude for his work and generosity in sharing his testing methods)

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload
