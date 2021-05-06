void setup() {
  
  pinMode(2, INPUT_PULLUP); // enabling internal pull-up resistor
  pinMode(13, OUTPUT);
}
 
void loop() {
 
  if (digitalRead(2) == LOW)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
