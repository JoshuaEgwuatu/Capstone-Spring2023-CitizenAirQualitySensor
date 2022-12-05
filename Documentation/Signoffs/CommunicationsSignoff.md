# Communication Signoff
## FUNCTION OF THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The Communication subsystem is responsible for exchanging data across and allows for access to the Internet.  Without this subsystem, wireless gathering of data would be infeasible.  This component will integrate with the microcontroller and act as a liaison or mouth for the device.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The type of chosen type of communication is 4G Long-term Evolution (LTE), which is a standard to describe the telecommunications protocols used by mobile and cellular device communications across broadband cellular networks.  Global System for Mobile Communication (GSM) and 3G are no longer viable options as the hardware supporting them will be shutoff December 31st, 2022  The reasoning behind the decision to utilize this type of communication is the near global infrastructure already set in place.  There are exceptions to this, but in terms of coverage, 4G LTE will be an expansive choice.  
## CONSTRAINTS ON THE SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  The constraints given below are generalized to allow for comparison of any potential contender for the microcontroller.  Constraints on the subsystem are as follows:
1. The component must be able to utilize LTE communication in 4G.  4G operating frequencies include 600 MHz, 700 MHz, 1700/2100 MHz, 2300 MHz, and 2500 MHz bands.  This is the chosen method of accessing the Internet due to its coverage and support in place.
2. The component must have a slot and support for a Subscriber Identity Module card (SIM).  This card contains identification information related to the device that allows a specified mobile network to pinpoint its location.  Without this, the device will be unable to send data to the mobile networks and, by extension, the Internet.
3. Price for this component should remain under $100 as this can quickly become a very expensive component, but it needs a limit and to be included for wireless communication.  
4. The component must support communication with other components.  To do this, Serial Peripheral Interface (SPI), Universal Asynchronous Receiver/Transmitter (UART), or some form of hardware communication will need to be achievable on the board.  SPI is a synchronous method while UART is an asynchronous method for two devices connected over a short distance to liaise.
5. There must be sufficient memory for the code. Comparing similar operating code with libraries and compilation show a range of 12 KB above or below 120 KB (Kilobytes) in flash memory. To account for worst case, 132 KB is the required memory.  
6. The component will need to have coding language support for C and or Python. Support for both is preferred for options and coverage but not required. It is expected that the users will have some degree of coding experience and may potentially personalize or improve upon the code. These languages are chosen due to popularity and performance. C, in particular, is predicted to be very desirable for this project.
7. The manufacturer needs to be a reputable and safe choice. A stable manufacturere that is assumed to remain in business for years to come and continue producing the chosen board is a necessecity. This project aims for replicability, so a board that remains relevant and available is a key part.
8. The clock speed for sending/receiving signals must be at least 4096 KHz.  If the clock were any slower, it would not able to keep up with 4G speeds.  

## BUILDABLES OF SUBSYSTEM
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Shown is the pseudo-code for the operating code.  The final form of the code may have parts added and additional functionalities included, but this is the general idea of how the code should flow.  Proceeding from each section is assuming that there are no errors detected indicating a “Success”.  If an error arises, a default handler will need to be called to assess the situation.  It should also be noted that the loop is intended to be theoretically infinite, however, there is an implicit exit at the shutoff button being pushed.  “Timers” refers to physical or software timers that act as a "Watchdog" to prevent the system from hanging on a bad or failed connection. Once a timer is triggered, an interrupt should start and take over to see what is taking so long.  It will then most likely close the connection and return to the loop to try again.
![Psued-Code_Comm](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/Psuedo-code_Comm.JPG)

## ANALYSIS OF CHOSEN COMPONENT(S)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The team has chosen to look at the Maduino Zero 4G LTE(SIM7600X) to fulfill the needs of the communications subsystem.  It is a small board that takes advantage of the cellular networks to transfer and exchange data wirelessly.  This component will satisfy the previously listed constraints and jobs of this subsystem.  Following are the corresponding fulfillment of the constraints:
1. The Maduino is able to fully utilize 4G LTE to communicate and transmit data throughout the Internet.  The carrier frequencies are 850 MHz, 1800 MHz, and 1900 MHz which puts it within range of the standard GSM. 
2. There is a slot for a SIM card on the bottom of the component with corresponding connections.
3. With a price of $64.80, it falls under the $100 limit.  Two SD cards will also be purchased for a total of $74.80.
4. Both SPI and UART are fully supported to allow for data exchange with the microcontroller.  
5. Two SD cards are used for storage.  The chosen SD will have 8 gigabytes of storage which is more than enough at a reasonable price.
6. The Maduino supports C and Python with many publicly available libraries. 
7. Arduino is a very popular and respected manufacturing and electronics design company.  They were established in 2005 and have had a lot of support throughout the years.  It is expected for them to persist for quite some time.
8. The PCM clock speed runs at 2048 KHz (2G/3G) and 4096 KHz (4G).  The CPU clock speed is not a priority as the device will be input/output heavy and not need to perform high speed computational operations. 

## BILL OF MATERIALS (BOM)
| Designator | Manufacturer      | Manufactured Part # | Description                                                                                     | Quantity | Price Each |
| ---------- | ----------------  | ------------------- | ----------------------------------------------------------------------------------------------- | -------- | ---------- |
| U1         | Maduino/MakerFabs | OHMZ4G7600          | Maduino Zero 4G LTE (SIM7600A-H) (Cellular Communication Device for Wireless Data Transmission) | 1        | $64.80     |
| U2         | Micro Center      | 16GB SDHC 2PK       | Micro Center 16GB SDHC Class 10 Flash Memory Card 2 Pack (Storage for device)                   | 1        | $9.99      |
| U3         | T-Mobile          | ZZZ260R070          | T-Mobile® SIM Card - 4G - 5G (Prepaid SIM card and data plan for wireless Internet access)      | 1        | $10.00     |

Notes: T-Mobile prepaid SIM cards come in many packages and plans for typical tablets and phones.  We are asking for just the SIM card and data plan for ZIP code 38501.  Sim card pack T-Mobile® SIM Card - 4G - 5G (SKU: ZZZ260R070) with the Mobile Internet Plan: Unlimited Mobile Internet with up to 2GB of 5G & 4G LTE Data for $10.00 per month with $10.00 activation fee covering the first month.
