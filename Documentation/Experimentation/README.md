# Experimentation
## Layout
All experimentation can be found under Documentation to Experimentation folder.  Experiments are sectioned into separate files targeting the subsystem they are most closely related to.  Each file's heading will contain the experiments performed and not performed regarding that subsystem.  Some additional notes on experiments not conducted can be found below.

Experimental Format:
1. The test description and what is being tested with how.
2. The test results in the form of a table or graph
3. Analysis of the results and consideration of their limitations on the design

## Project Goals and Fulfillments
The design has undergone considerable changes throughout its development.  There were many ambitious features that were hoped to be implemented in this iteration.  One of the biggest problems we faced was ordering parts which is naturally essential for experimentation.  In the Project Proposal, there was a list of shall statements that describe the idealized final product.  At the time of writing, here are the current beliefs about the shall statements of the project:
* Shall have a selection of tested and approved air quality sensors.
  * Due to problems with ordering, air quality sensors were never obtained.  These have had to be supplemented with other kinds of sensors.  Interfacing with an air quality sensor would not be a general issue, so the substitution is simply a change in what is being measured.
* Shall be easily replicable.
  * So far, all design aspects are available in this GitHub repository for the public.  All code and schematics for reaching above minimally functional are ready for replication.  The team has remained with off-the-shelf purchases of items that are also readily available in the open market.
* Shall be relatively cost-effective. with a budget of $300.
  * Searching through the Bill of Materials for each subsystem (excluding Sensors as descriibed in Shall statement), the total comes to $278.75 for purchasing every option.
* Shall be protected against the environment.
  * There is not currently a chasis that has been specified for purchase.  The idea is for a generic outdoors electrical enclosure to protect the electrical components.  Small holes will need to be located in a waterproof location on the box.  The team is currently investigating an open 3D printed model to place in the GitHub.  This model would be molded for the current iteration of the device.  However, neither option has been established as a definite.
* Shall be modular.
  * The current design does include many modular components: Wi-Fi, 4G, solar power, battery power, mains power, analog sensing, digital sensing, and a decently wide range of voltage tolerance for sensors to be placed.  Analog sensors even have the ability to be hot-swapped.  Digital sensors require software changes to be swapped for another.
* Shall utilize interchangeable sensors.
  * The sensors are able to interchanged with others.  Analog sensors even have the ability to be hot-swapped.  Digital sensors require software changes to be swapped for another.  Sensors have not been categorized into sampling groups due to a lack of anticipated sensors.
* Shall be able to operate with at least 3 sensors simultaneously.
  * The current iteration is able to reading from a set of digital sensors measuring gyroscopic data, temperature, and acceleration as well as an analog sensor measuring distance.  More analog sensors may be registered with ease.  Digital sensors are able to be registered with some work and understanding the data transmission from the digital sensor.
* Shall have easily accessible data.
  * Half of this statement has been met at the time of writing.  The wireless website is still under development having seen many drastic changes and shifts throughout the project.  Physical retrieval of data from the device itself has been implemented.  A user can simply plug in a regular FAT32 USB flash drive and return later with data stored safely on the flash drive. 
* Shall have a set of security measures to protect the device and its data.
  * There are no such security measures in place.
* Shall have an independent power source.
  * Development has reached the point of having several options of power sources/supplies.  Options are battery, mains, solar, battery and solar, or battery and mains.

## Subsystem Goals and Fulfillments

### Communication
The Communication subsystem has seen much success in fulfilling its constraints. Experimentation really targets the limitations on the device's ability to communicate as many of the constraints listed in the signoff are binary answers.

What has been done:
* The device is able to connect to local Wi-Fi and access the Internet.
* The ESP8266 for Wi-Fi is within budget at $7.99.
* The ESP8266 is able to receive instructions from the Microntroller through the UART.
* ESP8266 is an extremely popular product and is still in production.

What has not been done:
* All 4G contraints have not been met.  This is done intentionally as it was expected to exceed our workload with the time we were given to develop.  The 4G capabilites are possible with the specified components but are not implemented.
* Error handling has not been implemented.  The idea was for the software to have a way to attempt to fix itself or run diagnostic tests on a network connection to determine what to do.  The code is running on interrupt driven programming, but the additional routines have not been developed.

### Interface
The Interace subsystem is able to fulfill each of its constraints. The experiments target the values present in the circuit given various inputs.  The goal being to insure the scaling of the input to a desired output for safe usage for the Microcontroller.

