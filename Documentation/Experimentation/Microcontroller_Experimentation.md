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
* Test 2 text
* Test 2 table
* Test 2 Discussion
* Test Picture

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
