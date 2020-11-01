#include <Arduino.h>
#include <PubSubClient.h> // Biblioteca usada, baixe e instale se não a tiver, link abaixo
                          //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino

/*
Os códigos de retorno de CONNACK são:
0  - Conexão aceita
1 - Conexão recusada, versão do protocolo inaceitável
2 - Conexão recusada, identificador rejeitado
3 - Conexão recusada, servidor indisponível
4 - Conexão recusada, usuário e/ou senha inválidos
5 - Conexão recusada, não autorizado
*/
//char* ESP8266Client = "MQTT_ARN";

unsigned long previousMillis_mqtt=0;
unsigned long intervalo_mqtt = 1500;

/***************BROKER INTERNO linux UBUNTU**************************/
const char* mqttServer = "192.168.0.105";
const int mqttPort = 1883; // Aqui mude para sua porta fornecida pelo ACL
const char* mqttUser = "ARN"; //  Aqui o nome de usuario fornecido pelo ACL
const char* mqttPassword = "camila"; //  Aqui sua senha fornecida pelo ACL

//****DEFINIÇÃO DOS TÓPICOS PARA O BROKER*************/
//identificador de publicação no terminal
const char* usu = "METRO_DF/ARN";
const char* estacao = "ARN";

/**************************Instanciamento de entidades*****************/
WiFiClient espClient;
PubSubClient client(espClient);
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient

void c_mqtt(){
 while (!client.connected()) {
   Serial.print("Conectando ao: ");
   Serial.println(mqttServer);
   if (client.connect(estacao, mqttUser, mqttPassword )) {

     Serial.println("************** conectado ***************");
     Serial.println(usu);

     } else {
     unsigned long currentMillis_mqtt = millis();
       if(currentMillis_mqtt - previousMillis_mqtt > intervalo_mqtt) {
       previousMillis_mqtt = currentMillis_mqtt;
       Serial.print("Conexão ao Broker MQTT falhou com estado= ");
       Serial.println(client.state());

       }
     }
   }
}
