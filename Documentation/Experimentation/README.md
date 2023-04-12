# Experimentation
## Layout
All experimentation can be found under Documentation to Experimentation folder.  Experiments are sectioned into separate files targeting the subsystem they are most closely related to.  Each file's heading will contain the experiments performed and not performed regarding that subsystem.  Some additional notes on experiments not conducted can be found below.

Experimental Format:
1. The test description and what is being tested with how.
2. The test results in the form of a table or graph
3. Analysis of the results and consideration of their limitations on the design

## Goals and Fulfillments
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

