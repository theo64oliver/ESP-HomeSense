#include "light_sensor.h"

#include "Si115X.h"

#include "config.h"
#include "MQTT_publisher.h"
#include "component_dto.h"

Si115X si1151;


void Light_Sensor::setup() {

    if (!si1151.Begin()) {
        Serial.println("Si1151 is not ready!");
        while (1) {
            delay(1000);
            Serial.print(".");
        };
    }
    else {
        Serial.println("Si1151 is ready!");
    }
}

void Light_Sensor::lum_sensor_main() {
    int lum_val = si1151.ReadVisible();

    MQTT_Publisher::publish_lum(0, lum_val);
}

String Light_Sensor::create_dto(int id, String value) {
    return Component_DTO::create(ComponentType::e_Sunlight, id, value, "LumSensor");
}
