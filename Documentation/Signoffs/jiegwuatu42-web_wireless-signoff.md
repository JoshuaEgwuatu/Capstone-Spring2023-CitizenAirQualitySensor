# Web and Wireless Signoff
## FUNCTION OF THE SUBSYSTEM

The Web & Wireless subsystem is responsible for receiving data from the Communication subsystem, storing data received from the Communication subsystem on a host device, formatting and encrypting the data, and displaying the data for the user on a webpage.

## CONSTRAINTS ON THE SUBSYSTEM

The subsystem constraints are placed to ensure that it can fulfill its job in a satisfactory manner. Constraints on the subsystem are as follows:
1. The server must be able to communicate with the microcontroller:
Via 4G LTE
Via Wi-Fi
2. The server must have adequate storage for user data. This storage is based on the number of sensors used at once (3 max). The current goal is to hold data collected for a month. At this time, 1 GB of ram is required. A chart will be provided to show if the user chooses to use a different option. 
The equation used: 10 Hz (worst case sampling rate) * 10 bits (analog to digital converter) = 100 bits. 100 bits / 8 (8 bits in a byte) = 12.5 bytes per second. 12.5 bytes per second / 10^6 (convert to megabytes) = 12.5*10^-6 megabytes. 12.5*10^-6 megabytes * 1 month = 32.8536 megabytes per month. 32.8536 megabytes per month * 3 (sensors in microcontroller at one time) = 98.5608  megabytes per month [N/A]

Chart Displaying Possibilities:


| Required Space for Server (Megabytes per month) |  |        |         |        |
| ----------------------------------------------- |  |        |         |        |
|                                                 |  | Data Size |
| Sensors left in the field                       |  | 8 Bits | 10 Bits | 16 bits |
| 1 Month                                         |  | 7.88E+01 | 9.86E+01 | 1.58E+02 |
| 3 Months                                        |  | 2.37E+02 | 2.96E+02 | 4.73E+02 |
| 6 Months                                        |  | 4.73E+02 | 5.91E+02 | 9.46E+02 |
| 1 Year                                          |  | 9.46E+02 | 1.18E+03 | 1.89E+03 |

3. The data will be encrypted and decrypted using AES Symmetric Encryption. The encryption/decryption will happen at two different times:
Microcontroller to Server
Server to User
4. The server must be able to process the data collected.
5. The server must establish a connection to the internet. The server must be accessible via the Internet.
6. The data received must be displayed in an easy-to-understand format.



## BUILDABLE SCHEMATIC OF SUBSYSTEM

<img width="350" alt="4G Connection" src="https://user-images.githubusercontent.com/110966922/219462337-5e72409b-17d1-4c59-8d68-eab86c8fda1f.png">
<img width="432" alt="Wifi Connection" src="https://user-images.githubusercontent.com/110966922/219462340-b16763c0-cbe4-4803-ba0f-be77fbb212e4.png">


Server will be made using HTML. It will receive info from TCP Connection provided from UART. 

## ANALYSIS OF CHOSEN COMPONENT(S)

1. Arduino IDE
2. ArduinoMqttClient

For Wifi Component:
3. NodeMCU
Works with HiLetGo 1PC ESP8266 NodeMCU CP2102 ESP-12E
Arduino-like hardware IO which is easier for the user to configure and manipulate. 
![Wifi Module HTTP Server](https://user-images.githubusercontent.com/110966922/221247686-2bc1a8b8-0a40-409c-804d-ef23eedf323f.png)
![Wifi Module Access Point](https://user-images.githubusercontent.com/110966922/221247710-097123f8-785a-4ec7-b119-68a5eb4fa8a0.png)


For 4G LTE:


## BILL OF MATERIALS (BOM)

N/A

## References
1. A. Marget, “Data Encryption: How It Works & Methods Used,” Unitrends, Jan. 27, 2022. https://www.unitrends.com/blog/data-encryption#:~:text=A%20key%20is%20used%20to (accessed Feb. 10, 2023).
‌
2. I. Craggs, “MQTT Vs. HTTP: Which protocol is the best for IoT or IIoT?,” www.hivemq.com. https://www.hivemq.com/blog/mqtt-vs-http-protocols-in-iot-iiot/#:~:text=They%20both%20run%20over%20TCP (accessed Feb. 10, 2023).
‌
3. “How to Send Data from Arduino to Webpage using WiFi,” Circuitdigest.com, 2016. https://circuitdigest.com/microcontroller-projects/sending-arduino-data-to-webpage (accessed Feb. 10, 2023).
‌
4. Datasheet SPS30 Particulate Matter Sensor for Air Quality Monitoring and Control.” https://cdn.sparkfun.com/assets/4/e/e/f/8/Sensirion_PM_Sensors_Datasheet_SPS30.pdf (Accessed on 2-23-23).

5. Amazon.com: Customer reviews: HiLetgo 1PC ESP8266 NodeMCU CP2102 ESP-12E Development Board Open Source Serial Module Works Great for Arduino IDE/Micropython (Small),” www.amazon.com. https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/product-reviews/B010O1G1ES/ref=cm_cr_dp_d_show_all_btm?ie=UTF8&reviewerType=all_reviews (accessed Feb. 23, 2023).
‌
6. nodemcu, “nodemcu/nodemcu-firmware,” GitHub, Apr. 04, 2019. https://github.com/nodemcu/nodemcu-firmware (accessed Feb. 23, 2023).

7. Admin, “SIM7600 4G GSM with Arduino | AT Commands, Call, SMS,” How To Electronics, Jan. 20, 2022. https://how2electronics.com/using-sim7600-4g-gsm-with-arduino-at-commands-call-sms/ (accessed Feb. 23, 2023)
‌
8. “Maduino Zero 4G LTE(SIM7600X),” Makerfabs. https://www.makerfabs.com/maduino-zero-4g-lte-sim7600.html (accessed Feb. 23, 2023).
