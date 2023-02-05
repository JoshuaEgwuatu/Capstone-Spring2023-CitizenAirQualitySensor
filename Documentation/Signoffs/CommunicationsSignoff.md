# Communication Signoff
## FUNCTION OF THE SUBSYSTEM
The Communication subsystem is responsible for receiving data from the Microcontroller subsystem, connecting the device to the Internet, and formatting/encrypting and sending the received data to the Web & Wireless subsystem.  Encryption is done to protect the data from outside malicious intent.  These functions may be done in two configurations: 4G LTE or Wi-Fi.  This subsystem can be configured to utilize 4G LTE (Long-term Evolution) as a standard in telecommunications to connect to the Internet for its near global coverage [1].  This subsystem may also be configured to connect to the Internet using Wireless-Fidelity (Wi-FI) and its associated IEEE 802.11 (802 Family Set) standard [12].  The Web & Wireless subsystem, a server conjoined to the Internet, will wait for data from the Communication subsystem, format and encrypt the data, and then store and display it for the user on a webpage.

## CONSTRAINTS ON THE SUBSYSTEM
Constraints on the subsystem are as follows for 4G LTE configuration:
1. The component must be able to utilize 4G LTE telecommunication.  This is the chosen method of accessing the Internet for users needing its coverage.
2. The component must have support for a Subscriber Identity Module card (SIM).  
3. Price for this component should remain under $100 as end-users only have a budget of $300.  Recurring costs per month should be $10 or lower.  Allocating 1/3 of the budget is from estimating the costs of other subsystems and viewing prices of available options that satisfy the functions.
4. For receiving data from the Microcontroller subsystem, Universal Asynchronous Receiver/Transmitter (UART) as standards for hardware communication will need to be achievable with at least 2 UART pins [2] [3].  
5. This project aims for replicability, so a board that remains relevant and available is a key part. The manufacturer needs to be a reputable and safe choice. A stable and reputable manufacturer is assumed to remain in business for years to come and continue producing the chosen board. Public and customer reviews will be used to gauge manufacturer reputability while board production history will be used to gauge product longevity.  

Constraints on the subsystem are as follows for Wi-Fi configuration:
1. The component must have support for connecting to an already established Wi-Fi network for Internet access.  
2. Price for this component should remain under $100 as end-users only have a budget of $300.  Allocating 1/3 of the budget is from estimating the costs of other subsystems and viewing prices of available options that satisfy the functions.
3. For receiving data from the Microcontroller subsystem, Universal Asynchronous Receiver/Transmitter (UART) as standards for hardware communication will need to be achievable with at least 2 UART pins [2] [3].
4. This project aims for replicability, so a board that remains relevant and available is a key part. The manufacturer needs to be a reputable and safe choice. A stable and reputable manufacturer is assumed to remain in business for years to come and continue producing the chosen board. Public and customer reviews will be used to gauge manufacturer reputability while board production history will be used to gauge product longevity.  

## BUILDABLES OF SUBSYSTEM
The only connections made are 2 UART connections to the Microcontroller subsystem.  “Timers” refers to physical or software timers that act as a "Watchdog" to prevent the system from hanging on a bad or failed connection. Once a timer is triggered, an interrupt should start and take over to see what is taking so long.  It will then close the connection and return to the loop to wait for another attempt.
![Psued-Code_Comm2](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/Psuedo-code_Comm2.jpg)

## ANALYSIS OF CHOSEN COMPONENT(S)
The team has chosen the Maduino Zero 4G LTE(SIM7600X) to satisfy the previously listed constraints and jobs of this subsystem for 4G LTE:
1. The Maduino is able to fully utilize 4G LTE to communicate and transmit data throughout the Internet.
2. There is a slot for a SIM card on the bottom of the component with corresponding connections.
3. With a price of $64.80, it falls under the $100 limit.  Two SD cards will also be purchased for a total of $74.80.  T-Mobile Mobile Internet Access SIM card has a recurring cost of $10.
4. UART is fully supported to allow for data to be received from the Microcontroller subsystem.  
5. The SIM7600 series of boards were first introduced in 2018 and more realized in production in 2020, making them newer boards [4].  MakerFabs, founded in 2015, is a known manufacturing company that has created many variations of PCBA boards [5].  Their Maduino series is a popular option for wireless connections and is reviewed in detail by many customers positively [6] [7].  

The team has chosen the HiLetGo ESP8266 NodeMCU CP2102 ESP-12E to satisfy the previously listed constraints and jobs of this subsystem for Wi-Fi:
1. The ESP8266 has the ability to connect to a local Wi-Fi network to transmit/receive data throughout the Internet.
2. With a price of $7.99, it falls well under the $100 limit.
3. UART is fully supported to allow for data to be received from the Microcontroller subsystem.
4. The ESP8266 was launched by Espressif in 2014 and has steadily rose in popularity and usage in custom projects requiring a Wi-Fi connection [8] [9].  This manufacturer, HiLetGo, has been producing components since 2016 and specializes in robotic, sensor, and module manufacturing [9].  Although preceeded by the ESP32, ESP8266 continues manufacturing due to its popularity and performance per dollar [10].  Customer reviews highly rate the HiLetGo version of the ESP8266 in particular [11].


