# Interface Experimentation 

## Included Test Specifications
* Interface an analog voltage sensor with the Arduino ADC

## Excluded Test Specifications
* Components must be RoHS compliant
  * Components chosen have gone through thorough testing for hazardous components to be listed as RoHS compliant and therefore I will not be testing this myself.
* Interface must run off of 5 V
  * 5 volts will be provided to components requiring voltage which does not warrant testing.
* Interface analog current sensors with the Arduino ADC
  * We do not have access to any current sensors or any substitutes. 
 
##  Interface an Analog Voltage Sensor

### Test Setup: 
* The Sharp 2Y0A21 distance sensor (analog voltage) outputs 0.3 V at 10 cm and 3.1 V at 80 cm. Taking this voltage output range into account, the sensor was attached to the 0 - 3 V to 0 - 5 V converter on the interface. The output of this circuit was then connected to analog pin 1 of the arduino. To test the full voltage range of the distance sensor, three 1 foot tall boxes were stacked on top of one another and then 10 cm ( 4 inches) to 80 cm (2.62 feet) with various in-between measurements were marked out on the boxes. For every marked measurement, an object was placed at that distance away from the sensor and the value of the ADC was read then converted back to a voltage. 

### Trial One

| Distance (in) | Voltage (V) | 
| ----------------| ---------------|
| 4 (10cm)      | 4.25              | 
| 6                  | 3.42              |
| 12                | 1.70              | 
| 14                | 1.35              |
| 18                | 1.19              | 
| 22                | 1.19              | 
| 24                | 1.19              | 
| 26                | 1.19              | 
| 31 ( 80 cm)  | 1.19              | 


### Trial Two

| Distance (in) | Voltage (V) | 
| ----------------| ---------------|
| 4 (10cm)      | 4.25              | 
| 6                  | 3.42              |
| 12                | 1.70              | 
| 14                | 1.35              |
| 18                | 1.19              | 
| 22                | 1.19              | 
| 24                | 1.19              | 
| 26                | 1.19              | 
| 31 ( 80 cm)  | 1.19              | 

### Trial Three

| Distance (in) | Voltage (V) | 
| ----------------| ---------------|
| 4 (10cm)      | 4.25              | 
| 6                  | 3.42              |
| 12                | 1.70              | 
| 14                | 1.35              |
| 18                | 1.19              | 
| 22                | 1.19              | 
| 24                | 1.19              | 
| 26                | 1.19              | 
| 31 ( 80 cm)  | 1.19              | 

### Trial Four

| Distance (in) | Voltage (V) | 
| ----------------| ---------------|
| 4 (10cm)      | 4.25              | 
| 6                  | 3.42              |
| 12                | 1.70              | 
| 14                | 1.35              |
| 18                | 1.19              | 
| 22                | 1.19              | 
| 24                | 1.19              | 
| 26                | 1.19              | 
| 31 ( 80 cm)  | 1.19              | 

### Trial Five

| Distance (in) | Voltage (V) | 
| ----------------| ---------------|
| 4 (10cm)      | 4.25              | 
| 6                  | 3.42              |
| 12                | 1.70              | 
| 14                | 1.35              |
| 18                | 1.19              | 
| 22                | 1.19              | 
| 24                | 1.19              | 
| 26                | 1.19              | 
| 31 ( 80 cm)  | 1.19              | 

* Sensor interfaced to the Arduino

![image_67175169](https://user-images.githubusercontent.com/118490274/234534105-abf72d9c-8cb7-43b0-94ef-95ad185988fa.JPG)


* Sensor Measurement Process Picture

![image_67192577](https://user-images.githubusercontent.com/118490274/234534134-9e19b842-43c4-4040-94ea-0523bbc4e2ae.JPG)



### Unexpected Results:
* As distance increased, I expected the sensor to reach its minimum voltage at 80 cm as stated by the datasheet. However, the output voltage of the sensor read by the ADC consistently caps out at 1.19 V at a distance of 56 cm which is 24 cm under its stated maximum distance of 80 cm. 

### Output Code
 * Output code for distance of 10 cm

![CodeOutputFor10cm](https://user-images.githubusercontent.com/118490274/234534248-dda82f02-3115-4697-ae28-8c09825060e7.JPG)


* Output code for distance of 10 cm

![CodeOutputFor80cm](https://user-images.githubusercontent.com/118490274/234534292-19839a98-c779-469f-aa71-ac2a7493e750.JPG)

### ADC Value to Voltage Source Code

![VoltageReadingCode](https://user-images.githubusercontent.com/118490274/234534465-175248e1-ae34-4035-8f14-6658210ad771.JPG)
