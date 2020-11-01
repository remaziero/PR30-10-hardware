#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <PubSubClient.h> // Biblioteca usada, baixe e instale se não a tiver, link abaixo
//https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino

#include <c_wifi.cpp>
#include <C_MQTT.cpp>
#include <led.cpp>

/****************Define a pinagem do ESP8266************************/
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D6 12
#define D7 13
#define D5 14
#define D8 15
#define D9 3
#define D10 1
#define ledPin 2    //D4 S
#define pinBoton 13 //14    //D5 E
#define ALARME 14   // 13    //D7 S
#define RST 15      //D8 E

/************varíaveis**************************/
const long interval_led = 1000;

void setup()
{
  /*********** definições da pinagem do ESP8266************/
  pinMode(ledPin, OUTPUT);
  pinMode(pinBoton, INPUT);
  pinMode(ALARME, OUTPUT);
  pinMode(RST, INPUT);

  //****************inicializações de hardware e software *********************
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  c_wifi();
  client.setServer(mqttServer, mqttPort);
  //client.setCallback(callback);  //PARA O RESET DO NODEMCU VIA COMANDO
  c_mqtt();
  client.subscribe("estacao"); //para reset do sensor por software
}

void loop()
{

  //keep-alive da comunicação com broker MQTT externo
  client.loop();

  atrasoled(interval_led); //ESTA FUNÇÃO ESTÁ NA ABA LED
}
