# Microcontroller Signoff
## FUNCTION OF THE SUBSYSTEM
The microcontroller and its code are responsible for operating, managing, communicating with, maintaining, and collaborating with all of the other subsystems and acts as both the brain and body of the device.  All the data and instructions must flow through the microcontroller giving a common place for all of the data to go and be readily available for whichever subsystem has need of it.  The hardware will be responsible for the actual actions and completion of any given task.  The code will be responsible for controlling the hardware and manipulating data.  This subsystem will be where most of the coding for the project is done as the operating code will be the largest by far.

These jobs require a sufficiently powerful board.  One that has ample storage, plenty of physical space, decent processing power, sufficient support, and none restrictive.  Before choosing components and detailing the design, the specific constraints of the subsystem need to be known and laid out.  Then any potential solutions can be compared to the constraints to test viability and fulfillment of the subsystem’s purpose. 

## CONSTRAINTS ON THE SUBSYSTEM
The subsystem constraints are placed to ensure that it can fulfill its job in a satisfactory manner.  The constraints given below are generalized to allow for comparison of any potential contender for the microcontroller.  Constraints on the subsystem are as follows:
1. With a budget of $300, a super-powered board is not affordable.  The board price ranges between $20-$60.  This range is gathered from estimating the costs of other components and viewing prices of avaiable options that meet the needs of the subsystem.
2. The microcontroller must support communication between components.  To do this, Serial Peripheral Interface (SPI), Universal Asynchronous Receiver/Transmitter (UART), or some form of hardware communication will need to be achievable on the board.  SPI is a synchronous method while UART is an asynchronous method for two devices connected over a short distance to liaise.
3. External storage support is required of this subsystem. The most preferred form of external storage is a Universal Serial Bus (USB) Flash Drive as it is common in households and easily available.
4. A major goal of the project is to allow for synchronous operations of at least 3 air quality sensors.  Sensors may be either analog or digital, so there must be support for both.  The board must have enough Input/Output (I/O) pins to operate any combination of 3 sensors whether they be digital or analog.   Different sensors interface with a potentially different number of pins.  Preliminary research shows that a sensor may take up to 5 pins to operate.  Other sensors may have more, but it is more common for 5 and under.  This means the board must have at least 15 digital input pins and 15 analog input pins.
5. The cpu clock speed does not need to be very fast.  The code will be mostly Input/Output heavy with less computation.  This means that there will be a lot of waiting for responses and does not require a high-speed processor.  A cpu clock speed of at least 1 MHz is preferred for fast bootup.  Cpu's over 1 MHz are very common and just provides a reliable speed for what computation is present.
6. There must be sufficient memory for the code.  It is unknown how much memory the code will occupy.  Comparing similar operating code with libraries and compilation show slightly over or under 150 KB (Kilobytes) in Flash/Disk/Storage.  To account for the worst case, the board will need over 150 KB.
7. The power requirements of the board need to be reasonably under or near 240 mW.  Here, we take a voltage supply of 12 V and current of 20 mA to get 240 mW.  12 V with 20 mA is from the power subsystem’s output to provide an adequate operation time or lifespan and not damaged components.  Going over 240 mW could risk draining the battery too quickly.
8. Some form of battery monitoring capabilities need to be included or applicable.  
9. The board itself cannot be too big.  “Too big” here is defined as having a volume greater than 50 cubic inches.  This size was set to prevent the device from proving too large.  50 cubic inches would be about the size of a small novella/book.  .  
10. The manufacturer needs to be a reputable and safe choice.  A stable manufacturere that is assumed to remain in business for years to come and continue producing the chosen board is a necessecity.  This project aims for replicability, so a board that remains relevant and available is a key part.
11. The board will need to have coding language support for C and or Python.  Support for both is preferred for options and coverage but not required.  It is expected that the users will have some degree of coding experience and may potentially personalize or improve upon the code. These languages are chosen due to popularity and performance.  C, in particular, is predicted to be very desirable for this project.

