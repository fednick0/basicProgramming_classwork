void setup() {
  pinMode(11, OUTPUT); // r
  pinMode(10, OUTPUT); //g
  pinMode(9, OUTPUT); // b

  analogWrite(11, 0);
  analogWrite(10, 255);
  analogWrite(9, 255);
}

int r = 255;
int g = 255;
int b = 255;

int maxi = 255;
int mini = 0;

int d_lay = 10;

void loop() {
  arcoiris();
}

void arcoiris(){
  for(g; g > mini; g--){ 
      analogWrite(10, g);
      delay(d_lay);
  }
  for(r; r < maxi; r++){ 
      analogWrite(11, r);
      delay(d_lay);
  }
  for(b; b > mini; b--){ 
      analogWrite(9, b);
      delay(d_lay);
  }
  for(g; g < maxi; g++){ 
      analogWrite(10, g);
      delay(d_lay);
  }
  for(r; r > mini; r--){ 
      analogWrite(11, r);
      delay(d_lay);
  }
  for(b; b < maxi; b++){ 
      analogWrite(9, b);
      delay(d_lay);
  }
}

void red(){
  for(r; r > mini; r--){ 
      analogWrite(11, r);
      delay(d_lay);
  }
  for(r; r < maxi; r++){ 
      analogWrite(11, r);
      delay(d_lay);
  }
}

void green(){
  for(g; g > mini; g--){ 
      analogWrite(10, g);
      delay(d_lay);
  }
  for(g; g < maxi; g++){ 
      analogWrite(10, g);
      delay(d_lay);
  }
}

void blue(){
  for(b; b > mini; b--){ 
      analogWrite(9, b);
      delay(d_lay);
  }
  for(b; b < maxi; b++){ 
      analogWrite(9, b);
      delay(d_lay);
  }
}