## BILL OF MATERIALS (BOM)
| Designator | Manufacturer      | Manufactured Part # | Description                                                                                     | Quantity | Price Each |
| ---------- | ----------------  | ------------------- | ----------------------------------------------------------------------------------------------- | -------- | ---------- |
| U1         | Maduino/MakerFabs | OHMZ4G7600          | Maduino Zero 4G LTE (SIM7600A-H) (Cellular Communication Device for Wireless Data Transmission) | 1        | $64.80     |
| U2         | SanDisk           | SDSDXNE-016G-GNCIN  | SanDisk 16GB Extreme SDHC UHS-I Memory Card - 90MB/s, C10, U3, V30, 4K UHD                      | 2        | $9.99      |
| U3         | T-Mobile          | ZZZ260R070          | T-Mobile® SIM Card - 4G - 5G (Prepaid SIM card and data plan for wireless Internet access)      | 1        | $9.78      |
| U4         | HiLetGo           | 703681358704        | HiLetGo 1PC ESP8266 NodeMCU CP2102 ESP-12E Development Board Open Source Serial Module          | 1        | $7.99      |

Notes: Do not purchase the T-Mobile prepaid SIM card  or Maduino Zero 4G LTE without an explicit request from the supervisor or instuctor and team.  Wi-Fi will be the initial focus, so there is not need to pay for a monthly plan just yet. 

Notes: The Maduino Zero 4G LTE (SIM7600A-H) ("A-H" referring to North American frequency bands while "E-H" refers to several other countries) can only be purchased from MakerFabs.  The SanDisk 16GB Extreme SDHC UHS-I Memory Card (SD Card) and HiLetGo 1PC ESP8266 are both available from Amazon.

Notes: T-Mobile prepaid SIM cards come in many packages and plans for typical tablets and phones.  We are asking for just the SIM card and data plan for ZIP code 38501.  Sim card pack T-Mobile® SIM Card - 4G - 5G (SKU: ZZZ260R070) with the Mobile Internet Plan: Unlimited Mobile Internet with up to 2GB of 5G & 4G LTE Data for $10.00 per month with $10.00 activation fee covering the first month.

## References
1. European Telecommunications Standards Institute (ETSI), "4th Generation (LTE)," https://www.etsi.org/technologies/mobile/4G (Accessed on 12-8-22).
2. Texas Instruments, Electrical Design and Semiconductor Production Company, "Universal Asynchronous Receiver/Transmitter (UART)," https://www.ti.com/lit/ug/sprugp1/sprugp1.pdf?ts=1670532165815&ref_url=https%253A%252F%252Fwww.google.com%252F (Accessed on 12-8-22).
3. Pena, Eric, Analog Dialogue, Technical Magazine, "UART: A Hardware Communication Protocol Understanding Universal Asynchronous Receiver/Transmitter," https://www.analog.com/en/analog-dialogue/articles/uart-a-hardware-communication-protocol.html (Accessed on 12-8-22).
4. SIMCom Wireless Solutions Limited, Leading Supplier of M2M Modules and Solutions, "SIM7600X," https://www.simcom.com/product/SIM7600X.html (Accessed on 12-8-22).
5. MakerFabs, Hardware Facilitation Company, "MakerFabs Main Page," https://www.makerfabs.com/wiki/index.php?title=Main_Page (Accessed on 12-8-22).
6. Tindie, Reviews, Critiques, and Marketplace, "MakerFabs Review," https://www.tindie.com/stores/makerfabs/reviews/ (Accessed on 12-8-22).
7. HowToElectronics, Engineering Community For Public Electrical Projects, News, and Articles, "Using SIM7600 4G GSM with Arduino | AT Commands, Call, SMS," https://how2electronics.com/using-sim7600-4g-gsm-with-arduino-at-commands-call-sms/ (Accessed on 12-8-22).
8. Espressif Systems, Specializes in AIoT Development, "ESP8266," https://www.espressif.com/en/products/socs/esp8266 (Accessed on 12-8-22).
9. Tones B, Instructables, Autodesk Inc., Documentation and Engineering Education Community, "ESP8266 WiFi Module for Dummies," https://www.instructables.com/ESP8266-WiFi-Module-for-Dummies/ (Accessed on 12-8-22).
10. Ida HÜbschmann, Nabto, IoT Communication Development Organization, "ESP8266 for IoT: A Complete Guide," https://www.nabto.com/esp8266-for-iot-complete-guide/ (Accessed on 12-8-22).
11. Amazon, Online Marketplace, "HiLetgo 1PC ESP8266 NodeMCU CP2102 ESP-12E Customer Reviews," https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/product-reviews/B010O1G1ES/ref=cm_cr_dp_d_show_all_btm?ie=UTF8&reviewerType=all_reviews (Accessed on 12-8-22).
12. Institute of Electrical and Electronics Engineers (IEEE), Electrical Engineer Association and Standardizing Committee, "IEEE 802," https://standards.ieee.org/featured/ieee-802/ (Accessed on 12-8-22)
