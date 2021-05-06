#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);

void setup() {
  bt.begin(9600);
  Serial.begin(9600);

  pinMode(7, OUTPUT); //R
  pinMode(6, OUTPUT); //G
  pinMode(5, OUTPUT); //B
}

void loop() {  
  if( bt.available() ) {
    char c = bt.read();
    Serial.write( c );

    if(c == '2') {
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
    }
    else if (c == '1') {
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
    }
    else if (c == '3') {
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);  
    }
    else if (c == '4') {
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);  
    }
  }

   if( Serial.available() ) {
     bt.write( Serial.read() );
   }
}
