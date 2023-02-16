# Web and Wireless Signoff
## FUNCTION OF THE SUBSYSTEM

The Wireless acquisition of data helps effortlessly boost the quality of life. The functionality can be broken into a couple of parts: the server, storage, and user interface (UI). The server accepts data from the device and stores it for remote access from the user. The data will be stored on a server host machine. The UI is what the user sees when attempting to read the data collected from the device. The UI helps get the data to the user in an understandable manner.

## CONSTRAINTS ON THE SUBSYSTEM

The subsystem constraints are placed to ensure that it can fulfill its job in a satisfactory manner. Constraints on the subsystem are as follows:
1. The server host machine must possess adequate storage space for the server code to store all collected data.
2. The data will be encrypted and decrypted with an undisclosed algorithm using AES Symmetric Encryption.  
3. The server must be able to be established and connected to the internet.
4. The server must have adequate storage for user data.
5. The data received must be in legible format.


## BUILDABLE SCHEMATIC OF SUBSYSTEM

<img width="350" alt="4G Connection" src="https://user-images.githubusercontent.com/110966922/219462337-5e72409b-17d1-4c59-8d68-eab86c8fda1f.png">
<img width="432" alt="Wifi Connection" src="https://user-images.githubusercontent.com/110966922/219462340-b16763c0-cbe4-4803-ba0f-be77fbb212e4.png">


Server will be made using HTML. It will receive info from TCP Connection provided from UART. 

## ANALYSIS OF CHOSEN COMPONENT(S)

N/A

## BILL OF MATERIALS (BOM)

N/A

## References
1. https://www.unitrends.com/blog/data-encryption#:~:text=A%20key%20is%20used%20to,physical%20access%20to%20the%20device.

2. https://www.hivemq.com/blog/mqtt-vs-http-protocols-in-iot-iiot/#:~:text=They%20both%20run%20over%20TCP,respond%20to%20requests%20from%20clients.

3. https://circuitdigest.com/microcontroller-projects/sending-arduino-data-to-webpage
