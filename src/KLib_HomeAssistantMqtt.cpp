#include "KLib_HomeAssistantMqtt.h"

KLib_HomeAssistantMqtt::KLib_HomeAssistantMqtt(PubSubClient& client) : client(client) {}

void KLib_HomeAssistantMqtt::autoDiscover(
    const std::string& device_id,
    const std::string& id,
    const std::string& name,
    const std::string& deviceClass,
    const std::string& unitOfMeasurement
) {
    std::string topic = "homeassistant/sensor/" + device_id + "/" + id + "/config";

    std::string payload = "{";
    payload += "\"device\": {";
    payload += "\"identifiers\": [\"" + device_id + "\"]";
    payload += ",\"name\": \"" + device_id + "\"";
    payload += ",\"manufacturer\": \"KazaLab\"";
    payload += ",\"model\": \"Home Sensors\"";
    payload += "}";
    if (deviceClass != "") {
        payload += ",\"device_class\": \"" + deviceClass + "\"";
    }
    payload += ",\"unique_id\": \"" + device_id + "_" + id + "\"";
    payload += ",\"object_id\": \"" + device_id + "_" + id + "\"";
    payload += ",\"state_topic\": \"home/" + device_id + "/" + id + "\"";
    payload += ",\"state_class\": \"measurement\"";
    payload += ",\"unit_of_measurement\": \"" + unitOfMeasurement + "\"";
    payload += ",\"value_template\": \"{{ value }}\"";
    payload += "}";

    bool result = client.publish(topic.c_str(), payload.c_str(), true);

    if (!result) {
        Serial.print("Result: ");
        Serial.println(result);

        int errorCode = client.state();
        Serial.print("MQTT Client State: ");
        Serial.println(errorCode);

        Serial.print("Topic: ");
        Serial.println(topic.c_str());
        Serial.println(payload.c_str());
        Serial.print("Payload Size: ");
        Serial.println(payload.length() - 1);
    }
}
