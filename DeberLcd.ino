#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, A0, A1, A2, A3); //RS, Enable, D4, D5, D6, D7
String dato ;
String frase;
int alm = 0;
int num = 0;
int a = 0;
int i = 0;

void setup() {
  lcd.begin(16, 2);
  //  lcd.print("INGRESE FRASE");

  lcd.blink();
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    for (i = 0; i < dato.length() - 1; i++) {
      frase = frase + dato.substring(i, i + 1);
    }
    lcd.print(frase);
    delay(2000);
    for (i = 0; i < frase.length(); i++) {
      lcd.scrollDisplayLeft();
      delay(750);
    }
    for (i = 0; i < 16 + frase.length(); i++) {
      lcd.scrollDisplayRight();
      delay(750);
    }
    for (i = 0; i < 16; i++) {
      lcd.scrollDisplayLeft();
      delay(750);
    }

  }
  lcd.setCursor(0, 0);
  lcd.print("INGRESE FRASE");
  dato = "";
  frase = "";
  lcd.print("                ");
  lcd.setCursor(0, 0);
}
