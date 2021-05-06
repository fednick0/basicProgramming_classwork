void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  analogWrite(11, 255);
  analogWrite(10, 255);
  analogWrite(9, 255);
}

//30000 rojo 1200 parpadeo
//30000 verde 1200 parpadeo
//30000 azul 1200 parpadeo

int tiempo = 30000;

void loop() {
  analogWrite(11, 255 - 10);
  delay(tiempo);
  for(int x = 0; x < 3; x++){
    analogWrite(11, 255 - 0);
    delay(200);
    analogWrite(11, 255 - 10);
    delay(200);
    }
  analogWrite(11, 255 - 0);

  analogWrite(10, 255 - 10);
  delay(tiempo);
  for(int x = 0; x < 3; x++){
    analogWrite(10, 255 - 0);
    delay(200);
    analogWrite(10, 255 - 10);
    delay(200);
    }
  analogWrite(10, 255 - 0);

  analogWrite(9, 255 - 10);
  delay(tiempo);
  for(int x = 0; x < 3; x++){
    analogWrite(9, 255 - 0);
    delay(200);
    analogWrite(9, 255 - 10);
    delay(200);
    }
  analogWrite(9, 255 - 0);
}
