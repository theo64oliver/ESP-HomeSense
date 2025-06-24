#ifndef HUM_TEMP_SENSOR_H
#define HUM_TEMP_SENSOR_H

namespace HumTempSensor {
  void hum_temp_sensor_setup();
  void hum_sensor_checks(float hum_val);
  void hum_change_threshold(int new_threshold_value);
  void temp_sensor_checks(float temp_val);
  void hum_temp_sensor_main();
}

#endif /* !HUM_TEMP_SENSOR_H */
