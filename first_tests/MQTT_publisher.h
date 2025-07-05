#ifndef MQTT_PUBLISHER_H
#define MQTT_PUBLISHER_H

namespace MQTT_Publisher {
  void setup();
  void publish_temp(int id, int temp_value);
  void publish_hum(int id, int hum_value);
  void reconnect();
  void loop();
}

#endif /* !MQTT_PUBLISHER_H */
