# Sensor Subsystem Signoff
## FUNCTION OF THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The Sensor Subsystem will be designed to give various data to the Microcontroller Subsystem through the Interface Subsystem. As data acquisition starts, the output of each analog sensor goes through the Interface for voltage/current regulation to the microcontroller.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Within this Sensor Subsystem, the design team has decided to get multiple types of sensors for the modularity of the device. These types are digital, analog voltage, and analog current sensors. While the digital sensors send bits describing the measurement of a specific parameter, the analog sensors send their signals a bit differently. Analog sensors output analog signals which are different to measure from bits [11], therefore the Interface Subsystem will provide assistance in parameter conversion to the microcontroller.

## CONSTRAINTS ON THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Constraints on the subsystem are as follows:

1. The sensors shall be able to measure carbon monoxide, lead monoxide, nitrogen oxide, ozone, particulate matter, and sulfur dioxide. These sensors should work independently from each other.

2. Shall be modular. Specifically, the change of sensors should be seamless and handled by the board and software. The sensors will have multiple kinds of Input/Output (I/O) ports. For a sensor to be in the same group, it must share the same voltage supply, current consumption, communication technique through the interface, and output the signal at the range of 0 - 10 VDC or 4 - 20 mA [12].

3. Each sensor must be able to communicate with the microcontroller using a communicative language. The sensors shall communicate through Serial Peripheral Interface (SPI), Universal Asynchronous Receiver-Transmitter (UART), or Inter-Integrated Circuit (I2C). The microcontroller for this design will also be able to communicate with those same data transfer techniques.  

4. For windy environments, the sampling rate should be at most 100Hz [3]. For indoor monitoring, ambient gas sensors will be sampled at the lowest rate of 2 Hz per second based on the diffusion of ambient air quality [1]. Thus, depending on the location/weather/wind/etc, the sensor should sample at specific ranges for indoor and outdoor measurements.

5. The input voltages from the Power Subsystem will provide either 3 or 5 V DC. Therefore, each sensor that will be used for the device shall have input voltages of either value. From looking at multiple gas sensors for this project, the maximum worst case for wattage in this subsystem is 375 mW. Maximum current consumption for sensors is 75 mA.

6. For every sensor that is plugged onto the Air Quality Device initially, there may be a start up time for initial calibration. All sensors shall have a wait/warm-up time less than 2 hours before data acquisition.

7. According to the ANSI/ASHRAE Standard 62.1-2016: Ventilation for Acceptable Indoor Air Quality [2], indoor CO2 concentrations no greater than 700 parts per million (ppm) above outdoor CO2 concentrations will satisfy a substantial majority (about 80%) of occupants. Sensors used for this device shall comply with their pollutant concentration with this standard for indoor/outdoor use.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; O3 - At least 0.08 parts per million inside and 0.115 ppm outside [8].

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; SO2 - At least 0.02 ppm inside and 0.14 outside annually [9].

## BUILDABLES OF THE SUBSYSTEM

