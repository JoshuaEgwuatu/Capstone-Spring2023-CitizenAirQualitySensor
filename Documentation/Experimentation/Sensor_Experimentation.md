# Sensor Experimentation
* The code for these tests can be found under the software section with similar names to the test themselves

## What is Being Tested
1. Performance/Accuracy of Sensors
    - HW-123 MPU-6050 Detection Sensor
      - Gyroscope Sensor
      - Acceleration Sensor
    - Sharp 2YOA21
      - -Distance Sensor

## What isn’t being tested
1. Air Quality Sensors
    - This is due to the fact that the originally planned sensors didn’t make it through the ordering phase.

2. Sensor start-up times
    - These were taken out of consideration due to the sensors being needed not being available

3. Microcontroller communication protocol
   - This was taken out of consideration due to it being tested in the microcontroller/communication subsystem

4. Resolution of Sensors
    - This was taken out of consideration due to this test being out of the scope of this subsystem. 

## Performance of Sensors
### Sharp 2Y0A21 (Distance Sensor)  
#### Test Setup
Two Trials were done to test the accuracy of the distance sensor. The first trial used a box as the object. The second trial used a computer mouse as the object. A tape measure was set at 5 cm from the sensor. The object was placed at the opposite end of the tape measure. Every 5 cm, the object was moved. The experiment was stopped once 80 cm was reached.