## BUILDABLE SCHEMATIC OF SUBSYSTEM
Shown is the pseudo-code for the operating code.  The final form of the code may have parts added and additional functionalities included, but this is the general idea of how the code should flow.  Proceeding from each section is assuming that there are no errors detected indicating a “Success”.  If an error arises, a default handler will need to be called to assess the situation.  It should also be noted that the loop is intended to be theoretically infinite, however, there are explicit and implicit breaks at the battery running critically low (explicit) and the shutoff button being pushed (implicit).  “Timers” refer to either physical hardware or coded timers that go off to alert the system that the sensor(s) sampling is ready.

![pseudo code 2](https://user-images.githubusercontent.com/110966922/202583040-c28e27fe-c175-4287-a8cb-cefafbfe327b.png)

Shown is a schematic of the Arduino Mega 2560 Rev 3.
![CAPSTONE I Shematic Checkpoint 1](https://user-images.githubusercontent.com/110966922/202655081-0386ed76-3795-4ab5-98af-ee23ff0b19f6.png)

## ANALYSIS OF CHOSEN COMPONENT(S)
The team has chosen to look at the Arduino Mega 2560 Rev 3 and Arduino USB Shield Host as the solutions.  The Arduino Mega is a larger and more powerful version of the Arduino Uno with much more storage, memory, and I/O pins.  The USB Shield is a breakout board or additional component that connects to the Arduino Mega to allow for USB devices to be implemented and utilized.  These components, in conjunction, will satisfy the constraints and jobs of this subsystem.  Following are the corresponding fulfillment of the constraints:

1. The Arduino Mega 2560 Rev 3 falls within the preferred range of $20-$60 at a current price of $48.40 (as of 11-8-22).  The USB Host Shield component has a price of $20.99 as of the same date.  The USB Host Shield will provide easy access to external storage as needed by the related shall statement.  The Arduino Mega does not have a USB port by default, so the additional component is needed. 
2. 4 UART serial hardware ports are present on the board.  SPI is supported as well with included libraries.  As an alternative later, Two-Wire Interface (TWI) is also supported.  These enable the Mega to issue instructions and exchange data between other components and subsystems.
3. There are 54 digital input/output pins (of which 15 are PWM outputs) and 16 analog inputs.  This meets the needs for at least 15 of each (digital and analog input pins).  The other 24 digital pins may also be assigned special purposes, so the excess will be used.  
4. The cpu clock speed is 16 MHz, which is significantly faster than 1 MHz.
5. The code is currently of an unknown size, so it is necessary to aim slightly higher in terms of needed processing memory.  The Arduino Mega has 256 KB of Flash, 8 KB of SRAM, and 4 KB of EEPROM.  The SRAM being bigger would be nice, but the Flash memory is satisfactory for the subsystem’s needs.
6. Recommended voltage of 7-12 V and a current draw of 20 mA puts the Mega near the target power draw of 240 mW.  This should prove to not be too power hungry and help to meet some of the operational time specifications of the project.
7. Algorithmic measurement of the battery life is supported.  This is as the board will be able to read the voltage levels coming from the battery and run an algorithm based on the battery’s expected output to determine the battery’s capacity.
8. Physically, the board is slightly bigger when compared to the other boards, but the extra space to support other components.  The board has a length of 4 inches and width of 2.1 inches with less than an inch in height.  This does put it below the volume cap.
9. Arduino is a very popular and respected manufacturing and electronics design company.  They were established in 2005 and have had a lot of support throughout the years.  It is expected for them to persist for quite some time.
10. The Arduino Mega supports C and Assembly for certain.  It could even be said that there is a favor for C when it comes to coding Arduino boards.  Arduino does have Python support as well and can potentially be used to accomplish the goals of this project or allow for the code to be translated from C to Python later on for whatever reason may arise from this team or another.

	
Arduino has been used for many, many projects in history and has a good track record.  The Arduino Mega and USB Host Shield have conjointly shown to fulfill the needs of this subsystem.  

## BILL OF MATERIALS (BOM)

| Designator | Manufacturer | Manufactured Part # | Description                                                   | Quantity | Price Each  |
| ---------- | ------------ | ------------------- | ------------------------------------------------------------- | -------- | ----------  |
| U1         | Arduino      | A000067             | Arduino Mega 2560 Rev3 (Master Controller for User Interface) |1         | $48.40      |
| U2         | Arduino      | A000004             | Arduino USB Host Shield (Storage PCB)                         |1         | $15.00      |
