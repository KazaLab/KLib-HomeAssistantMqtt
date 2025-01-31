#ifndef KLIB_HOMEASSISTANTMQTT_H
#define KLIB_HOMEASSISTANTMQTT_H

#include <string>
#include <PubSubClient.h>
#include <Arduino.h>

class KLib_HomeAssistantMqtt {
public:
    explicit KLib_HomeAssistantMqtt(PubSubClient& client);
    ~KLib_HomeAssistantMqtt() = default;

    void autoDiscover(const std::string& device_id,
                      const std::string& id, const std::string& name,
                      const std::string& deviceClass, const std::string& unitOfMeasurement);

private:
    PubSubClient& client;
};

#endif
