#include "button.h"

#include "config.h"
#include "led.h"

int button_state = 0;

void Button::button_setup() {
    pinMode(BUTTON_PIN, INPUT);
}

void Button::button_main() {
    button_state = digitalRead(BUTTON_PIN);

    if (button_state == HIGH) {
        // turn LED on:
        debug.println("button pressed");
        Led::led_on(BUILTIN_LED);
    }
    else {
        // turn LED off:
        debug.println("button released");
        Led::led_off(BUILTIN_LED);
    }
}
