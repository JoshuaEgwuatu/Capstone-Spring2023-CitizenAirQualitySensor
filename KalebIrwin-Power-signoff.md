## Function of the subsystem 
The subsystem will provide the microcontroller and sensor interface with power. There will be two configurations designed which the user will be able to choose from. The first configuration will be designed to operate with input from an ac mains electrical outlet and the second configuration will be powered by a battery that is charged by a solar cell.

## Constraints 
1. *Provide a maximum power draw of 1.686 W and 0.831 W typical 
   
   a. Arduino Mega maximum power is 0.9 W taken from 5 V operation at 180 mA peak current draw with 0.375 W typical power requirements taken from 5 V 75 mA typical operation [1]
   
   b. ESP8266 maximum power draw is 0.561 W taken from 170 mA maximum required current at 3.3 V operation [2]
   Typical power draw for ESP8266 is 0.231 W taken from 3.3 V 70 mA typical operation [3]
   
   c. 225 mW for three high current draw sensors simultaneously 
2. Power the Ardunio Mega with 7-12 V 160 mA on the Vin pin or 5±0.25 V 200mA from the USB 2.0 standard through the USB 2.0 input on the board [4][5]
3. **Provide 5 V and 3 V for sensor interface

Additional constraint on system for AC operation

 4. Function on 120 V 60 Hz AC mains input and must have UL certification 

Additional constraints on system for battery operation

5. Battery capacity greater than 39.89 Wh to allow for a minimum operational time of 48 hours on a single charge without additional power from a solar cell 
   
      Calculated with (typical power draw * minimum continuous operation time) = (0.831 W * 48 h) = 39.89 Wh 
   
 6. Must use a solar panel that is at least 4.43 W in order to recharge the batteries daily power consumption within the optimal solar charging timeframe of 4.5 hours [6]. 
 
      Calculated with (typical daily power usage / average hours of direct sun) = (19.94 Wh / 4.5 h) = 4.43 W

## Schematic 
<img width="1040" alt="Screen Shot 2023-02-17 at 10 37 43 AM" src="https://user-images.githubusercontent.com/118766525/219712171-392a585f-9603-4d4d-93a5-71a3d57acb4f.png">
<img width="1020" alt="Screen Shot 2023-02-17 at 3 13 57 PM" src="https://user-images.githubusercontent.com/118766525/219794582-51e36cb9-bd46-4767-8d8f-dcb19e173199.png">

## Analysis 
1. The chosen wall adapter is rated at 5 V and 2 A. Multiplying these numbers yields 10 W. The chosen battery has USB output of 5 V and 3 A. Multiplying these numbers yields 15 W both of which are greater than the worst case power draw of 1.686 W
2. Both solutions provide 5 V USB output that can power the Arduino 
3. 5V can be taken directly from the USB-A to the screw terminal on either power option and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3 V.
   
   a. The chosen DC-DC converter requires an input voltage at least 1.5 V higher than the output voltage and can input 4-40 V and output 1.5-35 V. These ranges allow for a 5 V input and a 3 V output.

4. The chosen wall adapter is rated for 100-240 V 50/60 Hz AC which covers the US electrical system and shows UL certification.
5. The chosen battery has a stated capacity of 25000 mAh and uses an internal battery voltage of 3.7 V for a power capacity of 92.5 Wh. Using this and the typical power draw of 0.831 W tells us that it will run for 111.31 hours on a single charge with no additional power from the solar cell. This is 2.319x the minimum operation time. 
6. Built in solar cell provides can provide 6 W during peak sun hours

   Gaining 6 W * 4.5 h = 27 Wh given 4.5 hours of peak sun which is greater than the 19.988 Wh daily usage.

## BOM
| Designator | Manufacturer | Manufactured Part # | Description                                                                     | Quanitity | Price Each |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------------------------- | --------- | ---------- |
| P1         | Hiluckey     |                     | Solar Charger 25000 mAh                                                          | 1         | $46.99     |
| P2         | ALMOCN       |              | DC-DC Adjustable Step-Down Module with Digital Display Voltmeter Display 2 pack | 1         | $8.99    |
| P3         | Fonken      |                     | 5 V 2 A wall charger 3 pack                                                     | 1         | $11.99      |
| P4         | Itramax     |                     | USB male to two female adapter                                                      | 1         | $12.99      |
| P5         | JUXINICE     |                     | Male USB to screw terminal connector 2 pack                                     | 1         | $8.99  
| ***        | SANKABA      | 000010              | 5 W USB Solar Panel for DC 5V Security Camera.                                   | 0         | $23.99 
## Notes 
*Maximum and typical power calculations done with no low power modes or code taken into account. For actual operation these values can be lowered substainually and should be considered to lower the load on the battery. For this project we will attempt to include as many options as possible and provide data on power consumption with and without these features.

**Additional constraint placed on power subsystem if the chosen sensors exceed the Arduino Mega 50 mA current limit. If the sensors do not exceed the current limitations of the Arduino Mega and its' pins, the DC-DC converters may be ommited from the design as the sensors can use the 3.3 V and 5 V supplies on the board. 

***An additioanl solar cell can be purchased in the event that the solution presented is not suffecent for a users area. This additional panel must have micro-USB output as it will need to be pluged into the power in port of the battery.  
## Reference 
1. C. David, “Arduino mega tutorial [pinout],” DIYI0T, 07-May-2021. [Online]. Available: https://diyi0t.com/arduino-mega-tutorial/. [Accessed: 07-Feb-2023]. 
2. “ESP8266EX datasheet - espressif,” ESP8266 Datasheet. [Online]. Available: https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf. [Accessed: 08-Feb-2023]. 
3. C. David, “How to reduce the ESP8266 power consumption?,” DIYI0T, 07-May-2021. [Online]. Available: https://diyi0t.com/how-to-reduce-the-esp8266-power-consumption/. [Accessed: 07-Feb-2023]. 
4. T. A. Team, “MEGA 2560 REV3: Arduino documentation,” Arduino Documentation | Arduino Documentation. [Online]. Available: https://docs.arduino.cc/hardware/mega-2560. [Accessed: 07-Feb-2023]. 
5. USB-IF,“USB 2.0 specification,” USB, 08-Oct-2021. [Online]. Available: https://www.usb.org/document-library/usb-20-specification. [Accessed: 07-Feb-2023]. 
6. Unbound Solar , “Sun hours map: How many sun hours do you get?,” 09-Mar-2021. [Online]. Available: https://unboundsolar.com/solar-information/sun-hours-us-map. [Accessed: 08-Feb-2023]. 