![CAPSTONE II Sensor Subsystem](https://user-images.githubusercontent.com/118767661/220430088-dc5df317-ef82-4628-a876-0c82efdccfef.png)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 1. Sensor Subsystem through Interface Schematic

![Screenshot (229)](https://user-images.githubusercontent.com/118767661/220430812-1e9725cd-139a-45dc-94f5-ec22bebd58c4.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 2. Sample code for the MIKROE-2767

![Screenshot (231)](https://user-images.githubusercontent.com/118767661/220431271-221e77c1-a7d6-4de3-9dff-db658f13ef42.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 3. Sample Code for the A02P43B7001

## ANALYSIS OF THE SUBSYSTEM

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The team has chosen 3 sensors for testing that matches with the constraints list. We wanted each to be a different type of sensor output to test modularity and implement the necessary actions required within the software to model the functionality of both the Microcontroller, Interface, and Sensor Subsystems. All sensors chosen for experimentation are for detecting one of the 6 pollutants that the proposal has stated for data input.

### ANALOG VOLTAGE SENSOR

#### Analysis of the MIKROE-2767 [4]- (Analog Voltage):

●	The MIKROE-2767 Ozone (O3) Gas Sensor is a quarter-sized PCB mounted with a MQ131 detector that has high sensitivity depending on the potentiometer. This sensor is able to detect the pollutant anywhere from 10‐1000 Part-Per-Million (ppm). {1},{7}

●	The MIKROE-2767 is able to communicate with the microcontroller using SPI and UART. Thus, the sensor will be able to send data for the user to store. {3}

●	The MIKROE-2767 has an input voltage range of 3.3V - 5V therefore, this particular sensor can be powered by both voltage supply options. Based on the Schematic (Schematic Reference!), the current computation is in the range of 5 uA - 33 uA. {5}

●	The UART source code can be seen in the Buildables of the Subsystem section within the document. (See Figure 2.)

### ANALOG CURRENT SENSOR

#### Analysis of the ULPSM-IAQ 968-008 [6] with the A02P43B7001 [5] - (Analog Current):

●	The A02P43B7001 gas detector is able to detect Sulfur Dioxide (SO2) which is within the list of pollutants to be acquired. {1}

●	The ULPSM-IAQ 968-008 below the detector contains a nice feature of having the ability to switch the gas detectors for other pollutants as well. This can allow the user to replace the SO2 sensor with another pollutant detector, or a different type of gas detector for more convenience and modularity. {2}

●	The SO2 gas detector can also communicate with the microcontroller using UART for data transfer. {3}

●	The ULPSM-IAQ 968-008 will be under what the gas detector is mounted on. calls for a supply voltage of  around 3.3V. Therefore, this will consume even less power and can control current output for more accurate measurements within the parameters. The power consumption is on average 30 uW. Also, the corresponding current consumption is 10uA on average. {5}

●	The A02P43B7001 will operate at the same voltage supply of 3.3V with an LED indicator telling the user that the sensor is operating in the ON position. During this time, the SO2 sensor has a max operating current of 1.17 mA and a max power consumption of 3.7 mW. {5}

●	The analog current detector has a measurement range of 0 - 5 ppm. Having a wide range will give the user a range of accuracy and levels of precise calculations. {7}

●	A method sample code for the SO2 detector to communicate with the Master device can be seen within the Buildables of the Subsystem section. (See Figure 3.)

### DIGITAL SENSOR

#### Analysis of the DGS-CO 968-034 [7] - (Digital):

●	The DGS-CO is a digital carbon monoxide detector that has a similar modular feature as the analog current gas sensor. This means we can switch detectors for experimentation on whether the components meet our specifications. {1},{2}

●	The connections are configured by the PCB to communicate using UART as well. {3}

●	The supply voltage is available for a 3.3V supply with a power gumption range of 0.15 - 12 mW. The current consumption also has a range of 0.05 mA - 4 mA. Values for the power, voltage, and current requirements depend on the operating periodic functions of this device. {5}

●	This Digital sensor has a range of 0 -1,000 ppm. {7}

### GPS SENSOR

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Another sensor to be applied in the project is used for GPS location. The RAK1910 [10] can do this task while also corresponding to the constraints provided.

●	The RAK1910 can take 3.3V with low amperage consumption. The worst case being 22 mA. {5},{2}

●	The GPS sensor can communicate using UART or I2C, being compatible with the microcontroller in use. {3}

●	30 second cold start-up time. {6}

## BILL OF MATERIALS

|Item Name|Manufactured Part #|Quantity|Description|Price|
|----------|-------------------|--------|-----------|-----|
|OZONE 2 CLICK|MIKROE-2767|1|Analog Voltage O3 Gas Sensor|$45.00|
|Analog Gas Sensor Module|ULPSM-IAQ 968-008|1|Analog Current Gas Sensor (Modular with Digital Sesnor)|$50.00|
|Allsensing gas sensor module|A02P43B7001|1|SO2 GAS SENSOR|$163.62|
|WisBlock GNSS Location Module|RAK1910|1|Tracks the GPS and the GLONASS signals|$17.00|
|Digital Gas Sensor Module|DGS-CO 968-034|1|Digital Gas Sesnor (Modular with Analog Current Sensor) if out of stock, 968-001 is similar option.|$50.00|

## REFERENCES

1. Pacific Marine Environmental Laboratory Gas Sensor Sampling Rate Standards “Sampling Rates” https://www.pmel.noaa.gov/ocs/sampling-rates (Accessed on 1-31-23).

2. The National Institute for Occupational Safety and Health (NIOSH) “Indoor Environmental Quality” https://www.cdc.gov/niosh/topics/indoorenv/hvac.html (Accessed on 2-16-23).

3. UC Irvine Machine Learning Repository “Gas sensor arrays in open sampling settings Data Set” http://archive.ics.uci.edu/ml/datasets/gas+sensor+arrays+in+open+sampling+settings (Accessed on 2-16-23).

4. MIKROE-2767 Datasheet “Ozone 2 click” https://media.digikey.com/pdf/Data%20Sheets/MikroElektronika%20PDFs/MIKROE-2767_Web.pdf (Accessed on 2-13-23).

5. A02P43B7001 Datasheet https://media.digikey.com/pdf/Data%20Sheets/Allsensing%20PDFs/AGSM-SO2-5.pdf (Accessed on 2-16-23).

6. ULPSM-IAQ 968-008 Datasheet “Ultra-Low Power Analog Sensor Module for IAQ” https://www.spec-sensors.com/wp-content/uploads/2016/10/ULPSM-IAQ-968-008.pdf (Accessed on 2-16-23).

7. DGS-CO 968-034 Datasheet “Digital Gas Sensor – Carbon Monoxide” https://www.spec-sensors.com/wp-content/uploads/2017/01/DGS-CO-968-034.pdf (Accessed on 2-16-23).

8. San Joaquin Valley Air Pollution Air District “Ozone Standards” https://www.valleyair.org/Air_Quality_Plans/AQ_plans_Ozone_standards.htm#:~:text=Federal%20Standards&text=EPA%20ozone%20standard%20is%20an,for%20primary%20and%20secondary%20standards (Accessed on 2-17-23).

9. United States Environmental Protection Agency “Timeline of Sulfur Dioxide National Ambient Air Quality Standards (NAAQS)” https://www.epa.gov/so2-pollution/timeline-sulfur-dioxide-national-ambient-air-quality-standards-naaqs (Accessed on 2-17-23).

10. RAK1910 WisBlock GNSS Location Module Datasheet https://docs.rakwireless.com/Product-Categories/WisBlock/RAK1910/Datasheet/#overview (Accessed on 2-17-23).

11. RF Wireless World “Analog sensor vs Digital sensor | Difference between Analog sensor and Digital sensor” https://www.rfwireless-world.com/Terminology/Analog-sensor-vs-Digital-sensor.html (Accessed on 2-20-23).

12. GasLab “Analog and Digital Gas Sensors: What’s the Difference?” https://gaslab.com/blogs/articles/what-s-difference-between-analog-digital-gas-sensors#:~:text=Analog%20gas%20sensors%20output%20one,or%200%2D3%20volts%20DC. (Accessed on 2-20-23).


