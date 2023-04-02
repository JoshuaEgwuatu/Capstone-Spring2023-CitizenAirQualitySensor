# Microcontroller Subsystem Experimentation
* The code for these tests may be found under the Software section with similar names to what the test is covering.

### What Is Being Tested
1. USB Read/Write Speed
2. USB Access Time
3. Sampling Speeds
4. Multiple Sensor Simultaneous Sampling (Analog and Digital)

### What Is Not Being Tested
* Pin count
  * It is not necessary to test the pin count as it is evident that enough pins are available.
* UART
  * It is expected for the UART to be operable
* Signal connections from other subsystems are expected to work

### USB Read/Write Speed
* For this test, we are going to look at reading and writing speeds to a standard USB Fat32 flash drive.  During the test, it is assumed that the flash drive has adequete size to store the data to be written.  To conduct the write test, we simply open a file on the flash drive and write a predetermined set of data as fast as possible while keeping track of how long it took.  We can perform the read test by reading from the data that was just written as fast as possible while also keeping track of time.

| Write Speed (KB/s) | Max (us) | Min (us) | Average (us) |
| ------------------ | -------- | -------- | ------------ |
| 64                 | 538592   | 76       | 1552         |
| 62                 | 543760   | 76       | 1605         |
| 64                 | 543608   | 76       | 1546         |
| 62                 | 567616   | 76       | 1606         |
| 64                 | 547084   | 76       | 1555         |


| Read Speed (KB/s) | Max (us) | Min (us) | Average (us) |
| ----------------- | -------- | -------- | ------------ |
| 168               | 5124     | 84       | 586          |
| 168               | 5120     | 84       | 586          |
| 168               | 5120     | 84       | 586          |
| 169               | 5124     | 84       | 586          |
| 169               | 5344     | 84       | 586          |


* The results are very conclusive.  With all the tests pooled together, it is easy to see a very high precision cluster in the data.  The only variables to really change with any significance are the Max time values.  Most likely, this is where the first write or read takes significantly longer as the file needs to be accessed before anything can be done.  Once the first write or read has been made, the rest become significanly faster.  Knowing this, we could actually say that discarding the Max value as a major outlier is understandable for an average.  With this change, the Min and Average values then become the same at 76 microseconds for writing and 84 microseconds for reading.  This cannot be used for the case of actual write/read speeds however, as in the real application, we will encounter such massive delays as the Max values.  This will lower the speed and is why the write speed can only be as fast as 64 KB/s and read speed as fast as 169 KB/s.  This combined with USB access time will prove valuable in getting efficient timing which is naturally going to give the microcontroller extra time to perform other tasks.

* Shown is an example output from one of the tests.  Numbers were rounded whole.
![USBWriteReadSpeedTestOutput](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/USBWriteReadSpeedTestOutput.JPG)

### USB Access Time
* This test is to see how long it takes to open a file on the USB Fat32 flash drive.  It is expected for the device to have to do this a lot and given that the USB is very probably the slowest component, knowing just how slow is critical.  To test this, a simple code has been created that will initially creating a blank file that is can be opened and written to as normal.  The time start time is marked and then the file will be opened and accessed.  The end time is marked when the file has been fully opened and is able to be read from.  The file is then closed and the test is over.  

| Trial # | Time (ms) |
| ------- | --------- |
| 1       | 2         |
| 2       | 4         |
| 3       | 4         |
| 4       | 4         |
| 5       | 4         |
| 6       | 3         |
| 7       | 4         |
| 8       | 2         |
| 9       | 4         |
| 10      | 4         |
| 11      | 4         |
| 12      | 2         |
| 13      | 4         |
| 14      | 3         |
| 15      | 3         |

* What we are wanting to take away from this test is, when we are going to try to access the flash drive as a means for storage, how long can we expect it to take to get to the file.  Here, we will take the highest amount of time as our worst-case scenario and see that the longest time to access the flash drive was 4 milliseconds.  This means that we can safely adjust our time prediction to account slightly above 4 milliseconds (say 5 or 6).
* This knowledge, combined with write/read speeds will allow us to make accurate predicitons and improve the performance of the device.  Knowing the timing of what is our slowest action (disregarding wireless) is pivotal.  It is doubly important when an interrupt driven system is being implemented.  Preventing the interrupts from overlapping with accruate predictions will allowf or more smoothly flowing performance.
* Shown is a sample output from one of the trials.  Timing reference is ommitted but is known to be in milliseconds.
![USBAccessTimeTest](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/USBAccessTimeTest.JPG)

### Sampling Speeds
* Test 3 text
* Test 3 table
* Test 3 Discussion
* Test Picture

### Multiple Sensor Simultaneous Sampling (Analog and Digital)
* Test 4 text
* Test 4 table
* Test 4 Discussion
* Test Picture
