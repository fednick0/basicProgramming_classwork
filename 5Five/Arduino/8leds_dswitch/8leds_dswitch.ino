short a = 13;
short b = 12;
short c = 11;
short d = 10;
short e = 9;
short f = 8;
short g = 7;
short dot = 6;

short dl = 100;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(dot, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
}

void loop() {
  if( digitalRead(2) && !digitalRead(3) && !digitalRead(4) && !digitalRead(5) ) {
    digitalWrite(a, HIGH);
    delay(dl);
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    delay(dl);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    delay(dl);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    delay(dl);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    delay(dl);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    delay(dl);
    digitalWrite(f, LOW);
  }
  
  else if( !digitalRead(2) && digitalRead(3) && !digitalRead(4) && !digitalRead(5) ) {
    digitalWrite(a, HIGH);
    delay(dl);
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    delay(dl);
    digitalWrite(b, LOW);
    digitalWrite(g, HIGH);
    delay(dl);
    digitalWrite(g, LOW);
    digitalWrite(e, HIGH);
    delay(dl);
    digitalWrite(e, LOW);
    digitalWrite(d, HIGH);
    delay(dl);
    digitalWrite(d, LOW);
    digitalWrite(c, HIGH);
    delay(dl);
    digitalWrite(c, LOW);
    digitalWrite(g, HIGH);
    delay(dl);
    digitalWrite(g, LOW);
    digitalWrite(f, HIGH);
    delay(dl);
    digitalWrite(f, LOW);
  }  
  
  else if( !digitalRead(2) && !digitalRead(3) && digitalRead(4) && !digitalRead(5) ) {
    digitalWrite(a, HIGH);
    delay(dl);
    digitalWrite(a, LOW);
    digitalWrite(g, HIGH);
    delay(dl);
    digitalWrite(g, LOW);
    digitalWrite(d, HIGH);
    delay(dl);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    delay(dl);
    digitalWrite(e, LOW);
    digitalWrite(c, HIGH);
    delay(dl);
    digitalWrite(c, LOW);
    digitalWrite(f, HIGH);
    delay(dl);
    digitalWrite(f, LOW);
    digitalWrite(b, HIGH);
    delay(dl);
    digitalWrite(b, LOW);
  }
   
  else if( !digitalRead(2) && !digitalRead(3) && !digitalRead(4) && digitalRead(5) ) {
    digitalWrite(a, HIGH);
    digitalWrite(d, HIGH);
    delay(dl);
    digitalWrite(a, LOW);
    digitalWrite(d, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(c, HIGH);
    delay(dl);
    digitalWrite(f, LOW);
    digitalWrite(c, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(d, HIGH);
    delay(dl);
    digitalWrite(e, LOW);
    digitalWrite(d, LOW);
  }
}
