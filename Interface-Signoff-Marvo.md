# Interface Signoff

## Subsystem Function
The interface conditions a chosen set of analog voltage, analog current and digital signal output ranges to be within the 0-5 volt range then transmits the data to the microcontroller. 
## Subsystem Constraints
1) Must scale the following voltage ranges to 0-5 V: 0-3 V, 0-10 V   
2) Must convert the following current range to 0-5 V: 4-20 mA 
3) Resistors must be RoHS compliant.

## System Schematic

![interface mark 4 schematic](https://user-images.githubusercontent.com/118490274/220842539-eee8c190-cef5-4922-8b62-e53048e0ebf4.PNG)

## Analysis

1) Voltage Scaling
* An input voltage range 0-3 V is scaled to 0-5 V through the use of an non-inverting amplifier with a gain of 5/3. The gain formula for a non-inverting op amp is 1 + R2/R1 and if R1 is set to 3.3k then R2 needs to be 2.2k to acquire a gain of 5/3.The input voltage range is ran through the op amp and multiplied by the gain to scale up to the needed range of 0-5 V. 0 x 5/3 = 0 V and 3 x 5/3 = 5 V now making the 0-3 V range map into 0-5 V.
* A 0-10 V range will be scaled down to 0-5 V by way of voltage division. The formula for voltage division is Vout = ( R2 x Vin ) / ( R1 + R2 ). If we set both resistor values to 10k then vout will equal half of the input voltage. (10k x 0 V) / (10k + 10k) = 0 V and (10k x 10 V) / (10k + 10k) = 5 V. The 0-10 V range is now scaled down to a 0-5 V range now measurable by the arduino. Using ohm's law, 10 V / (10k + 10k),  the current going through the voltage divider is .5 mA. Using the power formula, 10v x .5 mA, the power dissipated by each resistor is 5 mW. The chosen resistors are  ¼ W resistors so power dissipation and overheating will not become a problem.  

2) Current to Voltage Converter
* The current to voltage converter is a 1000 ohm resistor in parallel with a 330 ohm resistor to form a 250 ohm resistor in series with the current source input. The resistor will convert a 4-20 mA range to a 1-5 V output. 4 mA * 250 ohms = 1 volt and 20 mA * 250 ohms = 5 volts. With a current of 20 mA and a produced voltage of 5 V the power dissipated would be .1 W. This is lower than our ¼ W resistor which solves any power dissipation concerns. 

3) RoHS Compliance
* The chosen resistors are stated to be lead free and RoHS compliant by the manufacturer.  

## BOM

| Designator   | Manufacturer      | Manufactured Part #     | Description                         | Quantity    | Price       |
|------------- |------------------ |-------------------------|-------------------------------------|-------------|-------------|
| P1           | ‎jianxin          | JIANXI-09-13-30-zong-01 | ¼ W Resistor Pack                   | 25 pieces   | $6.99       |
| P2           | Texas Instruments | 296-OP-07DP-ND          | IC OPAMP GP 1 CIRCUIT 8DIP (digikey)| 1           | $2.97       |



## References
1) R. C. Dorf and J. A. Svoboda, Introduction to Electric Circuits, 9th Edition, John Wiley & Sons, Inc., 2014   
