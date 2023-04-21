const int Trigger = 2;  //Pin digital 2 para el Trigger del sensor
const int Echo = 3;     //Pin digital 3 para el echo del sensor
const int Led = 13;
const int Zumbador = 11;

void setup() {
  Serial.begin(9600);          //iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT);    //pin como salida
  pinMode(Echo, INPUT);        //pin como entrada
  digitalWrite(Trigger, LOW);  //Inicializamos el pin con 0
  pinMode(Led, OUTPUT);    //pin como salida
  pinMode(Zumbador, OUTPUT);    //pin como salida
}

void loop() {
  long t;  //timepo que demora en llegar el eco
  long d;  //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);  //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);  //obtenemos el ancho del pulso
  d = t / 59;               //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print(d);  //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();

  if (d<30) {
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }

  if (d<15&&d>5) {
    //analogWrite(Zumbador, 200);
    tone(Zumbador, 400, 200);
  } else if (d<=5) {
    tone(Zumbador, 400);
  } else {
    //analogWrite(Zumbador, 0);
    noTone(Zumbador);
  }
  delay(500);  //Hacemos una pausa de 100ms
}
