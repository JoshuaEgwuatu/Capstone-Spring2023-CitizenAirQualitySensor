# Sensor Subsystem Signoff
## FUNCTION OF THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The sensor subsystem will be designed to take commands from the Microcontroller Subsystem and execute the tasks for an extended period of time. These sensors will analyze and receive data from the outside and send the new data from the interface straight to the microcontroller. Within this subsystem, the sensors will take and measure the data differently, but give the same information back for the user to obtain. Therefore, the Sensor Subsystem is an integral part of the process.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; For experimental purposes, the design team has decided to get multiple types of sensors for the modular functionality to the device. 
These types are digital, analog voltage, and analog current output sensors. While the digital sensors send bits describing the measurement of a specific parameter, the 
analog sensors send their signals a bit differently. There are pros and cons on analog voltage or current signals in many regards. Voltage outputs for analog components
are more common, but current signals are faster and less likely to lose current or voltage drops in the signal process. Current analog sensors have an extra step where 
a built-in transmitter in the component takes the voltage and sets a current range for the signal to be generated. Once the current signal gets to the microcontroller, 
it would need to go back to its voltage via a load resistor. The team plans on getting various types of sensors for the design process of this subsystem so that the user of the Air Quality Device will be able to use the modular sensor inputs for most of the sensors that the user desires.

## CONSTRAINTS ON THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The subsystem constraints are placed to ensure that it can fulfill its job in a satisfactory manner.  The constraints given below are structured to meet the qualifications of functionality, modularity, and sampling rate for the digital, analog voltage, and current sensors. Constraints on the subsystem are as follows:

1. Shall have a selection of tested sensors to cover a range of pollutants, particulates, air composites, and other qualities.  Common qualities to measure are carbon monoxide, lead, nitrogen oxides, ozone, particulate matter, and sulfur dioxide.  Other qualities may be selected in the future, but these are definite qualities to look for.  These sensors should work independently from each other.

2. Shall be modular. Specifically, the change of sensor should be seamless and handled by the board and software. The sensors will have multiple kinds of Input/Output (I/O) ports, so a list will be made that acknowledges all I/O ports of sensors to be approved and tested. The I/O ports that are shared among a group of sensors should be able to operate seamlessly if swapped out from the same type of I/O port for another sensor in the group using that I/O port.  Sensors that do not share this I/O port will have a port of its own grouping that has this same functionality within that group.

3. Each sensor must be able to communicate with the microcontroller using a communicative language such as Serial Peripheral Interface (SPI), or Universal Asynchronous Receiver-Transmitter (UART). The microcontroller for this design will also be able to communicate with those same data transfer techniques. 

4. Shall be able to operate with at least 3 sensors sampling independently of each other.  Sensors will take samples at set intervals and be read and stored on the device periodically.  Samples may be received and outputted one at a time.

5. According to the Pacific Marine Environmental Laboratory [1], the speed for sample rates when receiving analog or digital signal input from the sensors should be sampled at a rate at approximately 2 Hz with a sample period of 30 seconds. Having sample rates that are too low causes data to be lost in the calibration process.

6. The input voltages from the interface will provide either 3 or 5 V DC. Therefore, each sensor that will be used for the device shall have input voltages of either value. Appropriate current and power supply to the load will also have similar values for each sensor.

7. For every sensor that is plugged onto the Air Quality Device initially, there may be a start up time for initial calibration. All sensors shall start data acquisition once the timer goes to 0, and the microcontroller signals the sensors to start.


