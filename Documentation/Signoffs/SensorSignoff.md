# Sensor Subsystem Signoff
## FUNCTION OF THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The Sensor Subsystem will be designed to give various data to the Microcontroller Subsystem through the Interface Subsystem. As data acquisition starts, the output of each analog sensor goes through the Interface for voltage/current regulation to the microcontroller.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Within this Sensor Subsystem, the design team has decided to get multiple types of sensors for the modularity of the device. These types are digital, analog voltage, and analog current sensors. While the digital sensors send bits describing the measurement of a specific parameter, the analog sensors send their signals a bit differently. Analog sensors output analog signals which are different to measure from bits, therefore the Interface Subsystem will provide assistance in parameter conversion to the microcontroller.

## CONSTRAINTS ON THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Constraints on the subsystem are as follows:

1. The pollutants of the Air Quality Device shall be able to detect carbon dioxide, methane, nitrogen dioxide, ozone, particulate matter, and sulfur dioxide. These sensors should work independently from each other.

Each sensor shall meet the requirmentds of either Constraint 2 or 3.

2. Shall be modular. Specifically, the change of sensors should be seamless and handled by the board and software. The sensors will have a variety of Input/Output (I/O) ports. For a sensor to be in the same group, it must share the same voltage supply, current consumption, and communication technique through the interface. The sensor shall meet either of the following output ranges [9]:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● Output the signal at the range of 0 - 10 VDC for analog voltage.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● Output 4 - 20 mA for analog current.

3. Each sensor must be able to communicate with the microcontroller using a communicative language. The sensors shall communicate through Serial Peripheral Interface (SPI), Universal Asynchronous Receiver-Transmitter (UART), or Inter-Integrated Circuit (I2C). The microcontroller for this design will also be able to communicate with those same data transfer techniques. 

4. For windy environments, the sampling rate should be at most 10 Hz. This is because there are environmental factors that can cause a loss of accuracy in the data given higher wind speeds or non preferable weather conditions. After viewing this experiment of wind analysis in Thailand, it can be shown that using the Nyquist sampling theorem and varied wind speed, one can find the appropriate sampling rate at higher wind speed conditions without losing as much accuracy. They observed the wind speed data and used Fourier Transform to locate a cutoff frequency for the Nyquist sample rate. From their calculations, they have also concluded 10 Hz to be a suitable sample rate for higher wind conditions [1]. For indoor monitoring, ambient gas sensors will be sampled at the lowest rate of 2 Hz per second based on the diffusion of ambient air quality [3].

5. The input voltages from the Power Subsystem will provide either 3 or 5 +/- 0.1 V DC. Therefore, each sensor that will be used for the device shall have input voltages of either value. From looking at multiple gas sensors for this project, the maximum worst case for wattage in this subsystem is 375 mW. Maximum current consumption for each sensor is 75 mA.

6. For every sensor that is plugged onto the Air Quality Device initially, there may be a start up time for initial calibration. According to a study in Tokyo, most portable gas sensors have a start-up time of 30s [10]. After a survey observing the full start-up time range, the sensors selected within the analysis section have a max time of 1 hour. Therefore, all sensors shall have a wait/warm-up time less than 2 hours before data acquisition.

