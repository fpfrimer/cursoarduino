#include <Servo.h> // Inclui a biblioteca Servo para controlar servos

const int trigPin = 9;
const int echoPin = 10;

Servo meuServo;      // Cria um objeto Servo para controlar o servo motor
int pos;             // Declara uma variável para a posição do servo

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  meuServo.attach(6);       // Associa o servo motor ao pino digital 6
  meuServo.write(0);        // Posição inicial = 0 graus
  Serial.begin(9600);
}

void loop() {
  // Geração do pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Cálculo da distância
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  // Imprime na serial
  Serial.print("Distance: ");
  Serial.println(distance);

  // Ajusta para o ângulo do servo de 0 a 90°
  pos = distance * 3;
  if(pos >= 90){
    pos = 90;
  }
  meuServo.write(pos);   // Define a posição do servo
  delay(100);
}
