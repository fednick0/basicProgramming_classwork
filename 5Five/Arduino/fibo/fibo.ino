void setup() {
  
  pinMode(11, OUTPUT); // r
  pinMode(10, OUTPUT); //g
  pinMode(9, OUTPUT); // b

  analogWrite(11, 255 - 0);
  analogWrite(10, 255 - 0);
  analogWrite(9, 255 - 0);
}

int fibo = 0;
int a = 0;
int b = 1;
int n = 1;
int ban = 0;


void loop() {
        if(n == 1 || ban == 1){
            fibo = a + b;
            a = b;
            b = fibo;

            ban = 0;
        }

        if(n == fibo){
            analogWrite(10, 255 - 10);
            delay(1000);
            
            ban = 1;
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