7. According to the ANSI/ASHRAE Standard 62.1-2016: Ventilation for Acceptable Indoor Air Quality [2], indoor CO2 concentrations no greater than 700 parts per million (ppm) above outdoor CO2 concentrations will satisfy a substantial majority (about 80%) of occupants. Sensors used for this device shall comply with their pollutant concentration with this standard for indoor/outdoor use. The NAAQS has revised measurement standards for the main pollutants in America. Resolution for each analog sensor must be at most 0.15 ppm or less, and for digital sensors, a max resolution of 0.1 ppm or less shall be used. The ranges are as follows [14]:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● PM 10 - 150 - 350 μg/m3 (micrograms per cubic meter of air.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● PM 2.5 - From 12 - 200 μg/m3.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● NO2 - From 53 - 100 ppb (parts per billion).

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● O3 - From 0.07 - 0.115 ppm.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● SO2 - From 0.5 - 2 ppm.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ● CH4 (Methane) - From 2 - 90 ppm [15].

## BUILDABLES OF THE SUBSYSTEM

![CAPSTONE II Sensor Subsystem](https://user-images.githubusercontent.com/118767661/221063057-85074e1f-1613-4238-9c89-70a61df53dee.png)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 1. Sensor Subsystem through Interface Schematic

![Screenshot (229)](https://user-images.githubusercontent.com/118767661/220430812-1e9725cd-139a-45dc-94f5-ec22bebd58c4.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 2. Sample code for the MIKROE-2767

![Screenshot (231)](https://user-images.githubusercontent.com/118767661/220431271-221e77c1-a7d6-4de3-9dff-db658f13ef42.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Figure 3. Sample Code for the A02P43B7001

## ANALYSIS OF THE SUBSYSTEM

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The team has chosen 3 sensors for testing that matches with the constraints list. We wanted each to be a different type of sensor output to test modularity and implement the necessary actions required within the software to model the functionality of both the Microcontroller, Interface, and Sensor Subsystems. All sensors chosen for experimentation are for detecting one of the 6 pollutants that the proposal has stated for data input.

### OZONE SENSOR (ANALOG VOLTAGE)

#### Analysis of the MIKROE-2767 [4]:

1.& 7.-The MIKROE-2767 Ozone (O3) Gas Sensor is a quarter-sized PCB mounted with a MQ131 detector that has high sensitivity depending on the potentiometer. This sensor is able to detect the pollutant anywhere from 10‐1000 Part-Per-Million (ppm).

3.-The MIKROE-2767 is able to communicate with the microcontroller using SPI and UART. Thus, the sensor will be able to send data for the user to store.

2.& 5.-The MIKROE-2767 has an input voltage range of 3.3V - 5V therefore, this particular sensor can be powered by both voltage supply options. Based on the Schematic (Schematic Reference!), the current computation is in the range of 5 uA - 33 uA.

●	The UART source code can be seen in the Buildables of the Subsystem section within the document. (See Figure 2.)

### SULFUR DIOXIDE SENSOR (ANALOG CURRENT)

#### Analysis of the ULPSM-IAQ 968-008 [6] with the A02P43B7001 [5]:

1.-The A02P43B7001 gas detector is able to detect Sulfur Dioxide (SO2) which is within the list of pollutants to be acquired.

2.-The ULPSM-IAQ 968-008 below the detector contains a nice feature of having the ability to switch the gas detectors for other pollutants as well. This can allow the user to replace the SO2 sensor with another pollutant detector, or a different type of gas detector for more convenience and modularity.

3.-The SO2 gas detector can also communicate with the microcontroller using UART for data transfer.

5.-The ULPSM-IAQ 968-008 will be connected using header pins under the A02P43B7001, which will communicate with the Microcontroller. The ULPSM-IAQ 968-008 calls for a supply voltage of around 3.3V. The power consumption is on average 30 uW. Also, the corresponding current consumption is 10uA on average.

5.-The A02P43B7001 will operate at the same voltage supply of 3.3V with an LED indicator telling the user that the sensor is operating in the ON position. During this time, the SO2 sensor has a max operating current of 1.17 mA and a max power consumption of 3.7 mW.

7.-The analog current detector has a measurement range of 0 - 5 ppm. Having a wide range will give the user a range of accuracy and levels of precise calculations.

●	A method sample code for the SO2 detector to communicate with the Master device can be seen within the Buildables of the Subsystem section. (See Figure 3.)

### CARBON DIOXIDE SENSOR (DIGITAL)

#### Analysis of the DGS-CO 968-034 [7]:

1.& 2.-The DGS-CO is a digital carbon monoxide detector that has a similar modular feature as the analog current gas sensor. This means we can switch detectors for experimentation on whether the components meet our specifications.

3.-The connections are configured by the PCB to communicate using UART as well.

5.-The supply voltage is available for a 3.3V supply with a power gumption range of 0.15 - 12 mW. The current consumption also has a range of 0.05 mA - 4 mA. Values for the power, voltage, and current requirements depend on the operating periodic functions of this device.

7.-This Digital sensor has a range of 0 -1,000 ppm.

### METHANE SENSOR (ANALOG VOLTAGE)

#### Analysis of the MIKROE-1628 [11]:

1.-The MIKROE-1628 is able to detect methane within its location.

2.& 3. 5.-It can be supplied with a max voltage of 5V, a max current consumption of 33 uA, outputting at a range of 0 - 5 V using SPI or UART.

4.& 6.-After a warm up time of 1 hour, it can start sampling at a rate of 2Hz.

7.-Has a measurement rage of 200 - 10000 ppm.

### NITROGEN DIOXIDE SENSOR (DIGITAL)

#### Analysis of the SEN0377 [12]:

1.-The SEN0377 can detect various type of gasses, but for this device it shall be used to detect NO2.

2.& 5.-This sensor has the modular compatibility to take either 3.3 or 5 V supply with a low current consumption of 11 mA. Thus having a lower power intake of .45 W. Digital output of 0 - 3 V.

3.-The sensor shall communicate using I2C for the microcontroller.

4.& 6.-Start up time is less than 1 hour with a sample rate of 5 Hz.

7.-Measurement range of 0.05 - 10 ppm.

### PARTICULATE MATTER SENSOR (DIGITAL)

#### Analysis of the SPS30 [13]:

1.-This Particulate Matter (PM) Sensor can detect 4 different sizes of PM in its location.

2.& 5.-Supply voltage is 5V with max current intake of 75 mA. Outputs current of 0 - 16 mA.

3.-Uses both I2C and UART to communicate.

4.-Samples at a period of 1 second or 2 Hz.

6.-Start up time ranges from 8 - 30 seconds.

7.-Can calibrate up to ranges of 200 - 3000 ppm.

### GPS SENSOR (DIGITAL)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Another sensor to be applied in the project is used for GPS location. The RAK1910 [8] can do this task while also corresponding to the constraints provided.

2.& 5.-The RAK1910 can take 3.3V with low amperage consumption. The worst case being 22 mA.

3.-The GPS sensor can communicate using UART or I2C, being compatible with the microcontroller in use.

6.-30 second cold start-up time.

## BILL OF MATERIALS

|Item Name|Manufactured Part #|Quantity|Description|Price|
|----------|-------------------|--------|-----------|-----|
|OZONE 2 CLICK|MIKROE-2767|0|Analog Voltage O3 Gas Sensor|$45.00|
|Analog Gas Sensor Module|ULPSM-IAQ 968-008|1|Analog Current Gas Sensor (Modular with Digital Sesnor)|$50.00|
|Allsensing gas sensor module|A02P43B7001|1|SO2 GAS SENSOR|$163.62|
|WisBlock GNSS Location Module|RAK1910|0|Tracks the GPS and the GLONASS signals|$17.00|
|Digital Gas Sensor Module|DGS-CO 968-034|0|Digital Gas Sesnor (Modular with Analog Current Sensor) if out of stock, 968-001 is similar option.|$50.00|
|Methane Click|MIKROE-1628|1|Multiple Function Sensor|$15.00|
|Digital Sensor Module|SEN0377|1|Multiple Function Gas Sensor|$39.90|
|Particulate Matter Sensor|SPS30|0|Particulate Matter Sensor for Air Quality Monitoring and Control|$50.50|

Note: All sensors that our team does not plan to order will have the quantity order number of 0 within the BOM. Corresponding sensors that have the quantity number of 0 will be ordered at a later date separate from the initial build.

## REFERENCES

1. “Improving Accuracy of Wind Analysis with Multiple Sampling Rates of Wind Measurement” https://www.e3s-conferences.org/articles/e3sconf/pdf/2019/21/e3sconf_icpeme2018_02002.pdf (Accessed on 3-1-23).

2. The National Institute for Occupational Safety and Health (NIOSH) “Indoor Environmental Quality” https://www.cdc.gov/niosh/topics/indoorenv/hvac.html (Accessed on 2-16-23).

3. Lion Precision “Displacement Resolution Specifications and Its Effects on Performance” https://www.lionprecision.com/understanding-sensor-resolution-specifications-and-effects-on-performance/ (Accessed on 2-23-23).

4. MIKROE-2767 Datasheet “Ozone 2 click” https://media.digikey.com/pdf/Data%20Sheets/MikroElektronika%20PDFs/MIKROE-2767_Web.pdf (Accessed on 2-13-23).

5. A02P43B7001 Datasheet https://media.digikey.com/pdf/Data%20Sheets/Allsensing%20PDFs/AGSM-SO2-5.pdf (Accessed on 2-16-23).

6. ULPSM-IAQ 968-008 Datasheet “Ultra-Low Power Analog Sensor Module for IAQ” https://www.spec-sensors.com/wp-content/uploads/2016/10/ULPSM-IAQ-968-008.pdf (Accessed on 2-16-23).

7. DGS-CO 968-034 Datasheet “Digital Gas Sensor – Carbon Monoxide” https://www.spec-sensors.com/wp-content/uploads/2017/01/DGS-CO-968-034.pdf (Accessed on 2-16-23).

8. RAK1910 WisBlock GNSS Location Module Datasheet https://docs.rakwireless.com/Product-Categories/WisBlock/RAK1910/Datasheet/#overview (Accessed on 2-17-23).

9. GasLab “Analog and Digital Gas Sensors: What’s the Difference?” https://gaslab.com/blogs/articles/what-s-difference-between-analog-digital-gas-sensors#:~:text=Analog%20gas%20sensors%20output%20one,or%200%2D3%20volts%20DC. (Accessed on 2-20-23).

10. Stable Heating Technology for Catalytic Combustion Hydrogen Gas Sensor Using Quartz Resonators https://pdfs.semanticscholar.org/7a13/0c740245fd18929fdc9169a5f38154c9cf0e.pdf (Accessed on 2-23-23).

11. MIKROE-1628 Datasheet https://www.mouser.com/datasheet/2/272/methane-click-manual-v100-1483826.pdf (Accessed on 2-23-23).

12. SEN0377 Datasheet https://www.mouser.com/pdfDocs/ProductOverview-DFRobot-SEN0377.pdf (Accessed on 2-23-23).

13. SPS30 Datasheet https://cdn.sparkfun.com/assets/4/e/e/f/8/Sensirion_PM_Sensors_Datasheet_SPS30.pdf (Accessed on 2-23-23).

14. United States Environmental Protection Agency “NAAQS Table” https://www.epa.gov/criteria-air-pollutants/naaqs-table (Accessed on 2-26-23).

15. “A Portable Device for Methane Measurement Using a Low-Cost Semiconductor Sensor: Development, Calibration and Environmental Applications” https://www.mdpi.com/1424-8220/21/22/7456#:~:text=This%20sensor%20can%20perform%20temperature,RH%20and%20resolution%20of%200.01%25 (Accessed on 2-26-23).
