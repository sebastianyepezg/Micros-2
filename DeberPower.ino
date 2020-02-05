#include <LowPower.h> //PDWN
#include <avr/wdt.h>  //Perro guardián
#include <EEPROM.h>   //Memoria
#include<avr/sleep.h> //Sleep
#include <TimerOne.h> //Reloj1
#include <MsTimer2.h> //Reloj2
#include <avr/power.h>
#include <LiquidCrystal.h>//LCD
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int cont = 0;
int dato;
int alim = 7;
int num = EEPROM.read(0);

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  power_all_enable();
  lcd.begin(16, 2);
  num = 0;
}

void loop() {
  Serial.println(num);
  dormir();
  lcd.setCursor(6, 1);
  lcd.print(cont);
  dato = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(dato);
}
void conteo() {
  cont++;
}

void dormir() {
  if (cont == 5) {
    num = num + 1;
    lcd.setCursor(0, 0);
    lcd.print("CONV DES");
    power_adc_disable();

  }
  if (cont == 8) {
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("ANULADO");
    power_spi_disable();
  }
  if (cont == 12) {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("DANULADO");
    power_all_disable();
  }
  if (EEPROM.read(0) > 12) {
    num = 0;
    power_all_enable();
    EEPROM.write(0, num);
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("REINICIO");
    digitalWrite(alim, HIGH);
    delay(30);
    wdt_enable(WDTO_1S);

  }
}
