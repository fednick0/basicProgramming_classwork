#include <Servo.h>

short m1a = 17; // cafe
short m1b = 16; // naranja
short m1s = 6; // gris speed
short m2a = 15; // negro
short m2b = 14; // morado
short m2s = 5; // rojo speed
short u_echo = 3; // blanco
short u_trig = 2; // cafe

Servo pinza;

void setup() {
  // motores
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m1s, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m2s, OUTPUT);

  // ultrasonico
  pinMode(u_echo, INPUT);
  pinMode(u_trig, OUTPUT);

  Serial.begin(9600);
  //pinza.attach(11);  
}

void loop() {
  
  
}

void izq_delante(short s) {
  analogWrite(m1s, s);
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
}

void izq_atras(short s) {
  analogWrite(m1s, s);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
}

void der_delante(short s) {
  analogWrite(m2s, s);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void der_atras(short s) {
  analogWrite(m2s, s);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}

short ultrasonico() {
  digitalWrite(u_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(u_trig, LOW);

  unsigned short dt = pulseIn(u_echo, HIGH);
  dt = dt / 59;

  Serial.println(dt); // borrar
  delay(100);
  return dt;
}
