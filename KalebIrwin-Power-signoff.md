## Function of the subsystem 
The subsystem will provide the microcontroller and sensor interface with power. There will be two configurations designed. The first configuration will be designed to operate with input from an electrical outlet and the second configuration will be powered by a battery.

## Constraints 
1. Provide 1.96W of power 
   a. *1.75W to Arduino Mega 
   b. 210mW for three high current draw sensors simultaneously

Constraints on system for AC operation

2. Function on 120V 60Hz AC input
3. Power the Arduino Mega with 5V USB input
4. **Provide 5V and 3V DC for sensor interface 

Constraints on system for battery operation

5. Power the Arduino Mega with 7-12V or 5V through the USB connector 
6. **Provide 5V and 3V for sensor interface 
7. Battery capacity greater than 18.816 Ah 
   Calculated with (maximum power draw*minimum continuous operation time)/battery voltage =(1.96W * 48h)/ 5V = 18.816 Ah  
8. Must make use of a solar panel to extend the operational time without maintenance 

## Schematic 
<img width="866" alt="BuildableAC" src="https://user-images.githubusercontent.com/118766525/216235986-c4a7bbef-dcb8-4c07-8018-090d6612bf4e.png">
<img width="627" alt="BuildableDC" src="https://user-images.githubusercontent.com/118766525/216236032-495901d5-41aa-42f0-b8a0-075caf56226f.png">

## Analysis 
Analysis for system on AC operation 
 1. The chosen wall adapter is rated at 5V and 2.1A. Multiplying these numbers yields 10.2W which is greater than the worst case power draw of 1.96W 
 2. The chosen wall adapter is rated for 100V-240V 50/60Hz AC which covers the US electrical system  
 3. A USB-A to USB-A cable will plug directly into the power brick and the Arduino Mega 
 4. 5V can be taken directly from the USB-A to the screw terminal and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3V.
Analysis for system using a battery 
 1. The chosen battery has USB output of 5V and 3A. Multiplying these numbers yields 15W which is greater than the worst case power draw of 1.96W
 5. The chosen battery can provide 5V via USB.
 6. 5V can be taken directly from the USB-A to the screw terminal and sent to the interface. It can also be connected to the input terminal on the DC-DC converter to provide the 3V.
 7. Stated capacity is 25000 mAh which is greater than 18.816 Ah 
 8. Built in solar cell provides 6W during peak sun hours, gaining (6-1.96)*4.5h=18.18 Wh given 4.5 hours of peak sun

## BOM
| Designator | Manufacturer | Manufactured Part # | Description                                                                     | Quanitity | Price Each |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------------------------- | --------- | ---------- |
| P1         | Hiluckey     |                     | Solar Charger 25000mAh                                                          | 1         | $46.99     |
| P2         | ALMOCN       | LM2596S             | DC-DC Adjustable Step-Down Module with Digital Display Voltmeter Display 2 pack | 1         | $8.99    |
| P3         | HopePow      |                     | 5V 2.1A wall charger 3 pack                                                     | 1         | $10.99      |
| P4         | JUXINICE     |                     | Male USB to screw terminal connector 2 pack                                     | 1         | $8.99     |
