void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  analogWrite(11, 255 - 0);
  analogWrite(10, 255 - 0);
  analogWrite(9, 255 - 0);
}

int n = 1;
bool primo = true;

void loop() {
  if(n > 1)
            for(int i = 2; i < n; i++){
                if(n % i == 0){
                    primo = false;
                    break;
                }
            }

        if(primo){
            analogWrite(10, 255 - 15);
            delay(1000);
        }
        else{
            analogWrite(11, 255 - 15);
            delay(1000);
        }
            

        primo = true;

        
        n++;

        
        analogWrite(11, 255 - 0);
        analogWrite(10, 255 - 0);
        delay(1000);
}
