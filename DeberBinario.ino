int i = 0;
int leds[8] = {6, 7, 8, 9, 10, 11, 12, 13};
String dato;
int num1;
int num2;
void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ingrese un numero");
}

void loop() {
  if (Serial.available() > 0) {                 //Activar la entrada de datos
    dato = Serial.readStringUntil("\n");
    num1 = dato.toInt();                        //Transformar el dato en entero
  }
  if (num1 > 0 && num1 < 256) {                 //Verifica si el número ingresado está entre 0 y 256
    num2 = num1;                                //Almacena el número en otra variable
    for (i = 0; i < 8; i++) {                   //Ciclo que recorre el vector
      if (num2 % 2 == 1) {                      //Proceso de transformación a binario
        digitalWrite(leds[i], HIGH);
      }
      else {
        digitalWrite(leds[i], LOW);
      }
      num2 = num2 / 2;
    }
  }
  else {
    for (i = 0; i < 8; i++) {
      digitalWrite(leds[i], LOW);
    }
    num1 = 0;
  }
  delay(300);
}
