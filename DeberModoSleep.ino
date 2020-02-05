#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>
#include<TimerOne.h>
#include<EEPROM.h>
int cont = 0;
int modo;

void setup() {
  Serial.begin(9600);
  modo = EEPROM.read(0);
  EEPROM.write(0, 1);
  attachInterrupt(0, despertar, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  Serial.begin(9600);
  Serial.println(modo);
}
void loop() {
  if (cont == 2 ) {
    Serial.println("Modo activo");
    EEPROM.update(0, 1);
    Serial.println(modo);
  }
  if (cont == 12) {
    Serial.println("Modo dormido");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
    sleep_disable();
  }
}
void conteo() {
  cont++;
}
void despertar() {
  sleep_disable();
  Serial.println("Reinicio");
  cont = 0;
}
