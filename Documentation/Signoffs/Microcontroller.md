# Microcontroller Signoff
## FUNCTION OF THE SUBSYSTEM
Within this subsystem, the code will instruct the hardware in how to sample from the sensors, send data to the Communication subsystem, format and store data onto a USB Flash drive, and take readings from the power subsystem.  These are the core functions that are desired from the microcontroller.  

## CONSTRAINTS ON THE SUBSYSTEM
Constraints on the subsystem are as follows:
1. The chosen microcontroller should cost no more than $60 as the end-user only has a budget of $300.  This board value cap is gathered from estimating the costs of other subsystems and viewing prices of available options that satisfy proceeding constraints such as Raspberry Pis, Arduinos, Intel, ESP, etc.  Up to 20% of the budget was then allocated due to the importance of this subsystem.
2. The microcontroller must be able to send instructions and transfer data to other components such as the Communication subsystem.  To do this, Universal Asynchronous Receiver/Transmitter [11] (UART) (2 UART pins) as a standard in hardware communication for liaising will need to be achievable. 
3. USB Flash Drive external storage support is required as per the shall statements. The USB standard is used for convenience for the user as it is small, easily portable, commonly used for data storage, and readily available.
4. The board must have at least 15 digital input pins and 16 analog input pins. This allows the board to have enough Input/Output (I/O) pins to operate any combination of 3 sensors whether they be digital or analog. Different sensors interface with a potentially different number of pins; preliminary research shows most air quality sensors take 5 of fewer pins to operate, so 5 pins per sensor times 3 sensors gives 15 pins. 2 analog/digital pins will be used to read voltage/current from the power subsystem to monitor battery capacity with 1 analog pin for continuous.  It must have 2 UART pins for UART.
5. There must be sufficient memory for the code. Comparing similar operating code (Wireless Sensor Collection and Small-time Process Operating) with libraries and compilation show a range of 15 KB (10%) (Kilobytes) above or below 150 KB in flash memory.  To account for the worst case, 165 KB is the required memory.
6.  This project aims for replicability, so a board that remains relevant and available is a key part. The manufacturer needs to be a reputable and safe choice.  A stable and reputable manufacturer is assumed to remain in business for years to come and continue producing the chosen board. Public and customer reviews will be used to gauge manufacturer reputability while board production history will be used to gauge product longevity.
7. The board will need to have coding language support for C and/or Python.  At least one must be supported. These languages are chosen due to popularity, online support, and performance.  This helps create a wider web of coverage for end-users being at least relatively experienced with coding and engineering concepts.

## BUILDABLE SCHEMATIC OF SUBSYSTEM
Shown is the pseudo-code for the operating code.  If an error arises, a default handler will need to be called to assess the situation.  It should also be noted that the loop is intended to be theoretically infinite, however, there are explicit and implicit breaks at the battery running critically low (explicit) and the shutoff button being pushed (implicit).  “Timers” refer to either physical hardware or coded timers that go off to alert the system that the sensor(s) sampling is ready.

