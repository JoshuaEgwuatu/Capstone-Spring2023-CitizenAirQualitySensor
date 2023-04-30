# Citizen Air Quality Sensor

## Executive Summary

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; The goal of this project was a replicable device that accepts and operates multiple air quality sensors independently with a selection of interchangeable sensor options for local data collection.  Air quality is vital to maintaining life on Earth.  Poor air quality can result in a slew of health problems such as heart disease and lung cancer.  In the modern age, humanity pushes the levels of pollution in the world to unprecedented levels as compared to the pre-industrial era.  This pollution affects the very air that all living things rely on to survive.  This perspective on the negative repercussions of polluting the air and Earth is what led to this team’s proposition of a device that allows everyday citizens to see what pollutants blight their communities.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; There are already services that exist to alleviate this problem, however, the services do not fulfill the solution to a high degree.  The biggest of these services would be the Air Quality Index (AQI) provided by the United States Environmental Protection Agency.  The AQI takes in data from sensors placed systematically all across the country and in highly populated areas.  This data is then aggregated together to fill in any regions that were not explicitly sampled from a sensor directly.  The issue derives from that last sentence.  Because it is not reasonable or cost-effective for these services to place sensors everywhere, the readings that are received from these sensors may not be accurate in any given place.  For a community wanting a detailed view into the air quality of their chosen area, they would require more concrete sources of data.  It is here where the team’s proposed device comes in to provide an easy-to-use, solar-powered, easily replicable, and low-cost modular system that uses multiple sensors to gather data on different pollutants.



## Capabilities

1. Data Acquisition Through USB Or Wirelessly Through The Internet
2. Modular Sensor Design
3. Optional Self-Powering Modules Using Battery/Solar
4. Dynamically update a Google Sheet with current sensor values
 


## Salient Outcomes

### Internet Access:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  The original plan for accessing the Internet has remained the same, however, the implementation has changed.  Utilizing 3G GSM would provide national coverage.  The development here was that all major cellular service providers have been phasing out 3G support throughout the year of 2022.  This obviously proved a great concern as the initial design of the Communication subsystem was designed with 3G in mind.  The original design did not allow for anything else.  An upgrade to 4G was necessary and called for an entirely new component.

### Modularity:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  Modularity has been a core design concept from the beginning.  The system design incorporates this philosophy in many aspects and subsystems.  A project with this level of interchangeable parts and optional configurations has never been attempted by members of the team.  The team is eager to see this project flourish and see numerous options covering a wide range of locations and uses.

### Citizen Science 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  Dr. Austen has presented an admirable goal and intriguing future for this project.  His vision has a future where this proposed device is improved by numerous teams and utilized in small communities to spread awareness of air quality concerns and the health risks that can arise from poor conditions.  People and companies use this design as foundation for their own projects.  This team is happy to pursue this vision and see it fulfilled.

## Project Photos and Video

### Original Box Exterior
![Box1Exterior2.jpg](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/ProjectPhotos/JPGVersions/Box1Exterior2.jpg)

### New Box Exterior
![Box2Exterior.jpg](https://github.com/JoshuaEgwuatu/Capstone-Spring2023-CitizenAirQualitySensor/blob/main/Documentation/ProjectPhotos/JPGVersions/Box2Exterior.jpg)

### Device In Operation Video
[Click Here To Go To YouTube Demonstration]()

## About Us

### Team

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; All of the members on the team have studied over various circuits and how to implement them to do what the developer wants it to.  Members include: 
Cameron Smith is a computer engineer who is heading the communication subsystem
Kaleb Irwin is an electrical engineer who is designing the power subystem
Alejandro Moore is an electrical engineer in charge of the sensor subystem
Marvo Odds is an electrical engineer managing interfacing between components and sensors
Joshua Egwuatu is an electrical engineer leading the web subsystem.  

### Faculty Supervisor
The supervisor and customer for this project is Dr. Jeffrey Austin.  He is overseeing the design process made by the team and also providing the end-goal desires of the device.

### Stakeholders
The customer for this product is also the same person, Dr. Jeffrey Austin. Another stakeholder within this course is our professor, Mr. Jessie Roberts. The team will be in contact with both professors as we proceed within the design.


## Repo Organization

### Reports
The reports will consist of a Project Proposal, Conceptual Design, Minimal Functionality, Project Poster, and Presentations. Proposal and Design cover analysis and contraints of the system.

### Documentation
Signoffs, Schematics, 3D Models, Images/Photos, and Final Bill of Materials.  Signoffs cover analysis and contraints of individual subsystems.

### Software
The Pseudo Code and other Software components for the project will be placed in Software. Each code directory contains a README that details a description, functions of the code, dependences, and how to install.