What has been done:
* The circuit is able to scale the following sensor output voltage signal ranges to 0 V to 5 V: 0 V to 3 V, 0 V to 10 V, -10 V to +10 V, -5 V to +5 V.
* The circuit is able to convert a sensor output current signal of 4 to 20 mA to a voltage signal of 1 to 5 V.
* Comprised components are non-toxic and abide by RoHS.
* The circuit does not draw more current than the Power system can provide.



### Power
Currently testing.

### Microcontroller
The Arduino Mega 2560 has proven to be an apt choice for the project.  Many of the constraints have been fulfilled and are ready.  There is still much room for improvement and quality of life fixes.  Many of the constraints are binary, therefore, experimentation targets some of the limitations of the Mega regarding the current software design.  The goal being to find limiting factors and refactor the software with the results in mind.  The idea being that knowing how far the Mega can be pushed will help to understand what can be done in given amount of time.

What has been done:
* The Arduino Mega 2560 is within budget at $48.40.
* The Mega is able to instruct the USB Host Shield and ESP8266.  Although we intended for both to be done using UART, we ended up using some SPI for the connections made to the USB Host Shield.
* The Mega and USB Host Shield are able to log all collected data in a USB FAT32 flash drive.  There is actually a couple experiments targeting the limitations of the USB Host Shield.
* The Mega has an apparent abundance of pins available for use.
* We had projections for the code to take up quite a bit of room in memory.  The current version of the code only uses around 13% of the Mega's memory, so there is plenty to spare as expected.  Larger and more in-depth libraries are still able to be included for future improvements.
* The Mega is widely popular and readily available in the open-market.
* The entirety of the code is written using C++.

What has not been done:
* The code is interrupt driven, however, it does not have all the features that were hoped for.  There is no error handling.  There is not a feature for measuring the battery capacity.  The idea was to check the battery capacity every so often to guage whether or not the Arduino should enter a sleep mode to protect its data.  Although the sleep mode is being developed, it is not ready for publishing.

### Sensor
Currently testing.

### Web & Wireless
Due to time constraints and unforeseen problems with the Web & Wireless subsystem, only certain features are available.  These features either work or don't work so is suffices just to see if the feature works as intended.  The point of the Web & Wireless subsystem was to allow for remote access to the data via a website hosted by a deployable server.  This option has not been entirely abandoned but altered.  Now, the server aspect has been changed to be utilize public Google Services running a Google Script.  The data is stored onto a Google spreadsheet.  This can be accessed by anyone with the link and permission to the Google Sheets.  The website has been turned into a Google Site that contains the Google Sheets inside it.  This allows anyone with the link to view the data as a regular website.  
This has actually turned into a pleasant replacement for the original plans, but it still lacks some things.

What has been done:
* A website
  * Anyone with a Google account is able to create a super simple Google Site and link it to the Google Sheets for website access.  Otherwise, the Google Sheets can be accessed directly.  The Google Site shows a screenshot of the data received from the data.
* Graphical displays
  * Google Sheets inherently has built-in graphical options such as charts, graphs, plots, or diagrams.  
* Data display
  * The data is displayed in a spreadsheet and can be very easily read.  It is static on the website but dynamic on the Google Sheet.

What has not been done:
* Central server
  * There is not a central or default server that is accessible from anyone attempting to use the project for research.  Since there is not default server, there is also not a layer of security for the non-existant accounts or data.
* Deployable server
  * Although anyone can make a Google account, it still relies entirely on Google.  Independence is gone.
* Dynamic data display
  * Data displayed on the website is a static screenshot of whatever the data was in that moment.  It will not change.  The data displayed on the Google Sheets is dynamic however.  As a side note, Google Sheets has the benefit of easy chart and graphical creation.
* Fast sampling fix
  * Google has a limit on how many POST requests are allowed in a set timeframe.  This means that if the data is to be accessed remotely, the device must limit itself to a sample rate of once every five seconds.  The device needs to delay itself in order to not flood Google with POST requests that will inevitably get rejected.  A potential fix could be to increase the sample rate to the desired 2 Hz and store the data in a buffer.  Once five seconds has passed, the entire buffer could be sent to try to simulate 2 Hz sampling.  The device would then reset the buffer and begin filling it back up.  Sending a bigger POST request instead of the many small ones.