![IMG_3338](https://user-images.githubusercontent.com/110966922/235371363-7579b483-feda-4db6-a57d-4db74489859f.jpg)
Picture of Trial 1 Setup
### Trial 1
| Measured (cm) | Recorded (cm) |
| ------------- | ------------- |
| 5             | 6             |
| 10            | 10            |
| 15            | 15            |
| 20            | 18            |
| 25            | 23            |
| 30            | 29            |
| 35            | 32            |
| 40            | 35            |
| 45            | 39            |
| 50            | 43            |
| 55            | 50            |
| 60            | 57            |
| 65            | 60            |
| 70            | 57            |
| 75            | 55            |
| 80            | 50            |

![IMG_3342](https://user-images.githubusercontent.com/110966922/235371347-77daf7c2-6d4c-4b95-b047-a3c58fe7bd43.jpg)
Picture of Trial 2 Setup

### Trial 2
| Measured (cm) | Recorded (cm) |
| ------------- | ------------- |
| 5             | 6             |
| 10            | 10            |
| 15            | 14            |
| 20            | 16            |
| 25            | 22            |
| 30            | 25            |
| 35            | 28            |
| 40            | 31            |
| 45            | 25            |
| 50            | 21            |
| 55            | 22            |
| 60            | 21            |
| 65            | 19            |
| 70            | 16            |
| 75            | 14            |
| 80            | 13            |

- Unexpected Results:
    - During both trials, the sensor was unable to accurately detect any object within 6 cm. This is something that is known to be true about this sensor, but not being able to detect 80 cm is quite a surprise. During Trial 1, the sensor began to lose its accuracy at the 20 cm mark. The loss of accuracy continued to increase till 60 cm. At this point, the sensor completely lost all accuracy.
    - During Trial 2, the loss of accuracy happened at a quicker rate. It initially started at 15 cm and continued to increase to 40 cm. After this point, the sensor's accuracy was completely lost.
- Conclusion
    -  The Sharp 2YOA21 is not an ideal sensor to use for distance detection. The range of accuracy is between 20 - 60 cm. The sensor appears to perform better for larger objects. The sensor loses accuracy for smaller objects at a quicker rate, this is most likely due to the scope of the lens. Once again, this experiment helps simulate testing for the air quality sensors we weren’t able to obtain.


### HW-123 MPU-6050 Detection Sensor
#### Introduction
- Six different trials were done to test the accuracy of the HW-123 sensor. This sensor has the capability of getting very accurate information about the sensor's orientation. This can be done through the combination of accelerometer and gyroscope data. Both the acceleration speed and gyroscope data show how the sensor is orientated on the X, Y, and Z-Axis. 
#### Test Setup
- The way this sensor was tested was by changing the orientation 6 different times to show that the sensor is analyzing its position correctly. The sensor was rotated 90 degrees in each direction to show a multitode of orientations. Each column shows where the sensor is located on the X, Y, and Z-Axis. The accelerometer will show g (gravitational constant) in the X, Y, and Z-Axis. 


### Trial 1
- Orientation 1 (Upright)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| \-764                   | 15788                    | \-1960                   | 541    | \-133  | \-342  |
| \-972                   | 16012                    | \-2016                   | 333    | \-211  | 369    |
| \-1084                  | 16240                    | \-2148                   | 76     | 622    | \-123  |
| \-812                   | 15864                    | \-1880                   | 688    | \-117  | \-58   |
| \-896                   | 15832                    | \-2184                   | 249    | \-339  | 161    |
| \-1036                  | 16140                    | \-2088                   | 243    | 664    | \-32   |
| \-868                   | 15936                    | \-1880                   | 415    | 57     | \-279  |
| \-804                   | 15796                    | \-1888                   | 522    | \-546  | 395    |
| \-1136                  | 16100                    | \-2232                   | 73     | 568    | \-37   |
| \-1012                  | 15876                    | \-1876                   | 607    | 418    | \-296  |

### Trial 2
- Orientation 2 (90 degrees rotated to the right)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| \-15344                 | \-484                    | \-4784                   | 283    | \-667  | \-36   |
| \-15712                 | \-440                    | \-4916                   | 330    | \-121  | 29     |
| \-15744                 | \-428                    | \-5472                   | 341    | \-118  | 1      |
| 15096                   | \-484                    | \-5592                   | 329    | 1417   | 19     |
| \-15524                 | \-456                    | \-5872                   | 387    | \-561  | 45     |
| \-15612                 | \-492                    | \-5808                   | 365    | \-13   | 9      |
| \-15044                 | \-456                    | \-5592                   | 387    | 193    | 35     |
| \-15576                 | \-436                    | \-5216                   | 316    | \-534  | 42     |
| \-15832                 | \-384                    | \-5468                   | 345    | 140    | 35     |
| \-15308                 | \-400                    | \-4996                   | 365    | 1639   | \-23   |

### Trial 3
- Orientation 3 (180 degrees rotated to the right)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| 692                     | \-16360                  | \-2128                   | 347    | \-106  | 35     |
| 860                     | \-16844                  | \-2420                   | 709    | \-12   | 74     |
| 740                     | \-16436                  | \-2444                   | 282    | 83     | \-85   |
| 744                     | \-16328                  | \-2176                   | 410    | 61     | 37     |
| 940                     | \-16792                  | \-2120                   | 410    | 60     | \-43   |
| 792                     | \-16632                  | \-2196                   | 519    | 261    | \-157  |
| 788                     | \-16328                  | \-2192                   | 342    | 50     | 12     |
| 876                     | \-16904                  | \-2168                   | 415    | 12     | 14     |
| 808                     | \-16468                  | \-2080                   | 477    | 156    | \-83   |
| 752                     | \-16364                  | \-1908                   | 157    | 86     | 42     |


### Trial 4
- Orientation 4 (270 degrees rotated to the right)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| 17168                   | \-80                     | \-1764                   | 362    | 212    | \-37   |
| 17052                   | \-116                    | \-1756                   | 346    | 49     | \-26   |
| 16660                   | \-188                    | \-1612                   | 338    | 48     | \-12   |
| 17264                   | \-84                     | \-1696                   | 347    | 123    | \-28   |
| 16960                   | \-200                    | \-1776                   | 353    | 109    | \-62   |
| 16540                   | \-116                    | \-1780                   | 334    | 50     | \-22   |
| 17112                   | \-136                    | \-1628                   | 336    | 118    | \-10   |
| 17096                   | \-112                    | \-1812                   | 343    | 116    | \-33   |
| 16632                   | \-76                     | \-1724                   | 349    | 13     | \-1    |
| 17264                   | \-140                    | \-1696                   | 351    | 101    | 0      |

### Trial 5
- Orientation 5 (90 degrees rotated downward)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| 1496                    | \-640                    | \-18976                  | 293    | 56     | 641    |
| 1024                    | \-492                    | \-18496                  | 336    | 72     | 3      |
| 1304                    | \-492                    | \-18540                  | 310    | 40     | 3      |
| 1368                    | \-380                    | \-18984                  | 190    | \-1    | 4      |
| 1100                    | \-448                    | \-18468                  | 267    | 20     | 1      |
| 1140                    | \-492                    | \-18596                  | 240    | 51     | 3      |
| 1288                    | \-424                    | \-18948                  | 279    | 31     | 33     |
| 1096                    | \-408                    | \-18544                  | 511    | 235    | 148    |
| 1152                    | \-392                    | \-18400                  | 404    | 146    | 4      |
| 1272                    | \-268                    | \-19012                  | 310    | 65     | 20     |

### Trial 6
- Orientation 6 (90 degrees rotated upward)

| Acceleration X Axis (g) | Accerlaration Y Axis (g) | Accerlaration Z Axis (g) | Gyro X | Gyro Y | Gyro Z |
| ----------------------- | ------------------------ | ------------------------ | ------ | ------ | ------ |
| \-1408                  | \-944                    | 15012                    | 87     | 11     | \-53   |
| \-1308                  | \-924                    | 14288                    | 401    | 147    | \-19   |
| \-1532                  | \-1612                   | 14888                    | 338    | \-38   | \-78   |
| \-1364                  | \-1000                   | 14832                    | 113    | 39     | \-30   |
| \-1368                  | \-848                    | 14324                    | 445    | 160    | \-2    |
| \-1424                  | \-1380                   | 14732                    | 315    | 59     | \-15   |
| \-1484                  | \-980                    | 14868                    | 125    | 23     | \-45   |
| \-1328                  | \-804                    | 14292                    | 399    | 90     | 14     |
| \-1416                  | \-1420                   | 14852                    | 473    | 67     | 15     |
| \-1528                  | \-1092                   | 14940                    | 113    | 32     | \-25   |

- Unexpected Results:
    - After analyzing the Trials, we can see that the digital sensor is in good condition. The accuracy of this sensor is substantially better than the Sharp sensor. The values for the X, Y, and Z axis in acceleration show that the sensor properly analyzes where it is on the coordinate plane.

- Conclusion
    -  The HW-123 is an ideal sensor to use for sensor orientation. Due to the inability to test temperature, we aren't able to test all of its abilities. Once again, this experiment helps simulate testing for the air quality sensors we weren’t able to obtain.