![pseudo code 2](https://user-images.githubusercontent.com/110966922/202583040-c28e27fe-c175-4287-a8cb-cefafbfe327b.png)

Shown is a schematic of the Arduino Mega 2560 Rev 3 and USB Host Shield:
![CAPSTONE 1 Microcontroller Schematic Updated](https://user-images.githubusercontent.com/118767661/206057697-6be6d265-4ac2-411e-a632-a95b974fea32.png)

## ANALYSIS OF CHOSEN COMPONENT(S)
The team has chosen the Arduino Mega 2560 Rev 3 and Arduino USB Host Shield as the solutions.  These components, in conjunction, will satisfy the constraints and jobs of this subsystem.  Following are the corresponding fulfillment of the constraints:

1. The Arduino Mega 2560 Rev 3 falls under the preferred maximum of $60 at a current price of $48.40 (as of 11-8-22).  The USB Host Shield component has a price of $20.99 as of the same date.   
2. 4 UART serial hardware ports are present which is more than the constraint value of 2.
3. The USB Host Shield enables the use of USB devices such as a Flash drive for external storage and communication. 
4. There are 54 digital input/output pins (of which 15 are PWM outputs) and 16 analog inputs.  This meets the needs for at least 18 digital (15 for sensors and 3 for USB Host) and 16 analog input pins.  There are also 4 UART pins and 21 digital (2 for battery monitoring discretely) may be assigned special purposes later on in design.  1 analog pin may also be used for taking a continuous measurement for the battery monitoring.
5. The Arduino Mega has 256 KB of Flash, 8 KB of SRAM, and 4 KB of EEPROM.  The SRAM and Flash memory are satisfactory for the subsystem’s needs.
6. The Arduino Mega 2560 was released in 2010 and has been in production ever since [1].  The Mega is used in more demanding projects, such as this one, and has received good reception [2] [3] [4]. No announcements of replacements or discontinuations have been made regarding the Mega 2560.  Arduino was established in 2005 and have had much support throughout the years becoming a popular and respected manufacturing and electronics design company [5] [6] [7].  
7. The Arduino Mega supports C [8] and Python [9] with a generous amount of libraries and code support [10].

	
Arduino has been used for many, many projects in history and has a good track record.  The Arduino Mega and USB Host Shield have conjointly shown to fulfill the needs of this subsystem.  

## BILL OF MATERIALS (BOM)

| Designator | Manufacturer | Manufactured Part # | Description                                                   | Quantity | Price Each  |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------- | -------- | ----------  |
| U1         | Arduino      | A000067             | Arduino Mega 2560 Rev3 (Master Controller for User Interface) | 1        | $48.40      |
| U2         | Arduino      | A000004             | Arduino USB Host Shield (Storage PCB)                         | 1        | $20.99      |


## References
1. Wikipedia, free online encyclopedia, "List of Arduino boards and compatible systems," https://en.wikipedia.org/wiki/List_of_Arduino_boards_and_compatible_systems  (Accessed on 12-8-22).
2. Blom, Jim, SparkFun Electronics, Electronics Designers, Retailers, and Critiques, "Arduino Comparison Guide," https://learn.sparkfun.com/tutorials/arduino-comparison-guide  (Accessed on 12-8-22).
3. Pedamkar, Priya, EDUCBA, Skill Based Educational and Tutorial Services, "Arduino Mega vs Uno," https://www.educba.com/arduino-mega-vs-uno (Accessed on 12-8-22).
4. Element14, Provides Tutorials, Reviews, and Discussion Blogs For Engineers and Designers, "Review of Arduino Mega 2560," https://community.element14.com/products/roadtest/rv/roadtest_reviews/1068/review_of_arduino_me  (Accessed on 12-8-22).
5. G2, Software Peer Review and Marketplace, "Arduino IDE Reviews & Product Details," https://www.g2.com/products/arduino-ide/reviews (Accessed on 12-8-22).
6. Arduino, Electronics and Software Manufacturers, "About Arduino," https://www.arduino.cc/en/about (Accessed on 12-8-22).
7. Kushner, David, IEEE Spectrum, Largest Technical Professional Organization, "The Making of Arduino," https://spectrum.ieee.org/the-making-of-arduino (Accessed on 12-8-22).
8. CPlusPlus, Archive of the C, C#, and C++ Programming Language, "C-Library," https://cplusplus.com/reference/clibrary (Accessed on 12-8-22).
9. Python, Archive of Python Programming Language, "Arduino-Python3 Command API," https://pypi.org/project/arduino-python3/ (Accessed on 12-8-22).
10. Arduino, Electronics and Software Manufacturers, "Libraries - Arduino," https://www.arduino.cc/reference/en/libraries/ (Accessed on 12-8-22).
11. Texas Instruments, Electrical Design and Semiconductor Production Company, "Universal Asynchronous Receiver/Transmitter (UART)," https://www.ti.com/lit/ug/sprugp1/sprugp1.pdf?ts=1670532165815&ref_url=https%253A%252F%252Fwww.google.com%252F (Accessed on 12-8-22).
12. Pena, Eric, Analog Dialogue, Technical Magazine, "UART: A Hardware Communication Protocol Understanding Universal Asynchronous Receiver/Transmitter," https://www.analog.com/en/analog-dialogue/articles/uart-a-hardware-communication-protocol.html (Accessed on 12-8-22).
