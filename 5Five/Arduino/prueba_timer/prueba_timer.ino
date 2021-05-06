void setup() {
  Serial.begin(9600);

}

void loop() {
  timer();
  Serial.write("hola");
}

void timer() {
  Serial.write("ROJO");
  delay(10000);
  Serial.write("Amarillo");
  delay(10000);
  Serial.write("Verde");
  delay(10000);
}
