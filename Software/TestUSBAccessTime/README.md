This code was for testing the time it takes to access the USB Fat32 flash drive connected to the USB Host Shield. 

### Functions
1. Initialize and prepare the Fat32 for usage.
2. Creating a generic file to open on a Fat32.  
3. Mark a start time.
4. Access the file by attemtping to open it.
5. Mark the end time.
6. Close the file and display the access time in milliseconds.

### Dependent Libraries
1. 
2. Public USB Host Shield V2 library (additional custom version from u/greiman on GitHub)
3. UsbFat by u/greiman (Major thanks to William Greiman for his public library on Fat32 usage)

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload
