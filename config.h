#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Platform-dependent debug interface
#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) || defined(ARDUINO_ARCH_SAM)
    #ifdef SerialUSB
        #define debug  SerialUSB
    #else
        #define debug  Serial
    #endif
#else
    #define debug  Serial
#endif

// Wi-Fi credentials
#define WIFI_SSID "Livebox-FF50"
#define WIFI_PASSWORD "MwuSzV52cHkzvF2V64"

// Pin definitions for the button and LEDs
#define BUTTON_PIN D8
#define LED_PIN1 D5
#define LED_PIN2 D6

// Used by the humidity and temperature sensor
#define DHTTYPE DHT11   // DHT 11
// Pin for the humidity and temperature sensor
#define DHTPIN D3

#define LCD_COLS 2
#define LCD_ROWS 16


#endif
