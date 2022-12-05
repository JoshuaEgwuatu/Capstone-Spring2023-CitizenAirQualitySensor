# Microcontroller Signoff
## FUNCTION OF THE SUBSYSTEM
The microcontroller and its code are for operating, managing, communicating with, maintaining, and collaborating with all of the other subsystems and acts as both the brain and body of the device.  All the data and instructions will through the microcontroller making it especially important to complete first and giving it a high level of importance.  The hardware will be responsible for the actual actions and completion of any given task.  The code will be responsible for controlling and giving the hardware tasks and manipulating data throughout the system and device.  

Within this subsystem, the code will instruct the hardware in how to sample from the sensors, send data to the Communication subsystem, store data onto a USB Flash drive, and monitor battery voltage levels for the user.  These are the core functions that are desired from the microcontroller.  The microcontroller must be a reasonable portion of the end-user's budget of $300.

## CONSTRAINTS ON THE SUBSYSTEM
The constraints given below are generalized to allow for comparison of any potential contender for the microcontroller.  Constraints on the subsystem are as follows:
1. The chosen microcontroller should cost no more than $60 as the end-user only has a budget of $300.  This board value cap is gathered from estimating the costs of other subsystems and viewing prices of available options such as Raspberry Pis, Arduinos, Intel, ESP, etc.  Up to 20% of the budget was then allocated due to the importance of this subsystem.
2. The microcontroller must be able to send instructions and transfer data to other components such as the Communication subsystem.  To do this, Serial Peripheral Interface (SPI) or Universal Asynchronous Receiver/Transmitter (UART) as standards in hardware communication for liaising will need to be achievable. 
3. USB Flash Drive external storage support is required as per the shall statements. The USB standard is used for convenience from the end user as it is small, easily portable, and very commonly used for data transfer.
4. The board must have at least 15 digital input pins and 15 analog input pins. A major goal of the project is to allow for synchronous operations of at least 3 air quality sensors.  Sensors may be either analog or digital, so there must be support for both.  The board must have enough Input/Output (I/O) pins to operate any combination of 3 sensors whether they be digital or analog. Different sensors interface with a potentially different number of pins.  Preliminary research shows that a sensor may take up to 5 pins to operate, so 5 pins times 3 sensors gives 15 pins. Other sensors may have more, but it is more common for 5 and under.  
5. There must be sufficient memory for the code. Comparing similar operating code (Wireless Sensor Collection and Small-time Process Operating) with libraries and compilation show a range of 15 KB (10%) (Kilobytes) above or below 150 KB in flash memory.  To account for the worst case, 165 KB is the required memory.
6. Some form of battery monitoring capabilities need to be included or applicable as per shall statements.
7. The manufacturer needs to be a reputable and safe choice.  A stable manufacturer is assumed to remain in business for years to come and continue producing the chosen board is a necessity.  This project aims for replicability, so a board that remains relevant and available is a key part.  Public and customer reviews will be used to gauge reputability.
8. The board will need to have coding language support for C and/or Python.  At least one must be supported. These languages are chosen due to popularity, online support, and performance.  This helps create a wider web of coverage for end-users being at least relatively experienced with coding and engineering concepts.

## BUILDABLE SCHEMATIC OF SUBSYSTEM
Shown is the pseudo-code for the operating code.  The final form of the code may have parts added and additional functionalities included, but this is the general idea of how the code should flow.  Proceeding from each section is assuming that there are no errors detected indicating a “Success”.  If an error arises, a default handler will need to be called to assess the situation.  It should also be noted that the loop is intended to be theoretically infinite, however, there are explicit and implicit breaks at the battery running critically low (explicit) and the shutoff button being pushed (implicit).  “Timers” refer to either physical hardware or coded timers that go off to alert the system that the sensor(s) sampling is ready.

![pseudo code 2](https://user-images.githubusercontent.com/110966922/202583040-c28e27fe-c175-4287-a8cb-cefafbfe327b.png)

Shown is a schematic of the Arduino Mega 2560 Rev 3.
![CAPSTONE 1 Microcontroller Schematic](https://user-images.githubusercontent.com/118767661/204694703-fcaa5b67-bf5d-469f-a134-dae06493fe5f.png)

## ANALYSIS OF CHOSEN COMPONENT(S)
The team has chosen to look at the Arduino Mega 2560 Rev 3 and Arduino USB Shield Host as the solutions.  These components, in conjunction, will satisfy the constraints and jobs of this subsystem.  Following are the corresponding fulfillment of the constraints:

1. The Arduino Mega 2560 Rev 3 falls within the preferred range of $20-$60 at a current price of $48.40 (as of 11-8-22).  The USB Host Shield component has a price of $20.99 as of the same date.   
2. 4 UART serial hardware ports are present on the board.  SPI is supported as well with included libraries.  As an alternative later, Two-Wire Interface (TWI) is also supported.  These enable the Mega to issue instructions and exchange data between other components and subsystems (Communication).
3. The USB Host Shield enables the use of USB devices such as a Flash drive for external storage and communication. The Arduino Mega does not support USB as a standalone component.
4. There are 54 digital input/output pins (of which 15 are PWM outputs) and 16 analog inputs.  This meets the needs for at least 15 of each (digital and analog input pins).  The other 24 digital pins may also be assigned special purposes, so the excess will be used.  
5. The code is currently of an unknown size, so it is necessary to aim slightly higher in terms of needed processing memory.  The Arduino Mega has 256 KB of Flash, 8 KB of SRAM, and 4 KB of EEPROM.  The SRAM and Flash memory are satisfactory for the subsystem’s needs.
6. Algorithmic measurement of the battery life is supported.  The board will be able to read the voltage levels coming from the battery by taking a reading from a voltage divider located in the power subsystem.  This reading can then be used as a reference initially and then measured against the incoming voltage from said point continuously. Running an algorithm based on the battery’s expected output vs current output will determine the battery’s capacity.
7. Arduino is a very popular and respected manufacturing and electronics design company.  They were established in 2005 and have had a lot of support throughout the years.  It is expected for them to persist for quite some time. 
8. The Arduino Mega supports C and Python with a generous amount of libraries and code support.

	
Arduino has been used for many, many projects in history and has a good track record.  The Arduino Mega and USB Host Shield have conjointly shown to fulfill the needs of this subsystem.  

## BILL OF MATERIALS (BOM)

| Designator | Manufacturer | Manufactured Part # | Description                                                   | Quantity | Price Each  |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------- | -------- | ----------  |
| U1         | Arduino      | A000067             | Arduino Mega 2560 Rev3 (Master Controller for User Interface) | 1        | $48.40      |
| U2         | Arduino      | A000004             | Arduino USB Host Shield (Storage PCB)                         | 1        | $20.99      |
