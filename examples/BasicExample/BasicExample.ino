#include <KLib_HomeAssistantMqtt.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient mqttClient(espClient);
KLib_HomeAssistantMqtt haMqtt(mqttClient);

void setup() {
    Serial.begin(115200);

    // Simulated MQTT connection
    mqttClient.setServer("192.168.1.100", 1883);

    Serial.println("Connecting to MQTT...");
    if (mqttClient.connect("TestClient")) {
        Serial.println("Connected to MQTT!");
    } else {
        Serial.print("MQTT Connection failed, state: ");
        Serial.println(mqttClient.state());
    }

    // Example of Home Assistant auto-discovery for a temperature sensor
    haMqtt.autoDiscover("sensor1", "temperature", "Temperature Sensor", "temperature", "°C");
}

void loop() {
    mqttClient.loop();
}
