# Interface Signoff

## Subsystem Function
The interface conditions any input analog voltage, analog current and digital signal then transmits it to the microcontroller. 
## Subsystem Constraints
1) Must be able to operate with mV voltage output ranges
2) Must support positive DC voltage ranges: 0 to 1 V, 0 to 5 V, 1 to 5 V, 0 to 10V
3) Must be able to operate with negative voltage ranges: -10 to 10 V
4) Must Support current output range: 4-20 mA
5) The PCB material used must be UL certified


## System Schematic

![Interface Schematic Mark 4 PNG](https://user-images.githubusercontent.com/118490274/219834938-37dff819-c3d3-414d-8535-df8448b19ed3.PNG)

## Analysis

1) The amplifier will allow small signals such as those in the mV range to be measured by the arduino. The system is made of the OP27 op amp with resistors Rl set to a fixed value of 100 ohms and R2 being a 100 K potentiometer to allow the user to increase or decrease the gain depending on the output signal of the sensor. If the input signal to the op amp is already within the volt range then the microcontroller can measure the signal without needing amplification therefore a gain of 1 would be sufficient. However, if the signal was 1 mV then you would need a gain of 1000 to amplify to the range of 1 volt. A 100k ohm potentiometer as the R2 component in the op amp will allow this choice.  

| Gain          | R1            | R2              |               
| ------------- | ------------- | -------------   |
|1              | 100 Oohms     |  0 ohms         |
|10             | 100 Oohms     |  1k ohms        |
|100            | 100 Oohms     |  10k ohms       |
|1000           | 100 Oohms     |  100 ohms       |


2) The 1N750 zener diode (D4) at the output of the full wave rectifier circuit has a breakdown voltage of 4.7 volts. If the output voltage of the op amp is above this breakdown voltage the diode will pull the voltage down 4.7 volts. This will ensure that any DC voltage ranges exceeding 5 volts can be used without overloading the arduino.

3) The AC voltage signal is run through a half wave rectifier which will invert the signal and cut any peaks above 0. The original voltage signal and the signal from the half wave rectifier are both run through a summing op amps inverting input. This adds the amplitudes of both signals which produces a negative magnitude and is then inverted by the op amp thus only giving a positive output. This will ensure that the interface can handle any negative voltages coming from an AC signal. 

4) The current to voltage converter is just a 250 ohm resistor in series with the current source input. This will convert a current output from an analog sensor to a voltage output capable of being measured by the arduino. A 250 ohm resistor will convert a 4-20 mA range to a 1-5 V output. 4 mA * 250 ohms = 1 volts and 20 mA * 250 ohms = 5 volts.  

5) The pcb material will be FR4 PCB. The FR4 PCB has been through rigorous testing and has been UL certified.

## BOM

|Designator   |Manufacturer      |Manufactured Part # |Description                                                      | Price       |
|-------------|------------------|--------------------|-----------------------------------------------------------------|-------------|
| 1           |Juried Engineering| LM741CN/NOPB       | M741 Single 44V 1 MHz Operational Amplifier Op Amp (Pack of 10) | $12.09      |
| 2           | OJACK            |                    | 125 Piece 1N5817 Diode Pack                                     | $5.99       |
| 3           | CIGICM           | IN5817             | 125 Piece Resistor Pack                                         | $5.99       |


## References
* Storr, Wayne. “Non-Inverting Operational Amplifier - the Non-Inverting Op-Amp.” Basic Electronics Tutorials, 4 Aug. 2022, https://www.electronics-tutorials.ws/opamp/opamp_3.html.
* Burton, Daniel. “OP Amp Input over-Voltage Protection: Clamping vs. Integrated.” Microwave Product Digest, 22 Feb. 2016, https://www.mpdigest.com/2016/02/22/op-amp-input-over-voltage-protection-clamping-vs-integrated/. 
