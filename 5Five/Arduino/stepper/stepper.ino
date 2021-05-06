// https://www.aranacorp.com/en/control-a-stepper-motor-with-arduino/

#include <Stepper.h> 

Stepper st(2048, 8, 10, 9, 11);

void setup() {   
	st.setSpeed(10);
	Serial.begin(9600); //No se pa que
	  
	pinMode(7, INPUT_PULLUP);
}

void loop() {
	if(digitalRead(7) == LOW) {
		for(short x = 0; x < 5; x++) {
			st.step(500);
			st.step(-700);
		}
	}
}