## BUILDABLES OF THE SUBSYSTEM

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; This sample code is based on the Analog Voltage sensor for the MQ7 datasheet. We may reference this for future software design.
![Buildable Sensor Subsystem Sample Code](https://user-images.githubusercontent.com/118767661/204166232-bc152fba-989f-4139-976a-944a0f5c61cc.png)

## ANALYSIS OF THE SUBSYSTEM

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The team has chosen 3 sensors for testing that potentially matches with the constraints list. We wanted for each to be a 
different type of sensor output to test modularity and implement the necessary actions required within the software to model the functionality of both the 
Microcontroller and Sensor Subsystems. All sensors chosen for experimentation are for detecting Carbon Monoxide, one of the 6 pollutants that our team is wanting for 
data input. Therefore, one sensor outputs digital values, and the next sensor outputs analog voltage. Thus, the third device for testing will be an analog current 
sensor so progress on all types can be made in the design process.

### This is the analysis of the SEN0132 - (Analog Voltage):

●	The SEN0132 Carbon Monoxide Gas Sensor is a quarter-sized PCB mounted with a CO detector that has high sensitivity. This sensor is able to detect the pollutant 
anywhere from 20-2000 ppm. The sensitivity can be changed with the potentiometer located next to the detector.

●	The SEN0132 has an input voltage range of 1.4V - 5V, but 5V is recommended for the accurate output of this sensor. Also having a decent power consumption with 350mW 
on average.

●	The SEN0132 contains 3 pins on the other side of the PCB. Pin 1 is for output, 2 is GND, and of course, Pin 3 is for 5V. This makes wiring easier for the user and 
does not put too much force on current or wattage.

●	Lastly, the sensor is commonly used with Arduino devices which we plan to use for the microcontroller. Sample code tasked to receive input from the sensor is shown 
within the “Buildables of the Subsystem” section.

### Analysis of the 3SP_CO_1000 Package 110-102 - Model 110-102 - (Analog Current):

●	This CO sensor contains a 6 pin interface for the full functionality of the PCB. Most of the pins have no connection (NC), but the important ones are the working 
pin, reference pin, and counter pin.

●	The 110-102 sensor calls for a supply voltage of  around 3V. Therefore, this will consume even less power and can control current output for more accurate 
measurements within the parameters. The power consumption is on average 10-50 microwatts.

●	The analog current sensor has a measurement range of 0 - 1,000 Part-per-Million (ppm). Having a wide range will give the user a range of accuracy and levels of 
precise calculations. 

●	The PCB below the sensor contains a nice feature of having the ability to switch the gas sensor for other pollutants as well. This can allow the user to replace the 
CO sensor with another pollutant detector, or a different type of gas detector for more convenience and modularity.

### Analysis of the DGS-CO 968-034 - (Digital):

●	The DGS-CO is a digital carbon monoxide detector that has the same modular feature as the analog current gas sensor. This means we can switch detectors for 
experimentation on whether the components meet our specifications.

●	The supply voltage requirement is in a range of 2.6 - 3.6V with a power gumption range of 0.15 - 12 mW. The power and voltage requirements depend on the periodic 
functions of this device. As we start configuration we can pinout the exact parameters to be met for the subsystem.

●	This Digital sensor also has the same range as the analog current sensor with 0 -1,000 ppm.

●	Lastly, the connections are configured by the PCB to communicate using UART. While this is not SPI, we believe it is still possible to communicate with this sensor 
because the microcontroller is able to communicate to other devices in that language as well.

## BILL OF MATERIALS

|Item Name|Manufactured Part #|Quantity|Description|Price|
|----------|-------------------|--------|-----------|-----|
|Carbon Monoxide Gas Sensor(MQ7)|SEN0132|1|Analog Voltage CO Gas Sensor|$9.85|
|3SP_CO_1000 Package 110-102|110-102|1|Analog Current CO Gas Sensor (Modular with Digital Sesnor)|$20|
|DGS-CO 968-034|968-034|1|Digital CO Gas Sesnor (Modular with Analog Current Sensor) if out of stock, 968-001 is similar option.|$50|

## REFERENCES

1. Pacific Marine Environmental Laboratory Gas Sensor Sampling Rate Standards “Sampling Rates” https://www.pmel.noaa.gov/ocs/sampling-rates (Accessed on 1-31-23).
