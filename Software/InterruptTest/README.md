This code was for testing the interrupt capabalities of the Arduino Mega.  The test was to see if an entirely interrupt driven version of the demo.ino was possible.
It was recreated using a timer interrupt to call for the sampling of the sensors every 1 Hz.

### Functions
1. All functions of the demo.ino needed to be recreated
2. Interrupt driven programming meant that nothing should have been in the main loop. 
3. Sampling only occurs when the timer rolls over

### Dependent Libraries
1. Arduino's SPI
2. Arduino's Wire
3. Public USB Host Shield V2 library (additional custom version from u/greiman on GitHub)
4. UsbFat by u/greiman (William Greiman developed the USBFat library that is now publicly available.  Our gratitude is great.)

### Installation
1. Download and install latest version of the Arduino IDE
2. git clone the required libraries
3. git clone the target file
4. Launch Arduino and open the target file
5. Set the port to target the Arduino Mega
6. Compile and Upload
