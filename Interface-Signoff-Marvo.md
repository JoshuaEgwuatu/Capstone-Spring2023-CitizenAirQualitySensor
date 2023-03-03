# Interface Signoff

## Subsystem Function
The interface conditions a chosen set of analog voltage and analog current output ranges coming from the sensor subsystem to be within the 0 V to 5 V or 1 V to 5 V range then outputs these conditioned signals to the microcontroller. Digital signals do not connect with the interface but instead go straight to the microcontroller.  

## Subsystem Constraints
1) Must scale the following sensor output voltage signal ranges to 0 V to 5 V: 0 V to 3 V,  0 V to 10 V,  -10 V to +10 V,  -5 V to +5 V.     
2) Must convert a sensor output current signal of 4 to 20 mA to a voltage signal of 1 to 5 V.
3) Components must be RoHS compliant to prevent health and environment risks due to electronic waste.
4) Interface must not draw any more current than the power system can provide ( 3 A ) and operate off of 5±0.25 V from the power system.

## System Schematic

![interface mark 5 schematic](https://user-images.githubusercontent.com/118490274/221126418-b5eed9c2-7cea-4c91-a7e5-c7a780e5fbaa.PNG)

## Analysis

1) Voltage Scaling
* An input voltage range 0 V to 3 V is scaled to 0-5 V through the use of an non-inverting amplifier with a gain of 5/3. The gain formula for a non-inverting op amp is 1 + (R2/R1) and if R1 is set to 3.3k then R2 needs to be 2.2k to acquire a gain of 5/3. The input voltage range is ran through the op amp which multiplies the voltage by the gain. This scales up the original range to the desired range of 0 V to 5 V. 0 V x 5/3 = 0 V and 3 V x 5/3 = 5 V now making a 0 V to 3 V signal map into 0 V to 5 V. R2 should be kept in the kiloohm range to limit current going into the op amp. With R2 being 3.3k, the current entering the op amp according to the LTSpice simulation is around 0.8 mA. which is below the op07 short circuit current of 30 mA. Even if R2 is ±5% of its' nominal value of 3.3k, current entering the op amp according to the LTSpice simulation is around 0.7 mA. which is still below the op07 short circuit current.
* Offset Voltage: Voff due to input offset is calculated with the equation (1+R2/R1) x input offset voltage. Voff due to input offset current is calculated by R2 x input offset current. According to the op07 datasheet, input offset voltage and input offset current are 75 uV max and 3.8 nA max respectively. Substituting these values into the previous equations along with our resistor values of R1 = 3300 and R2 = 2200, we get a total offset voltage of 0.125 mV which is between our acceptable offset output range of 0 mV to 20 mV. Taking into account resistor tolerances, the new range for total offset voltage is between 0.12 mV to 0.14 mV which is still within our acceptable offset range of 0 mV to 20 mV.
* Component Variations for 0 V to 3 V to 0 V to 5 V Circuit: Each resistor tolerance and voltage tolerance for the op amp power supply is ±5%. Taking this into account, a LTSpice worse cast analysis simulation was performed for for the input voltages 0 V and 3 V respictevly. When a 0 volt signal from the sensors is applied as an input to the circuit, the output voltage due to tolerances will be in the range of 925.26 mV to 926.10 mV. When a 3 V signal is applied as an input, the output range will be between 3.80 V to 4.30 V. Due to component tolerances, output voltages will not be perfectly be 0 or 5 volts. As a result, data loss of input voltage signals from the sensors through the circuit should be expected.  





