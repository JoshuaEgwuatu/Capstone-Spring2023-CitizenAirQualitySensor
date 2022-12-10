Interface Signoff

Subsystem Function
The interface will house up 3 analog/digital based sensors at a time and output the recieved data to the microcontroller.                                                                                                   
Subsystem Constraints
Interface must support sensors of different classes that output or receive analog voltage,analog current and digital signals.
Interfaces must provide 3 or 5VDC to support sensors with different voltage requirements.

System Schematic

![Interface Schematic](https://user-images.githubusercontent.com/118490274/206822519-73ab0610-30a2-4b01-a183-2ac593d38109.JPG)



Chosen Component Analysis
The datasheet for the 3SP CO 1000 sensor has pin 1 as VCC, pin 4 as GND, and pin 5 as counter/data out and is connected to the analog pin 0 on the board because the 3SP sensor is an analog based device. Pin 1 is connected to 3 volts dc which is the needed supply voltage as requested in the datasheet.
The pinout according to the DGS CO 968 datasheet is pin 1 connected to RXD, pin 2 is TXD, pin 6 is GND, and pin 8 is V+. Pin 8 is connected to a 3 volt source which is within the sensor's supply voltage range of 2.6 volts to 3.6 volts. Pin 2 is RXD and is connected to the RX1 communication pin on the board and pin 3 is connected to TX1.
SEN0131 is connected to a 5 volt source which is the required supply voltage needed for the device. Pin 1 is connected to an analog pin on the board because the SEN0131 is an analog based sensor.

BOM
Designator	Manufacturer	Manufactured Part #	Description	Quantity	Price Each	
B1	REXQualis	RG-BK-4	Breadboard (Will be the bridge between sensors and interface.	1	$11.98	
