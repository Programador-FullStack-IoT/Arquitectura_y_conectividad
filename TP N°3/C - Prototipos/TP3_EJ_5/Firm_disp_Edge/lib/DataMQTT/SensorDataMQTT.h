#ifndef SENSORDATAMQTT_H
#define SENSORDATAMQTT_H

#include <WiFi.h>
#include <PubSubClient.h>
#include "Extractor.h"

class SensorDataMQTT {
public:
    SensorDataMQTT(const char* ssid, const char* password, const char* broker, int port, IPAddress ip, IPAddress gateway, IPAddress subnet, Extractor& extractor);
    void conectarWiFi();
    void conectarMQTT();
    void publicarLecturas(float co2, float temperatura, float humedad/*, float nivelBateria*/);
    void manejarMQTT();
    
private:
    const char* ssid;
    const char* password;
    const char* broker;
    int port;
    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;
    Extractor& extractor;
    WiFiClient espClient;
    PubSubClient client;

    void procesarMensaje(char* topic, byte* payload, unsigned int length);
    static SensorDataMQTT* instancia;
    static void callbackWrapper(char* topic, byte* payload, unsigned int length);
};

#endif
