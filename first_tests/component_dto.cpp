#include "component_dto.h"

#include <ctime>

#include "config.h"
#include "wifi.h"

String Component_DTO::create(int type, int id, String value, String component_name)
{
    String ts_val = String(std::time(nullptr), DEC);
    String ip = Wifi::get_ip();

    String id_tmp = String(id, DEC);

    String id_final = String(ip + component_name + id);
    String type_val = String(type, DEC);

    return String("{\"id\":\"" + id_final + "\", \"type\":\"" + type_val + "\", \"value\":\"" + value + "\", \"timestamp\":\"" + ts_val + "\"}\"");
}
