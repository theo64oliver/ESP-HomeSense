# Step 1: How to use all devices

## Board architecture:
- ESP8266
- Carrier Board
- Grove - Temperature & Humidity Sensor (DHT11)
- Grove - Chainable RGB LED
- Grove - 16x2 LCD
- Grove - Light Sensor
- Grove - Button

(TODO add refs!!!!!!!!!!!)

## Work Done:

For this third part, here is how the system should behave:
- Create a WebClient that sends requests to a server. (That will later be the backend of our system)
- Create a WebServer that will handle requests from the backend. These requests are:
  - Get the current temperature and humidity values.
  - Get the current luminosity value.
  - Get the current state of the button (pressed or not).
  - Switch on a led (or switch it off).
  - Display things on the LCD.
  - Change the threshold for the luminosity sensor.
  - Change the threshold for the humidity sensor.

(TODO how do we handle the current sensor values)

All of those endpoints are implemented to handle more devices in the future. They all have identifiers to distinguish between different devices. (For the moment limited to one device of each type quoted above)

## HTTP Endpoints:
- `/lcd/{id}/{line}` : Displays things on the LCD.
- `/led/{id}/{state}` : Switches on the led (or switches it off).
- `/humidity_threshold/{value}` : Changes the threshold for the humidity sensor.
- `/luminosity_threshold/{value}` : Changes the threshold for the luminosity sensor.

## MQTT subscription:
(TODO pub subs)

## Remarks:
Two alternatives were proposed for the implementation of a server on the ESP8266:

https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/server-examples.html
AND
https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer

Advantages of the first one:
- Already included in the ESP8266 core library, no need to install anything else.
- Already used for the Wifi module

Disadvantages of the first one:
- No endpoint creation possible, only one endpoint is available. (http://{ip}/)

Size comparison:
![before](./images/size_with_wifi_lib.png)
![after](./images/size_with_web_server_lib.png)

After this comparison, we decided to use the second library (ESP8266WebServer) for the server implementation. That allowed us to create endpoints properly and have a clean implementation.

## How to use:
1. Install the required libraries in your Arduino IDE (see below).
2. Connect the devices to the carrier board.
3. Upload the code to your ESP8266 board.
4. Open the Serial Monitor to see the output from the temperature and humidity sensor.
5. Play with the sensors to see the full behaviour of the system.

### Useful docs:

- Temperature and humidity sensor: https://wiki.seeedstudio.com/GroveTemperatureAndHumidity_Sensor
- LED : https://wiki.seeedstudio.com/Grove-Chainable_RGB_LED/
- LCD : https://wiki.seeedstudio.com/Grove-16x2_LCD_Series
- Capteur de luminosité : veuillez télécharger la bibliothèque disponible sur moodle (TODO change)
