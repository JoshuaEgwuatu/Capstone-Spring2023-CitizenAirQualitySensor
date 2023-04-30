# Interface Experimentation 
## Included Test Specifications
* Conversion of the following voltage ranges to 0-5 V: 0-3 V, 0-10 V, -10 V to +10 V, -5 V to +5 V and read the output voltages from the ADC.
## Excluded Test Specifications
* Components must be RoHS compliant
* Components chosen have gone through thorough testing for hazardous components to be listed as RoHS compliant and therefore I will not be testing this myself.
* Interface must run off of 5 V
* 5 volts will be provided from the power subsystem to components requiring voltage which does not warrant testing.
* Interface analog current sensors with the Arduino ADC
  * We do not have access to any current sensors or any substitutes. 

## 0 to 3 V to 0 to 5 V Converter
### Trial One
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0	                |1.19|
|0.5	              |1.19|
|1	                |1.64|
|1.5               |	2.55|
|2	                |3.41|
|2.5               |	4.26|
|3	                |4.26|
### Trial Two
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	1.19|
|0.5|	1.19|
|1|	1.7|
|1.5|	2.59|
|2|	3.48|
|2.5|	4.26|
|3|	4.26|
### Trial Three
| Input Voltage(V) | OutputVoltage (V) | 
|------------------|-------------------|
|0|	1.19|
|0.5|	1.19|
|1|	1.77|
|1.5|	2.61|
|2|	3.35|
|2.5|	4.26|
|3|	4.26|
### Trial Four
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	1.19|
|0.5|	1.19|
|1|	1.77|
|1.5|	2.51|
|2|	3.44|
|2.5|	4.17|
|3|	4.26|
### Trial Five
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	1.19|
|0.5|	1.19|
|1|	1.78|
|1.5|	2.62|
|2|	3.42|
|2.5|	4.22|
|3|	4.26|

* Test Setup: 
  * Circuit was set up using the circuits lab power supplies with channel set to 5 V and sent to the 
power supply pin to represent the 5 V signal coming from the power subsystem, then channel 2 
set to various voltages in between 0 V and 3 V representing the sensor output voltages that 
become the interface inputs. The circuit has a current draw of 10 mA, so the current knob on the 
power supply was set accordingly to ensure the circuit does not draw more current than allowed. 
The output of the circuit was then connected to pin A0 of the Arduino and the resultant voltage 
from the ADC was then read for each input voltage.
* Unexpected Results:
  * For an input voltage of 0, the expected output voltage is 0 but instead it is 1.19 V. This is due to a phenomenon called common-mode rejection. For a 0 V signal to 2nd and 3rd pin inputs of the amp, a non-zero output voltage of above 3 was recorded. For ideal operations, op amps amplify the difference between the input voltages so if there is no difference the output should be 0. However, due to the feedback resistors current is being leaked back to the 2nd pin input creating a voltage difference between the two inputs that gets amplified and shown on the output. 
* Conclusion
  * Due to common mode rejection, this circuit will convert a 0 - 3 V output to about 1- 5 V. This 
will not result in a loss of data but instead a loss in ADC resolution. 

## 0 to 10 V to 0 to 5 V Converter

### Trial One
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	0|
|1|	0.51|
|2|	1.03|
|3|	1.51|
|4|	2.03|
|5|	2.54|
|6|	3.04|
|7|	3.53|
|8|	4.04|
|9|	4.55|
|10|	5|

### Trial Two
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	0|
|1|	0.53|
|2|	1|
|3|	1.52|
|4|	2.01|
|5|	2.51|
|6|	3.04|
|7|	3.51|
|8|	4.03|
|9|	4.53|
|10|	5|

### Trial Three
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	0|
|1|	0.5|
|2|	1.02|
|3|	1.51|
|4|	2|
|5|	2.52|
|6|	3.03|
|7|	3.62|
|8|	4.02|
|9|	4.52|
|10|	5|

### Trial Four
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	0|
|1|	0.52|
|2|	1|
|3|	1.52|
|4|	2|
|5|	2.52|
|6|	3.05|
|7|	3.51|
|8|	4.02|
|9|	4.52|
|10|	5|
### Trial Five
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|0|	0|
|1|	0.53|
|2|	1.02|
|3|	1.52|
|4|	2.01|
|5|	2.52|
|6|	3.03|
|7|	3.52|
|8|	4.06|
|9|	4.53|
|10|	10|

* Test Setup: 
  * Circuit was set up using the circuits lab power supplies with channel set to 5 V and sent to the 
power supply pin of the op amp to represent the 5 V signal coming from the power subsystem, 
then channel 2 set to various voltages in between 0 V and 10 V representing the sensor output 
voltages that become the inputs to the interface. The circuit does not draw power/current from the 
sensor or power supply as it is just a voltage divider. The output of the circuit was then connected 
to pin A0 of the Arduino and the resultant voltage from the ADC was then read for each input 
voltage.
* Unexpected Results:
  * Testing showed expected results
