# KLib-HomeAssistantMqtt

**KLib-HomeAssistantMqtt** is a lightweight library for handling MQTT auto-discovery in Home Assistant.

## Installation

### Using PlatformIO

Add the following to `platformio.ini`:

```ini
lib_deps = https://github.com/tonuser/KLib-HomeAssistantMqtt.git
```


## Usage

```cpp
#include <KLib_HomeAssistantMqtt.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient mqttClient(espClient);
KLib_HomeAssistantMqtt haMqtt(mqttClient);

void setup() {
    Serial.begin(115200);
    mqttClient.setServer("192.168.1.100", 1883);
    mqttClient.connect("TestClient");

    haMqtt.autoDiscover("sensor1", "temperature", "Temperature Sensor", "temperature", "°C");
}

void loop() {
    mqttClient.loop();
}
```
