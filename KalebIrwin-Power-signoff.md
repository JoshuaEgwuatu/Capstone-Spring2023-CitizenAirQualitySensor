## Function of the subsystem 
The subsystem will provide the microcontroller and sensor interface with power. There will be two configurations designed which the user will be able to choose from. The first configuration will be designed to operate with input from an ac mains electrical outlet and the second configuration will be powered by a battery that is charged by a solar cell.

## Constraints 
1. Provide a maximum power draw of 2.725 W and 0.8475 W typical 
   
   a. Arduino Mega maximum power is 2.5 W [Ardunio Power Tree] with 0.375 W typical power requirements taken from 5 V 75 mA typical operation [diyiot]
   
   b. Typical power draw for communications is 0.2475 W taken from 3.3 V 70 mA typical operation [diyiot]. Maximum power is not affected by the communication system as it is included in the maximum power of the Mega based on the ardunio power tree [].
   
   c. 225mW for three high current draw sensors simultaneously
2. Operate for a minimum time span of 48 hours 
3. Power the Ardunio Mega with 7-12 V on the Vin pin or 5 V through the USB input on the board [ardunio documentation]
4. *Provide 5 V and 3 V for sensor interface

Additional constraint on system for AC operation

   5. Function on 120 V 60 Hz AC mains input

Additional constraints on system for battery operation

  6. Battery capacity greater than 40.68 Wh 
   
      Calculated with (typical power draw*minimum continuous operation time = (0.8475 W * 48 h) = 40.68 Wh 
   
   7. Must make use of a solar panel to extend the operational time without maintenance 

## Schematic 
<img width="866" alt="BuildableAC" src="https://user-images.githubusercontent.com/118766525/216235986-c4a7bbef-dcb8-4c07-8018-090d6612bf4e.png">
<img width="627" alt="BuildableDC" src="https://user-images.githubusercontent.com/118766525/216236032-495901d5-41aa-42f0-b8a0-075caf56226f.png">

## Analysis 
Analysis for system on AC operation 
 1. The chosen wall adapter is rated at 5 V and 2.1 A. Multiplying these numbers yields 10.2 W which is greater than the worst case power draw of 1.96 W  
 2.  
 3. The chosen wall adapter can output 5 V and excceds the 500 mA constraint and the included USB-A to USB-B cable will plug from the wall brick to the USB input of the Ardunio Mega
 4. 5 V can be taken directly from the USB-A to the screw terminal and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3 V.
   a. The chosen DC-DC converter requires an input voltage at least 1.5V higher than the output voltage and can input 4-40V and output 1.5-35V. These ranges allow for a 5V input and a 3V output.
 5. The chosen wall adapter is rated for 100V-240V 50/60Hz AC which covers the US electrical system 
 
Analysis for system using a battery 
 1. The chosen battery has USB output of 5 V and 3 A. Multiplying these numbers yields 15 W which is greater than the worst case power draw of 2.725 W
 2.
 3. The chosen battery can provide 5 V and 3 A which exceeeds the 500 mA constraint via USB
 4. 5 V can be taken directly from the USB-A to the screw terminal and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3 V.
 6. Stated capacity is 125 Wh which is greater than the required 40.68 Wh 
   a. Obtained by multipling the battery voltage by the stated capacity in mAh (5 V * 25000 mAh = 125 Wh)
 7. Built in solar cell provides 6 W during peak sun hours, gaining (6-0.8475 W)*4.5 h = 23.186 Wh given 4.5 hours of peak sun

## BOM
| Designator | Manufacturer | Manufactured Part # | Description                                                                     | Quanitity | Price Each |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------------------------- | --------- | ---------- |
| P1         | Hiluckey     |                     | Solar Charger 25000mAh                                                          | 1         | $46.99     |
| P2         | ALMOCN       | LM2596S             | DC-DC Adjustable Step-Down Module with Digital Display Voltmeter Display 2 pack | 1         | $8.99    |
| P3         | HopePow      |                     | 5V 2.1A wall charger 3 pack                                                     | 1         | $10.99      |
| P4         | JUXINICE     |                     | Male USB to screw terminal connector 2 pack                                     | 1         | $8.99     |
## Notes 
*Additional constraint placed on power subsystem if the chosen sensors exceed the Arduino Mega 50 mA current limit 

**If the chosen sensors do not exceed the current limitation of 50mA per pin of the Arduino Mega Rev 3, and AC operation is chosen, a standard USB wall wart may be connected directly to the board instead of the screw terminal connections 
## Reference 
tbi

have the refrences just not formated and ordered 
