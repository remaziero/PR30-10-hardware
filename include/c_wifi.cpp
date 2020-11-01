#include <Arduino.h>
//Parâmetros de configuração do wifi
const char* ssid = "TP-Link_A9C6";
const char* password = "20337537";


void c_wifi(){
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.println("Conectando à rede WiFi..");
   }
     // imprimir informações sobre a conexão WIFI
 Serial.print("Conectado à rede WiFi= ");
 Serial.println(ssid);
 Serial.print ( "IP address: " );
 Serial.println ( WiFi.localIP() );

 }
