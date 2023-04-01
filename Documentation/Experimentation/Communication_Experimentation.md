# Communication Subsystem Experimentation
* The code for these tests can be found under the software section with similar names to the tests themselves.
### What Is Being Tested
1. Wi-Fi Connection Distance Test
2. Throughput for our code

### What Is Not Being Tested And Why
* Ability to connect Wi-Fi
  * It should be a given that a device that claims to connect to Wi-Fi does indeed connect to the Wi-Fi.  This ability was proven during the prototype demonstration.
  * Given that the ESP8266 is the Wi-Fi component, we may assume that its hardware is functioning as intended.
* 3G/4G/LTE abilities
  * 3G services are no longer supported in the U.S.A.  
  * 4G/LTE options are not being implementing in this iteration
* TCP Client
  * HTTP has been chosen for accessing the server instead, so it is sufficient to know that the ESP8266 can do TCP to then achieve a HTTP Client
* UART receiving data and instructions
  * It is expected that UART will be operable from purchase

### Wi-Fi Capabilities
* For this test, we are actually going to be measuring the range of the ESP8266 to connect to the Wi-Fi.  This is to help see how far a user can place the device from a router and still work.  For this test, a simple code has been created that just marks the time it starts to connect to the Wi-Fi and marks the time that it fully connects.  This is just to see how long of a delay may be needed before sampling from the senosrs.  This is under normal conditions with few obstacles or inclement weather.  Distance is gradually increased after each success until a failure occurs. 

| Distance (ft) | Connect Time (ms) | Success or Failure |
| ------------- | ----------------- | ------------------ |
| 10            | 5580              | S                  |
| 20            | 5530              | S                  |
| 30            | 5130              | S                  |
| 40            | 5930              | S                  |
| 50            | 6431              | S                  |
| 60            | 5880              | S                  |
| 70            | 5631              | S                  |
| 80            | 21688             | S                  |
| 90            | 20199             | S                  |
| 100           | N/A               | F                  |
| 100+          | N/A               | F                  |

* As distance increases, I expected for the time to be linearly increasing, but that was not the case.  For the first few tries, it remained pretty consistently around 5-6 seconds.  It was only after 50 ft. that it took over 6 seconds.  What was weird was that it then dipped back under 6 seconds until 80 when it took an serious jump in time to nearly 22 seconds.  It still connected even at 90 ft. in 20 seconds, but the connection after 100 ft. was taking so long, that I stopped the tests after 100+ ft.  I did take step a few feet forward on the last test from 110 ft. and saw that the time read 44 seconds.
* For our purposes, the device can be reliably used within 70 ft. of the Wi-Fi source.  The device can still be used within 90 ft. of the Wi-Fi source, but the connection is very slow.  The code would need to be adjusted accordingly.  Going passed 90 ft. is when the reliability is almost non-existent and cannot be recommended for use.  The 4G alternative is, at the time of writing this, unavailable but would fill the role when a known Wi-Fi source is not close enough.
* Shown is the output from some of the tests.  Real IP and SSID are blocked for security.

![ESPDistanceTestOutput](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/ESPDistanceTestOutput.jpg)

### Throughput Test
* Although not explicitly stated anywhere in the rest of the documentation, it would be nice to know how much throughput we can get to with how our code is setup.  For this test, I will need a simple client that will constantly send some data.  Then, I wil need a server that will just receive the data.  The data to be sent will need to be consistant, so I chose the letters of the alphabet, coming out to 26 bytes per transmission.  To start the test, I just set the server to wait and start the client to send as fast as it can transmit to the server for 1 second.

| Number of Alphabets | Bytes Sent | Number of transmission |
| ------------------- | ---------- | ---------------------- |
| 1                   | 6110       | 235                    |
| 2                   | 12220      | 235                    |
| 3                   | 18330      | 235                    |
| 20                  | 122200     | 235                    |
| 60                  | 132600     | 85                     |
| 40                  | 132080     | 127                    |
| 50                  | 132600     | 102                    |
| 30                  | 131,820    | 169                    |
| 45                  | 132600     | 113                    |

The number of alphabets literally mean that I am sending that many sets of the standard english alphabet A-Z.  Bytes sent is calculated by number of transmission times byte size of the alphabet (26) times the number of alphabets.  I started off small with just a few sets to send and kept hitting roughly the same number of transmissions per second.  I decided to try and bump it up to 20 to see if that would change.  It didn't, so I decided to bump it up some more and it drastically lowered the number of transmissions.  This showed that the ESP8266 was struggling greatly to send the larger set of data at the same speeds.  In bumbing it to 60 sets, I was able to reach speeds of 1.326 kB per second and could not get passed this.  I decided to just fill in some of the numbers between and see where roughly where the cap on speed is for the bytes sent.  I found it to be around 45 sets of the alphabet.  Going passed this yielded the same speed.  It should be noted that this is a test of upload speed which is typically much slower than download speed.
* Code for this Client test can be found in the Software section.  Pictures of the physical test setup are not provided for this test as it seems unnecessary as the device is just connected to a laptop.  The test is entirely software based and cannot be seen.
* Shown is what the output from the client looked like.  Basically, what transmission count it stopped sending at.

![ESPThroughputTestOutputClientSide](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/ESPThroughputTestOutputClientSide.JPG)

* Shown is what the output from the server looked like.  Basically, the alphabet a lot.

![ESPThroughputTestOutputServerSide](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/ESPThroughputTestOutputServerSide.JPG)
