#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);

void setup() {
  bt.begin(9600); 
  Serial.begin(9600);

  pinMode(7, OUTPUT);
}
 
void loop() {
  if ( bt.available() ) {
    char c = bt.read();
    Serial.write( c );

    if(c == '1')
      digitalWrite(7, HIGH);
    if(c == '2')
      digitalWrite(7, LOW);
      
  }
  if ( Serial.available() ) {
    bt.write(Serial.read());
  }
}
