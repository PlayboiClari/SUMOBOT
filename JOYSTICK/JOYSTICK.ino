/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
// defines pins numbers
const int LED = 2;
const int LED2 = 3;
const int trigPin = 9;
const int echoPin = 10;
const int trigPin2 = 11;
const int echoPin2 = 12;

const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
// defines variables
long duration;
int distance;
long duration2;
int distance2;

const int vrx = A0;
const int vry = A1;
const int sw = 13;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

  pinMode(in1, OUTPUT); // Sets the trigPin as an Output
  pinMode(in2, OUTPUT); // Sets the trigPin as an Output
  pinMode(in3, OUTPUT); // Sets the trigPin as an Output
  pinMode(in4, OUTPUT); // Sets the trigPin as an Output

  Serial.begin(9600); // Starts the serial communication

  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(sw, INPUT);
}
void loop() {

int ejeX = analogRead(vrx);
Serial.println(  ejeX);

if (ejeX> 1000){
  frente();
}

if (ejeX< 400){
  atras();
}

if (ejeX> 400 and ejeX<1000){
  desactivado();
}

int ejeY = analogRead(vry);
Serial.println( ejeY);

if (ejeY< 400){
  izquierda();
}

if (ejeY> 1000){
  derecha();
}

if (ejeY> 400 and ejeY< 1000){
  desactivado();
}
  // Clears the trigPin

  // distance = ultrasonic(trigPin,echoPin);
  // Serial.print("distance: ");
  // Serial.println(distance);

  
  // distance2 = ultrasonic(trigPin2,echoPin2);
  // Serial.print("distance2: ");
  // Serial.println(distance2);

  // if (distance>200){
  //   frente();
  //   Serial.println("----------------------------------*frente: ");
  // }
  // if (distance<200){
  //   atras();
  //   Serial.println("----------------------------------*atras: ");

  //   }
}
int ultrasonic(int tPin, int ePin){
    // Clears the trigPin
    int d;
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ePin, HIGH);
  // Calculating the distance
  d = duration * 0.034 / 2;
  return d;
}

void frente (    ){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);  
  digitalWrite(in4,LOW);
}
void atras (    ){
  digitalWrite(in1,LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3,LOW);  
  digitalWrite(in4,HIGH);
}

void izquierda (    ){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);  
  digitalWrite(in4,LOW);
}

void derecha (    ){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);  
  digitalWrite(in4,LOW);
}

void desactivado (    ){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);  
  digitalWrite(in4,LOW);
}
 