#include <Arduino.h>
#define ledPin   2     //D4 S

long previousMillis_led = 0;
int ledState = LOW; // ledState usado para definir o estado lógico do LED

void atrasoled(long interval_led){

long currentMillis_led = millis();
if(currentMillis_led - previousMillis_led > interval_led) {
previousMillis_led = currentMillis_led;

// se o LED estiver desligado, ligue-o e vice-versa:
if (ledState == LOW){
ledState = HIGH;
//imprimirSerial(true,"led ALTO");
}

else{
ledState = LOW;
//imprimirSerial(true,"led BAIXO");
}
// define o LED com a condição da variável ledState:
digitalWrite(ledPin, ledState);
}
}
