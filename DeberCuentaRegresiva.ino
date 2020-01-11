#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, A0, A1, A2, A3); //RS, Enable, D4, D5, D6, D7
//////////////////TECLADO//////////////////
#include <Keypad.h>     // importa libreria Keypad
const byte fil = 4;     // define numero de filas
const byte col = 4;    // define numero de columnas
char keys[fil][col] = {    // define la distribucion de teclas
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFil[fil] = {11, 10, 9, 8}; // pines correspondientes a las filas
byte pinCol[col] = {7, 6, 5, 4}; // pines correspondientes a las columnas
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col);  // crea objeto
///////////////////////////////////////////
char tecla;
String dato ;
int alm = 0;
int num = 0;
int a = 0;
void setup() {
  MsTimer2::set(1000, lectura);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.print("INGRESE NUMERO");
  lcd.setCursor(0, 1);
}

void loop() {
  tecla = teclado.getKey();
  if (tecla) {
    if (tecla == 'A' || tecla == 'C' || tecla == 'D' || tecla == '#' || tecla == '*') {
      a = 1 - a;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(9, 1);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("CONTEO REGRESIVO");
    }
    else if (tecla == 'B') {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("RESET");
      delay(2000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESE NUMERO");
      lcd.setCursor(0, 1);
      tecla = ' ';
      dato=" ";
      a = 0;
      num = 0;
    }
    else {
      lcd.print(tecla);
      dato = dato + tecla;
    }
    num = dato.toInt();
  }
}
void lectura() {
  if (a == 1 ) {
    if (num > 0) {
      lcd.setCursor(9, 1);
      lcd.print("      ");
      lcd.setCursor(9, 1);
      lcd.print(num);
      num--;
    }
    else if (num == 0) {
      lcd.setCursor(9, 1);
      lcd.print("    ");
      lcd.setCursor(9, 1);
      lcd.print(num);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("FIN CONTEO");
    }
  }
}
