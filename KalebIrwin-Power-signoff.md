## Function of the subsystem 
The subsystem will provide the microcontroller and sensor interface with power. There will be two configurations designed which the user will be able to choose from. The first configuration will be designed to operate with input from an ac mains electrical outlet and the second configuration will be powered by a battery that is charged by a solar cell.

## Constraints 
1. *Provide a maximum power draw of 1.686 W and 0.831 W typical 
   
   a. Arduino Mega maximum power is 0.9 W taken from 5 V operation at 180 mA peak current draw [diyiot] with 0.375 W typical power requirements taken from 5 V 75 mA typical operation [diyiot]
   
   b. ESP8266 maximum power draw is 0.561 W taken from 170 mA maximum required current at 3.3 V operation [esp8266 datasheet]
   Typical power draw for ESP8266 is 0.231 W taken from 3.3 V 70 mA typical operation [diyiot]
   
   c. 225mW for three high current draw sensors simultaneously
2. Power the Ardunio Mega with 7-12 V on the Vin pin or 5±0.25 V through the USB input on the board [ardunio documentation][USB Spec rev 2]
3. **Provide 5 V and 3 V for sensor interface

Additional constraint on system for AC operation

 4. Function on 120 V 60 Hz AC mains input

Additional constraints on system for battery operation

5. Operate for a minimum time span of 48 hours 

6. Battery capacity greater than 39.888 Wh 
   
      Calculated with (typical power draw*minimum continuous operation time = (0.831 W * 48 h) = 39.888 Wh 
   
 7. Must make use of a solar panel to extend the operational time without maintenance 

## Schematic 
<img width="866" alt="BuildableAC" src="https://user-images.githubusercontent.com/118766525/216235986-c4a7bbef-dcb8-4c07-8018-090d6612bf4e.png">
<img width="627" alt="BuildableDC" src="https://user-images.githubusercontent.com/118766525/216236032-495901d5-41aa-42f0-b8a0-075caf56226f.png">

## Analysis 
1. The chosen wall adapter is rated at 5V and 2.1A. Multiplying these numbers yields 10.2W. The chosen battery has USB output of 5V and 3A. Multiplying these numbers yields 15W both of which are greater than the worst case power draw of 1.686W
2. Both solutions provide 5 V usb output that can power the arduino 
3. 5V can be taken directly from the USB-A to the screw terminal on either power option and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3V.
   
   a. The chosen DC-DC converter requires an input voltage at least 1.5V higher than the output voltage and can input 4-40V and output 1.5-35V. These ranges allow for a 5V input and a 3V output.

4. The chosen wall adapter is rated for 100V-240V 50/60Hz AC which covers the US electrical system 
5. Chosen battery has a stated capacity of 25000 mA or 125 Wh at 5 V. Using this and the typical power draw of 0.831 W tells us that it will run for 150.42 hours on a single charge with no additional power from the solar cell. This is 3.13x the minimum operation time. 
6. Battery capacity is stated at 25000 mA or 125 Wh at 5 V. This is greater than the calculated minimum of 39.888 Wh 
7. Built in solar cell provides 6W during peak sun hours
Gaining 6 W*4.5 h = 27 Wh given 4.5 hours of peak sun

## BOM
| Designator | Manufacturer | Manufactured Part # | Description                                                                     | Quanitity | Price Each |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------------------------- | --------- | ---------- |
| P1         | Hiluckey     |                     | Solar Charger 25000mAh                                                          | 1         | $46.99     |
| P2         | ALMOCN       | LM2596S             | DC-DC Adjustable Step-Down Module with Digital Display Voltmeter Display 2 pack | 1         | $8.99    |
| P3         | HopePow      |                     | 5V 2.1A wall charger 3 pack                                                     | 1         | $10.99      |
| P4         | JUXINICE     |                     | Male USB to screw terminal connector 2 pack                                     | 1         | $8.99     |
## Notes 
*Maximum and typical power calculations done with no low power modes or code taken into account. For actual operation these values can be lowered substainually and should be considered to lower the load on the battery. For this project we will attempt to include as many options as possible and provide data on power consumption with and without these features.

**Additional constraint placed on power subsystem if the chosen sensors exceed the Arduino Mega 50 mA current limit. 
***
## Reference 
tbi

have the refrences just not formated and ordered 
