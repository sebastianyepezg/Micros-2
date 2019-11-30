float valor;
float conversor;
String dato;
int aux = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  Serial.println("Limite de lectura de ADC");
  Serial.println("*-----------------------*");
  Serial.println("Ingrese un valor limite");
}
void loop() {
  if (Serial.available() > 0) {                   //Entrada de datos
    dato = Serial.readStringUntil("\n");          //Se debe dar un enter después de ingresar el número
    aux = dato.toInt();                           //Convertir el String ingresado en entero
  }
  if (aux > 0 && aux < 1024) {                    //Comprueba que entre en el rango de 0 a 1023
    valor = analogRead(A0);                       //Lee el valor de potenciómetro
    Serial.println(valor);                        //Imprime el valor del potenciómetro (opcional)
    delay(200);                                   //Retardo de impresión de datos
    if (valor > aux) {                            //Compara el valor del potenciómetro con el límite establecido por Cx Serial
      digitalWrite(8, HIGH);                      //Enciende el Led
    }
    else {
      digitalWrite(8, LOW);                       //Apaga el Led
    }
  }

  //valor = map(valor, 0, 1023, 0, 255);
  //conversor = (valor * 5) / 1023;


}
