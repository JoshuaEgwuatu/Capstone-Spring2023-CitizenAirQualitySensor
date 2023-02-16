Interface Signoff
Subsystem Function
    • The interface will be able to connect a minimum of 3 sensor signal output types to the microcontroller. These output signal types will be in the form of: Analog voltage, analog current and digital signals. 
Subsystem Constraints
    • Must support these current and voltage signal ranges without harming the microcontroller
        a. Common voltage output ranges: 0 to 1 V, 0 to 5 V, 1 to 5 V, 0 to 10V, and -10 to 10 V. 
        b. Common current output range of 4-20 mA.
System Schematic


Analysis
    1. Overvoltage Protection
        a. The resistor at the input of the 741 op amp will serve to keep the clamping diodes under the max current rating. The schottky 1N5817 diodes can handle a forward current of 25 A for 8.3 ms, thus a 10k resistor will keep the forward current in the mA range for voltages below 100 V. This will ensure the diodes stay well below their max current rating.
        b. The schottky diodes at the input form a clamping circuit and will become forward biased if the anode voltage is higher than the supply voltage of 5 volts. This will pull the voltage up or down to one of the supply voltages and redirect excess current away from the op amp inputs. 
        c. The diode at the output of the op amp will behave the same way serving as extra protection to pull the voltage down to 5 volts before entering the microcontroller.
    2. Amplification
        a. The 741 op amp will use two resistors with Rl set to a fixed value of 100 ohms and R2 being a 100 K potentiometer to allow the user to increase or decrease the gain depending on the output signal of the sensor.
            i. 
Gain
R1
R2
1
100 ohms
0 ohms
10
100 ohms
1k ohms
100
100 ohms
10k ohms
1000
100 ohms
100k ohms
            ii. If the input signal to the op amp is already within the volt range then the microcontroller can measure the signal without needing amplification therefore a gain of 1 would be sufficient. However, if the signal was 1 mV then you would need a gain of 1000 to amplify to the range of 1 volt. A 100k ohm potentiometer as the R2 component in the op amp will allow this choice. 
        b. The op amp positive supply voltage will be 5 volts and the negative supply voltage will be 1 volt. This will ensure that the op amp voltage output will not go below 1 volt or above 5 volts even if input voltage to the op amp has negative values such as a -10 to 10 volt range. 
    3. Current to Voltage Converter
        a. The current to voltage converter is just a 250 ohm resistor in series with the current source input. This will convert a current output from an analog sensor to a voltage output to be measured by the arduino. 
        b. Due to ohm's law, V=IR, a 250 ohm resistor will convert a 4-20 mA range to a 1-5 V output.
            i. 4 mA * 250 ohms = 1 volts
            ii. 20 mA * 250 ohms = 5 volts  
BOM
Designator
Manufacturer
Manufactured Part #
Description
Quantity
Price 
P1
Juried Engineering
‎LM741CN/NOPB
LM741 Single 44V 1 MHz Operational Amplifier Op Amp (Pack of 10)
1
$12.09
P2
BOJACK

125 Piece 1N5817 Diode Pack
1
$5.99
P3
MCIGICM
IN5817
125 Piece Resistor Pack
1
$5.99
References
    1. Storr, Wayne. “Non-Inverting Operational Amplifier - the Non-Inverting Op-Amp.” Basic Electronics Tutorials, 4 Aug. 2022, https://www.electronics-tutorials.ws/opamp/opamp_3.html.
    2. Burton, Daniel. “OP Amp Input over-Voltage Protection: Clamping vs. Integrated.” Microwave Product Digest, 22 Feb. 2016, https://www.mpdigest.com/2016/02/22/op-amp-input-over-voltage-protection-clamping-vs-integrated/. 
    3. 