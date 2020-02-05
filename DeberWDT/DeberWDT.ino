/*Realizar un programa que mediante comunicación serial ingrese el tiempo de reset del arduino de la siguiente forma: A->1seg, B->2seg,
   C->4seg, D->8seg. Hay que tener en cuenta que el sistema puede ser reconfigurado las veces necesarias (interrupciones)*/
#include<avr/wdt.h>
#include <EEPROM.h>
char letra;
int cont = 0;
int num = 0;
void setup() {
  // wdt_disable();
  Serial.begin(9600);
  attachInterrupt(0, reinicio, LOW);
  Serial.println("Inicio");
}

void loop() {
  if (cont == 1) {
    if (Serial.available() > 0) {
      letra = Serial.read();
      Serial.println(letra);
      EEPROM.update(0, letra);
    }
  }
  else {
    Serial.println(num);
    num++;
    delay(200);
  }
}
void reinicio() {
  Serial.println(EEPROM.read(0));
  if (cont == 1) {
    if (EEPROM.read(0) == 'A') {
      wdt_enable(WDTO_1S);
    }
    if (EEPROM.read(0) == 'B') {
      wdt_enable(WDTO_2S);
    }
    if (EEPROM.read(0) == 'C') {
      wdt_enable(WDTO_4S);
    }
    if (EEPROM.read(0) == 'D') {
      wdt_enable(WDTO_8S);
    }
  }
  if (cont == 0) {
    wdt_disable();
    Serial.println("Ingrese una letra");
  }
  cont = 1 - cont;
}
