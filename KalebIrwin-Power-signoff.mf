Function of the subsystem 
The power subsystem will provide the necessary energy for the components to operate. 

Constraints 
Output three voltages 
12V to power the chosen microcontroller 
5V and 3V to power common sensors
Runs continuously with minimal user interaction 
Designed modularly
Operate with AC input 
Operate with a battery charged by a solar panel
Provide ~485mW to microcontroller ~240mW + ~35mW for the communication and 210mW for three high current draw sensors simultaneously  
Battery capacity should allow no less than 24 hours of operation from a full charge 
(~485mW*24h)/12V= ~970mAH 

Schematic 


Analysis 
For design 1, the 12V needed to supply the microcontroller can be taken directly from the wall converter (P3) 
For design 2, the 14.8V will be taken from the battery (P1). This is within the input voltage range for the microcontroller (6-20V) and the DC-DC converters ()
5V and 3V needed for the sensors will come from each DC-DC module (P2) for both modes of operation.
For design 1, the wall adapter (P3) will provide continuous power
For design 2, the chosen battery(P1) has 1.34x the calculated capacity for 24 hours of operation and should allow for almost a day and a half of operation at maximum potential current draw from full charge ignoring any added power from the solar cell (P4)
Design 1 will use the wall adapter (P3) directly into the microcontroller and the DC converters (P2) in order to operate with AC input 
Design 2 will connect the solar cell (P4) to the battery (P1) and the battery to the microcontroller and the DC converters 
485mW/12V=40.4mA 
This falls well below the maximum current draw of both the wall plug (1A) and the battery 
The chosen battery (P1) has 1.34 times the calculated capacity needed for the constraint to be met.
Battery (P1) capacity is 1300mAh 	Calculated need= 970mAh
1300/970=1.34 
