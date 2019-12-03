/*Realizar un programa que active 4 juegos de luces con 5 leds al ingresar datos por Cx Serial de la siguiente forma:
  ACBF -> Activa juego 1
  ACGF -> Activa juego 2
  ADBF -> Activa juego 3
  ADBH -> Activa juego 4*/
String palabra;
int juego[5] = {8, 9, 10, 11, 12};
int i;
void setup() {
  for (i = 0; i < 5; i++) {
    pinMode(juego[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("JUEGO DE LUCES");
  Serial.println("ACBF -> Activa juego 1");
  Serial.println("ACGF -> Activa juego 2");
  Serial.println("ADBF -> Activa juego 3");
  Serial.println("ADBH -> Activa juego 4");
  Serial.println("Escoja un juego");
}
void loop() {
  if (Serial.available() > 0) {
    palabra = Serial.readString();
    Serial.println("");
    if (palabra == "ACBF") {
      juego1();

    }
    else if (palabra == "ACGF") {
      juego2();
    }
    else if (palabra == "ADBF") {
      juego3();
    }
    else if (palabra == "ADBH") {
      juego4();
    }
    else {
      Serial.println("Ingrese un codigo correcto");
    }
  }
}
void juego1() {
  Serial.println("Inicio del Juego 1");
  for (i = 0; i < 5; i++)
  {
    digitalWrite(juego[i], HIGH);
    digitalWrite(juego[4 - i], HIGH);
    delay(500);
    digitalWrite(juego[i], LOW);
    digitalWrite(juego[4 - i], LOW);
  }
  Serial.println("Fin del Juego 1");
}
void juego2() {
  Serial.println("Inicio del Juego 2");
  for (i = 0; i < 5; i++)
  {
    digitalWrite(juego[i], HIGH);
    delay(500);
    digitalWrite(juego[i], LOW);
    delay(500);
    digitalWrite(juego[4 - i], HIGH);
    delay(500);
    digitalWrite(juego[4 - i], LOW);
  }
  Serial.println("Fin del Juego 2");
}
void juego3() {
  Serial.println("Inicio del Juego 3");
  for (i = 0; i < 5; i++)
  {
    digitalWrite(juego[i], HIGH);
    delay(500);
  }
  for (i = 4; i >= 0; i--)
  {
    digitalWrite(juego[i], LOW);
    delay(500);
  }
  Serial.println("Fin del Juego 3");
}
void juego4() {
  Serial.println("Inicio del Juego 4");
  for (i = 0; i < 5; i++)
  {
    digitalWrite(juego[i], HIGH);
    delay(500);
    digitalWrite(juego[i], LOW);
    i++;
  }
  Serial.println("Fin del Juego 4");
}