* Conclusion
  * Circuit works as expected without any data or resolution loss and is therefore successful. 
## -5 to 5 V to 0 to 5 V Converter
### Trial One
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-5|	0|
|-4|	0.51|
|-3|	1.03|
|-2|	1.53|
|-1|	2.01|
|0|	2.48|
|1|	2.59|
|2|	3.47|
|3|	4.02|
|4|	4.52|
|5|	5|
### Trial Two
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-5|	0|
|-4|	0.51|
|-3|	1.04|
|-2|	1.53|
|-1|	2.03|
|0|	2.51|
|1|	2.59|
|2|	3.46|
|3|	4.01|
|4|	4.51|
|5|	5|
### Trial Three
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-5|	0|
|-4|	0.53|
|-3|	1.04|
|-2|	1.51|
|-1|	2.02|
|0|	2.5|
|1|	2.57|
|2|	3.47|
|3|	4.01|
|4|	4.5|
|5|	5|
### Trial Four
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-5|	0|
|-4|	0.54|
|-3|	1.05|
|-2|	1.53|
|-1|	2.03|
|0|	2.53|
|1|	2.56|
|2|	3.48|
|3|	4|
|4|	4.52|
|5|	5|
### Trial Five
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-5|	0|
|-4|	0.52|
|-3|	1.03|
|-2|	1.51|
|-1|	2.01|
|0|	2.49|
|1|	2.55|
|2|	3.47|
|3|	4.02|
|4|	4.51|
|5|	5|

* Test Setup: 
  * Circuit was set up using the circuits lab power supplies with channel set to 5 V and sent to the 
power supply pin of the op amp to represent the 5 V signal coming from the power subsystem, 
then channel 2 set to various voltages in between -5 V and 5 V representing the sensor output 
voltages that become the inputs to the interface. The circuit does draw current from the 
sensor or the power supply used as a substitute, and it comes out to about .03 mA. Current knob 
was adjusted accordingly to ensure the power supply did not supply more than .03 mA. The 
output of the circuit was then connected to pin A0 of the Arduino and the resultant voltage from 
the ADC was then read for each input voltage.
* Unexpected Results:
  * Testing showed expected results
* Conclusion
  * Circuit works as expected without any data or resolution loss and is therefore successful. 
## -10 to 10 V to 0 to 5 V Converter
### Trial One
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-10|	0|
|-7|	0.72|
|-4|	1.48|
|-1|	2.24|
|0|	2.51|
|1|	2.74|
|4|	3.49|
|7|	4.27|
|10|	5|
### Trial Two
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-10|	0|
|-7|	0.72|
|-4|	1.47|
|-1|	2.22|
|0|	2.55|
|1|	2.76|
|4|	3.5|
|7|	4.27|
|10|	5|
### Trial Three
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-10|	0|
|-7|	0.72|
|-4|	1.47|
|-1|	2.24|
|0|	2.51|
|1|	2.75|
|4|	3.5|
|7|	4.27|
|10|	5|
### Trial Four
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-10|	0|
|-7|	0.69|
|-4|	1.48|
|-1|	2.23|
|0|	2.55|
|1|	2.76|
|4|	3.51|
|7|	4.27|
|10|	5|
### Trial Five
| Input Voltage(V) | OutputVoltage (V) | 
| ---------------- | ---------------|
|-10|	0|
|-7|	0.7|
|-4|	1.46|
|-1|	2.23|
|0|	2.51|
|1|	2.75|
|4|	3.51|
|7|	4.28|
|10|	5|

* Test Setup: 
  * Circuit was set up using the circuits lab power supplies with channel set to 5 V and sent to the 
power supply pin of the op amp to represent the 5 V signal coming from the power subsystem, 
then channel 2 set to various voltages in between -10 V and 10 V representing the sensor output 
voltages that become the inputs to the interface. The circuit does draw current from the 
sensor or the power supply used as a substitute, and it comes out to about 1 mA. Current knob 
was adjusted accordingly to ensure the power supply did not supply more than 1 mA. The 
output of the circuit was then connected to pin A0 of the Arduino and the resultant voltage from 
the ADC was then read for each input voltage.
* Unexpected Results:
  * Testing showed expected results
* Conclusion
  * Circuit works as expected without any data or resolution loss and is therefore successful. 
## Arduino,Interface and Code Experimentation Setup Picture

## Arduino Source Code for Voltage Reading from the ADC

![VoltageReadingCode](https://user-images.githubusercontent.com/118490274/234534465-175248e1-ae34-4035-8f14-6658210ad771.JPG)
