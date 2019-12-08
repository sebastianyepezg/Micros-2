/*Realizar un ejercicio en el cual tenga las etapas de:
  (i)Ingreso de datos y (ii) ordenamiento
  (i)Al ingresar la palabra solo pueden ser números por comunicación serial.
  (ii) Una vez ingresados lo números, ordenarlos de menor a mayor e imprimirlo por comunicación serial.*/
int modo = 0;
int sel = 0;
String dato;
int i = 0;
String cant;
int cambio;
int aux;
void setup() {
  attachInterrupt(0, botUno, LOW);
  attachInterrupt(1, botDos, LOW);
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE ORDENA UN VECTOR");
  Serial.println("Presione el boton 1 para iniciar");
}
void loop() {
  if (sel == 1 && modo == 1) {
    if (Serial.available() > 0) {
      dato = Serial.readString();
      Serial.println("");
      Serial.println("Numero ingresado");
      Serial.println("Presione el boton 1 para ordenar el numero");
    }
  }
  else if (modo == 2 && dato != "") {       //Condición para no iniciar sin tener números
    int num[dato.length()];                 //Se crea el vector que guardará el dato
    for (i = 0; i < dato.length(); i++) {   //Aquí se crea el vector
      cant = dato.substring(i, (i + 1));    //Toma los datos que se ingresaron por teclado
      num[i] = cant.toInt();                //Guarda los datos individualmente convertidos en enteros
    }
    do {                                    //Código para ordenar los números
      cambio = 0;
      for (i = 0; i < dato.length(); i++) { //Se lee el vector
        if (num[i] > num[i + 1]) {          //Compara los números entre posiciones adyacentes
          cambio = 1;
          aux = num[i];
          num[i] = num[i + 1];
          num[i + 1] = aux;
        }
      }
    }
    while (cambio);
    for (i = 0; i < dato.length(); i++) { //Imprimir el número ordenado
      Serial.print(num[i]);
    }
    Serial.println(" ");
    dato = "";
  }
}
void botUno() {
  switch (modo) {
    case 0:
      Serial.println("Presione el boton 2 y digite un numero");
      modo++;
      break;
    case 1:
      Serial.println("Ordenamiento del numero");
      modo++;;
      break;
    default:
      modo = 0;
      sel = 0;
      break;
  }
}
void botDos() {
  if (modo == 1) {
    Serial.println("Escribir numero");
    sel++;
  }
}