![WORST CASE ANALYSIS FOR CIRCUIT 1](https://user-images.githubusercontent.com/118490274/221122771-ea940e4f-cec6-4fda-8705-ac0186986cd8.PNG)


* A 0 V to 10 V range will be scaled down to 0 V to 5 V by way of voltage division. The formula for voltage division is Vout = ( R2 x Vin ) / ( R1 + R2 ). If we set both resistor values to 10k then vout will equal half of the input voltage. (10k x 0 V) / (10k + 10k) = 0 V and (10k x 10 V) / (10k + 10k) = 5 V. The 0-10 V range is now scaled down to a 0 V to 5 V range now measurable by the arduino. Using ohm's law, 10 V / (10k + 10k),  the current going through the voltage divider is .5 mA. Using the power formula, 10 V x .5 mA, the power dissipated by each resistor is 5 mW. The chosen resistors are  ¼ W resistors so power dissipation and overheating will not become a problem. 
* Component Variations for 0 V to 10 V to 0 V to 5 V Circuit:  Each resistor tolerance is 5%. Taking this into account, a ltspice worse cast analysis simulation was performed for for the input voltages 0 V and 10 V. When a 0 volt signal from the sensors is applied as an input to the circuit, according to ltspice the output voltage with tolerances accounted for will be 0 V. When a 10 V signal is applied as an input, the output range will be between 4.80 V to 5.28 V. Due to component tolerances, the output voltage will experience small amounts of voltage loss or overvoltage by .28 V. However, the arduino megas analog pins can handle voltages at Vcc + 0.5 V rendering this potential scenario a non issue. 

![WORST CASE ANALYSIS FOR CIRCUIT 2](https://user-images.githubusercontent.com/118490274/221125591-8bcd4d9c-c7e1-4e57-bc8a-518199cc2f27.PNG)

* To accurately map our chosen negative voltage ranges, a set of equations and steps are used to pick the right resistor values for our three resistor voltage converter circuit. Step 1: Delta Vin = Sensor output range and Delta Vout =  A/D input range. Step 2: Ax = Delta Vin /  Delta Vout, Bx = Vbias / (Vout Vin/A ), and Cx = Ax * Bx / (Ax * Bx - Ax - Bx ). Step 2: RA and Vbias will be kept constant at 10k and 5 volts respectively. RA = (10K / Ax ) * Ax  = 10K. RB = (10k / Ax ) * Bx. RC = (10k / Ax ) * Cx. If input range is -10-10 V and these equations are followed, the values of resistor A,B and C would be 10k,5k, and 10k respectively to map the input range to 0 V to 5 V. If input range was -5 V to +5 V, using these equations would give us RA = 10k, RB = 10k and RC would be disconnected to map -5 V to +5 V to 0 V to 5 V. 
* Component Variations for -5 V to 5 V to 0 V to 5 V Circuit: Each resistor tolerance is 5%. Taking this into account, a ltspice worse cast analysis simulation was performed for for the input voltages 0 V and 10 V. When a -5 volt signal from the sensors is applied as an input to the circuit, the output voltage due to tolerances will be in the range of -300 mV to +260 mV. When a + 5 V signal is applied as an input, the output range will be between 4.87 V to 5.13 V. Due to component tolerances, output voltages can be -300 mV which is within the arduinos minimum voltage range of -0.5 V that an analog pin can handle or output voltage be .13 V over 5 V which is also within the arduinos max voltage range of an analog pin. As before, data loss due to these tolerances should be expetced.

![WORST CASE ANALYSIS FOR CIRCUIT 4 (5 V) ](https://user-images.githubusercontent.com/118490274/221127897-879d3b03-cf92-4f27-8b97-1831981449ca.PNG)

* Component Variations for -10 V to 10 V to 0 V to 5 V Circuit: Each resistor tolerance and voltage bias source is 5%. Taking this into account, a ltspice worse cast analysis simulation was performed for for the input voltages 0 V and 10 V. When a -10 volt signal from the sensors is applied as an input to the circuit, the output voltage due to tolerances will be in the range of -310 mV to +250 mV. When a +10 V signal is applied as an input, the output range will be between 4.84 V to 5.20 V. Due to component tolerances, output voltages can be -310 mV which is within the arduinos minimum voltage range of -0.5 V  or output voltage can be .20 V over 5 V which is also within the arduinos max voltage range.


![WORST CASE ANALYSIS FOR CIRCUIT 4 (10 V) ](https://user-images.githubusercontent.com/118490274/221128222-70fb486f-bcea-43d7-b8f9-b73ac13dd81e.PNG)

2) Current to Voltage Converter
* The current to voltage converter is a 1000 ohm resistor in parallel with a 330 ohm resistor to form a 250 ohm resistor in series with the current source input. The resistor will convert a 4 mA to 20 mA range to a 1 V to 5 V output. 4 mA * 250 ohms = 1 volt and 20 mA * 250 ohms = 5 volts. With a current of 20 mA and a produced voltage of 5 V the power dissipated would be .1 W. This is lower than our ¼ W resistor which gets rid of power dissipation concerns.
* Component Variations for 4 mA to 20 mA to 0 V to 5 V Circuit: Each resistor tolerance is 5%. Taking this into account, a ltspice worse cast analysis simulation was performed for for the input currents 4 mA to 20 mA. When a 4 mA signal from the sensors is applied as an input to the circuit, the output voltage due to tolerances will be in the range of -250 mV to +260 mV. When a 20 mA signal is applied as an input, the output range will be between 4.87 V to 5.3 V. Due to component tolerances, output voltages can be -250 mV which is within the arduinos minimum voltage range or output voltage can be .30 V over 5 V which is still within the max voltage range.

  
3) RoHS Compliance
* The chosen resistors and OP07 op amp have been found on Digikey and are listed as RoHS compliant.  

4) 
* As shown in the schematic, the only  two circuits in the interface that need power are the op amp the three resistor circuit which are both supplied 5 V from the power system. The op amp power consumption with a 5 volt power supply is about 50 mW. Taking the 5 volt power supply and dividing by the 50 mW power draw of the op07 you get a current draw of 10 mA. The only other circuit that draws power in the interface is the negative voltage to 0 V to 5 V converter, perfoming nodal analysis on said circuit comes out to about 1 mA. Therfore total current draw of the interface is about 11 mA. 

## BOM

| Designator   | Manufacturer                       | Manufactured Part #     | Description                         | Quantity    | Price       |
|------------- |----------------------------------- |-------------------------|-------------------------------------|-------------|-------------|
| P1           | Stackpole Electronics Inc          |CF14JT10K0               | RES 10K OHM 5% 1/4W                 | 2           | $0.00729    |
| P2           | Stackpole Electronics Inc          |RNF14BTE5K00             | RES 5K OHM 0.1% 1/4W                | 1           | $0.13965    |
| P3           | Lumimax Optoelectronic Technology  | CF1/4W3K3JTB            | RES 3.3K OHM 5% 1/4W                | 1           | $0.01144    |
| P4           | Stackpole Electronics Inc          | CF14JT2K20              | RES 2.2K OHM 5% 1/4W                | 1           | $0.1        |
| P5           | Stackpole Electronics Inc          | CF14JT1K00              | RES 1K OHM 5% 1/4W                  | 1           | $0.1        |
| P6           | Stackpole Electronics Inc          | CF14JT330R              | RES 330 OHM 5% 1/4W                 | 1           | $0.1        |
| P7           | Stackpole Electronics Inc          | CF14JT20K0              | RES 20K OHM 5% 1/4W                 | 2           | $0.10000    |        
| P8           | 	Analog Devices Inc.               | OP07CSZ-REEL            | IC OPAMP GP 1 CIRCUIT 8SOIC         | 1           | $2.31000    |



## References
1) R. C. Dorf and J. A. Svoboda, Introduction to Electric Circuits, 9th Edition, John Wiley & Sons, Inc., 2014   
2) Wyss, K. Scaling and Biasing Analog Signals, Symmetric Research, 24 Nov. 2007, http://edge.rit.edu/edge/P17105/public/Final%20Documents/pihat/docs/raspi_zero_power_sensor_hat/app_notes/resistor_biasing.pdf.  
3) “OP07 Datasheet by Analog Devices Inc..” Digi, https://www.digikey.com/en/htmldatasheets/production/53383/0/0/1/op07.html. 
