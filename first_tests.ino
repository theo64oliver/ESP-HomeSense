#include <ChainableLED.h>
#include <Wire.h>

#include "rgb_lcd.h"

#include "config.h"
#include "wifi.h"
#include "led.h"
#include "button.h"
#include "lcd.h"
#include "NodeMCU_server.h"
#include "hum_temp_sensor.h"

void setup() {

    debug.begin(115200);
    debug.println("DHTxx test!");
    Wire.begin();

    Led::led_setup();
    Led::led_off(0); // Turn off the builtin LED

    Wifi::wifi_setup();
    NodeMCU_Server::server_setup();

    LCD::lcd_setup();
    Button::button_setup();

    // To send:
    // Json avec MAC address
    //send_get("https://google.com");
}

void loop() {
    Button::button_main();

    HumTempSensor::hum_temp_sensor_main();

    NodeMCU_Server::server_listen();


    delay(500);
}
