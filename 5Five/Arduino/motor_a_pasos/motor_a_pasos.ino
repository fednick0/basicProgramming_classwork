#include <Stepper.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(6, 5);

Stepper st1(2048, 8, 10, 9, 11);

void setup() { 
  bt.begin(9600);
  Serial.begin(9600);

  pinMode(4, OUTPUT); // G
  pinMode(3, OUTPUT); // B
  pinMode(2, OUTPUT); // R

  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  
  st1.setSpeed(10);
}

char c;

void loop() {
  if (c == '3') {
      digitalWrite(4, LOW);
      delay(300);
      digitalWrite(3, LOW);
      delay(300);
      digitalWrite(2, LOW);
      delay(300);

      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }

    else if (c == '2') {
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }

    else if(c == '1') {
      st1.step(1);
    }
  
  if( bt.available() ) {
    c = bt.read();
    Serial.write( c );
  }
  
  if( Serial.available() ) {
    bt.write( Serial.read() );
  }
}
