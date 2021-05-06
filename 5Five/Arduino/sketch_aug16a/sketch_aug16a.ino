/*                  1 0   0 11    0 0
 *  f(A, B, C, D) = bC' + A'CD + B'D'
 *  
 *  0000  1
 *  0001  
 *  0010  1
 *  0011  1
 *  0100  1
 *  0101  1
 *  0110  
 *  0111  1
 *  1000  1
 *  1001  
 *  1010  1
 *  1011  
 *  1100  1
 *  1101  1
 *  1110  
 *  1111  
 */

void setup() {
  pinMode(11, OUTPUT); //r
  pinMode(10, OUTPUT); //g
  pinMode(9, OUTPUT); //b

  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
}

void loop() {
  digitalWrite(11, LOW);
  delay(1500);
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(6000);
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(3000);
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(1500);
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(3000);
  digitalWrite(11, HIGH);
  delay(3000);

  digitalWrite(11, HIGH);

  for(int i = 0; i < 3; i++){
    digitalWrite(10, LOW);
    delay(250);
    digitalWrite(10, HIGH);
    delay(250);
  }
  
}
