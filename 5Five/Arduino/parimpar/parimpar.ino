void setup() {
  pinMode(11, OUTPUT); // r
  pinMode(10, OUTPUT); //g
  pinMode(9, OUTPUT); // b

  analogWrite(11, 255 - 0);
  analogWrite(10, 255 - 0);
  analogWrite(9, 255 - 0);
}

int n = 1;

void loop() {
  
  if(n % 2 == 0){
    analogWrite(10, 255 - 10);
    delay(1000);
  }
  else{
    analogWrite(11, 255 - 10);
    delay(1000);
  }

  n++;

  analogWrite(11, 255 - 0);
  analogWrite(10, 255 - 0);  
  delay(1000);
}
