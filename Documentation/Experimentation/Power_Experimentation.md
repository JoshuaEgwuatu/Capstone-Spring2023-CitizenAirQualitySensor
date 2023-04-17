# Power System Experimentation

## What is being tested?
1. Current draw of the system with and without sensors
2. Recharge capabilities of the solar cell
3. Voltage output for the DC-DC convertor 
## What isn't being tested?
1. Ability to operate on battery and AC mains input
    *  Was shown during minimum functionality prototype 
## System Current Draw
For this test, the power input of the microcontroller will be supplied with 5 V and a DMM set to measure
current will be placed in series at the positive input. A sample will be taken every second for 5 minutes 
and logged. The test will be run again with the sensors disconnected in order to establish the current 
draw independent of the sensors.
### Graphs
![Current Consumption With Sensors -2](https://user-images.githubusercontent.com/118766525/232384061-53cbb2c1-c43c-4e8f-9801-1c4e4ef69af3.png)
![Current Consumption without Sensors-2](https://user-images.githubusercontent.com/118766525/232383700-8ebcc5ed-2d50-4066-8cf5-7959633268e7.png)
### Explanation
The above tests show the current draw over around 5 minutes of the system. The results show that using 
the sensors causes the current to fluctuate regularly around 237 mA. The slight negative slope can be 
attributed to the high initial current consumption shown in the test running just the microcontroller. 
Also observed was how consistent the Arduinos’ power draw is with minimal variance about the average 
current of 199 mA. The maximum current draw observed during operation with the sensors was 245.56 mA 
while the minimum value was 228.98. If you use the worst case current draw alongside the 5 V input, 
you get a power draw of 1.2278 W. Our selected battery has a capacity of 92.5 Wh. Using this and the 
worst case power draw shows that our device should run for 75.34 hours with no further charging from 
the solar cell. Using the average current draw of 237 mA gives a power draw of 1.185 W. This gives a use 
time of 78.05 hours. Both of these values are well above the minimum operation time of 48 hours; however, 
they also fall below the expected operation time outlined in the power subsystem detail design. This is due 
to the sensors chosen using more current than initially accounted  for as well as the estimations for current 
use from the arduino being taken utilizing low power features from a library that was not implemented.
### Further Improvements/Experimentation 
Implementing and testing the low power library as well as the use of the deep sleep mode for ATMega2560 
should be the priority for future improvements as it could decrease the average current consumption significantly 
and lead to improved operational time.

## DC-DC Convertor 
For this test, the input will be supplied with 5 V from the bench supply in the capstone lab. A DMM will be connected 
across the output leads of the converter and the voltage will be measured. This will be taken 5 times and then the 
convertor will be calibrated and the data will be taken again. 
### Results 
#### Uncalibrated Results 
|                 | Trial 1 | Trial 2 | Trial 3  | Trial 4 | Trial 5 |
|-----------------|---------|---------|----------|---------|---------|
| Input Voltage   | 5.07    | 5.07    | 5.07     | 5.07    | 5.07    |
| Output voltage  | 3.15947 | 3.15951 | 3.15972  | 3.15976 | 3.15959 |
| Shown Output    | 3.0     | 3.0     | 3.0      | 3.0     | 3.0     |
#### Calibrated Results 
|                 | Trial 1 | Trail 2 | Trail 3 | Trial 4 | Trial 5 |
|-----------------|---------|---------|---------|---------|---------|
| Input Voltage   | 5.07    | 5.07    | 5.07    | 5.07    | 5.07    |
| Output Voltage  | 2.94648 | 2.94681 | 2.94656 | 2.94630 | 2.94629 |
| Shown Output    | 2.8     | 2.8     | 2.8     | 2.8     | 2.8     |
### Explanation
The output out of the box seems to overshoot the output by about 0.15V. Once the converter was calibrated using a voltmeter 
and adjusting the potentiometer on the device a stable output near the desired voltage was easily achieved. The output voltage 
shown by the seven segment displays was still showing an output voltage of about 0.15V less than the actual output and should be 
used cautiously and we recommend calibrating the device especially if exact voltages or tight tolerances are required by the sensors
being powered. 
### Further Improvements/Experimentation 
We would have liked to observe the ripple voltage under a sufficant and varrying load but, we did not have the sensors we planned on ordering. Implementing these sensors and observing the ripple volatge using the same method presented above and a scope probe across the output should be done in future experiments.

## Solar cell
For this test, the battery will be discharged until the indicator LEDs show it is around half charged.
The solar cell will then be left on a car dashboard overnight so that it is in the sun from sunrise to sunset.
At the end of the day the battery charge level will be inspected using the indicator LEDs once again. 
This process will be repeated until it is fully charged
### Results
The solar cell was discharged and left until the night of April 5th. On the night of April 4th the battery was inspected and the indicator LEDs showed the battery at near 3/4 capacity. At the end of the second day when I checked it again the battery was fully charged. April 4th was mostly cloudy for a majority of the peak solar hours and became partly cloudy towards the  end of the day and April 5th was sunny during the peak solar hours and overcast for the end of the day.

### Explanation 
 This test showed a mix of weather conditions and showed that even on a cloudy day we can expect to regain a 
quarter of the capacity or more. Given the imprecise nature of testing the capacity with its four indicator LEDs, we are not able to guarantee 
that the chosen solar cell completely replenishes the power used through an entire day based on weather conditions. Assuming the capacity gained 
from the mostly cloudy day was just 25%, which would be the worst case given another LED lit up, the solar cell collected 23.125 Wh throughout the day. Using the capacity of the battery and the hourly gain in energy from the solar cell and the worst case power draw, it can be shown that the system will operate for slightly more than 418 hours. If this is not long enough for the user, they may implement the solution presented in the detailed design of plugging an additional usb-c solar cell into the power input of the battery to further prolong operation.
