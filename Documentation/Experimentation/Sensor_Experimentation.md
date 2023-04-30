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
### Trial 1

### Trial 2

### Trial 5
    - 
