short t = 750;

void setup() {  
  pinMode(2, INPUT); // sensor

  // r
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  // g
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
}

bool enter = true;
short n = 0;

void loop() {  
  if( digitalRead(2) ) {

    if(enter) {
      n++;
      enter = false;
    }

    switch(n) {
      case 1: // verde
        encendido(8, 13, 0);          
        break;

      case 2: // amarillo
        encendido(8, 13, true);
        break;

      case 3: // rojo
        encendido(14, 19, 0);
        n = 0;
        break;
    }
  }
  else
    enter = true;
}

void encendido(short mini, short maxi, bool amarillo) {
  for(short i = mini; i <= maxi; i++) {
    digitalWrite(i, HIGH);
          
    if(amarillo)
      digitalWrite(i+6, HIGH);
            
    delay(t);
  }

  for(short i = mini; i <= maxi; i++) {
    digitalWrite(i, LOW);
          
    if(amarillo)
      digitalWrite(i+6, LOW);
            
    delay(t);
  }
}
