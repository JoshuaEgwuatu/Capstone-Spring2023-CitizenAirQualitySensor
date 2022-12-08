# Communication Signoff
## FUNCTION OF THE SUBSYSTEM
The Communication subsystem is responsible for receiving data from the Microcontroller subsystem, connecting the device to the Internet, and formatting and sending the received data to the Web & Wireless subsystem.  This subsystem will utilize 4G LTE (Long-term Evolution) as a standard in telecommunications to connect to the Internet, a vast collection of connected computer networks, for its near global coverage.  The Web & Wireless subsystem, a server conjoined to the Internet, will wait for data from the Communication subsystem, format and encrypt the data, and then store and display it for the user on a webpage.

## CONSTRAINTS ON THE SUBSYSTEM
Constraints on the subsystem are as follows:
1. The component must be able to utilize 4G LTE telecommunication.  For 4G LTE, the component will need to operate in the 600-2500 MHz range.  This is the chosen method of accessing the Internet due to its coverage and support in place.
2. The component must have support for a Subscriber Identity Module card (SIM).  
3. Price for this component should remain under $100 as end-users only have a budget of $300.  Recurring costs per month should be $10 or lower.  Allocating 1/3 of the budget is from estimating the costs of other subsystems and viewing prices of available options that satisfy the functions.
4. For receiving data from the Microcontroller subsystem, Universal Asynchronous Receiver/Transmitter (UART) as standards for hardware communication will need to be achievable.  
5. There must be sufficient memory for the code. Comparing similar operating code (Wireless Sensor Collection and Small-time Processes Operating) with libraries and compilation show a range of 12 KB (Kilobyte) (10%) above or below 120 KB in flash memory. To account for worst case, 132 KB is the required memory.  
6. The board will need to have coding language support for C and/or Python. At least one must be supported. These languages are chosen due to popularity, online support, and performance. This helps create a wider web of coverage for end-users who are at least relatively experienced with coding and engineering concepts.
7. This project aims for replicability, so a component with a stable and reputable manufacturer that remains relevant and available is a key part.  A stable and reputable manufacturer is assumed to remain in business for years to come and continue producing the chosen board. Public and customer reviews will be used to gauge manufacturer reputability while component production history will be used to gauge product longevity.  

## BUILDABLES OF SUBSYSTEM
This subsystem consists only of the Maduino Zero 4G LTE (SIM7600X) and operating code.  The only connections made are 2 UART connections to the Microcontroller subsystem.  Shown is the pseudo-code for the operating code.  The final form of the code may have parts added and additional functionalities included, but this is the general idea of how the code should flow.  Proceeding from each section is assuming that there are no errors detected indicating a “Success”.  If an error arises, a default handler will need to be called to assess the situation.  It should also be noted that the loop is intended to be theoretically infinite, however, there is an implicit exit at the shutoff button being pushed.  “Timers” refers to physical or software timers that act as a "Watchdog" to prevent the system from hanging on a bad or failed connection. Once a timer is triggered, an interrupt should start and take over to see what is taking so long.  It will then most likely close the connection and return to the loop to try again.
![Psued-Code_Comm](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/Images/Psuedo-code_Comm.JPG)

## ANALYSIS OF CHOSEN COMPONENT(S)
The team has chosen to look at the Maduino Zero 4G LTE(SIM7600X) to fulfill the needs of the communications subsystem.  This component will satisfy the previously listed constraints and jobs of this subsystem.  Following are the corresponding fulfillment of the constraints:
1. The Maduino is able to fully utilize 4G LTE to communicate and transmit data throughout the Internet.  The carrier frequencies are 850 MHz, 1800 MHz, and 1900 MHz which puts it within range of the standard 4G LTE. 
2. There is a slot for a SIM card on the bottom of the component with corresponding connections.
3. With a price of $64.80, it falls under the $100 limit.  Two SD cards will also be purchased for a total of $74.80.  T-Mobile Mobile Internet Access SIM card has a recurring cost of $10.
4. UART is fully supported to allow for data to be receiving from the Microcontroller subsystem.  
5. Two SD cards are used for storage.  The chosen SD will have 8 gigabytes of storage each which is more than enough at a reasonable price.
6. The Maduino supports C and Python with many publicly available libraries. 
7. The SIM7600 series of boards were first introduced in 2018 and more realized in production in 2020, making them newer boards.  MakerFabs, founded in 2015, is a known manufacturing company that has created many variations of PCBA boards.  Their Maduino series is a popular option for wireless connections and is reviewed in detail by many customers positively.  

## BILL OF MATERIALS (BOM)
| Designator | Manufacturer      | Manufactured Part # | Description                                                                                     | Quantity | Price Each |
| ---------- | ----------------  | ------------------- | ----------------------------------------------------------------------------------------------- | -------- | ---------- |
| U1         | Maduino/MakerFabs | OHMZ4G7600          | Maduino Zero 4G LTE (SIM7600A-H) (Cellular Communication Device for Wireless Data Transmission) | 1        | $64.80     |
| U2         | Micro Center      | 16GB SDHC 2PK       | Micro Center 16GB SDHC Class 10 Flash Memory Card 2 Pack (Storage for device)                   | 1        | $9.99      |
| U3         | T-Mobile          | ZZZ260R070          | T-Mobile® SIM Card - 4G - 5G (Prepaid SIM card and data plan for wireless Internet access)      | 1        | $10.00     |

Notes: T-Mobile prepaid SIM cards come in many packages and plans for typical tablets and phones.  We are asking for just the SIM card and data plan for ZIP code 38501.  Sim card pack T-Mobile® SIM Card - 4G - 5G (SKU: ZZZ260R070) with the Mobile Internet Plan: Unlimited Mobile Internet with up to 2GB of 5G & 4G LTE Data for $10.00 per month with $10.00 activation fee covering the first month.
