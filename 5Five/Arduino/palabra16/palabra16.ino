int a = 13;
int b = 12;
int c = 11;
int d = 10;
int e = 9;
int f = 8;
int g = 7;

int r = 1000;
int h = 1; //encender
int l = 0; //apagar

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  _a();
  delay(1000);
  _u();
  delay(1000);
  _t();
  delay(1000);
  _o();
  delay(1000);
  _r();
  delay(1000);
  _r();
  delay(1000);
  _e();
  delay(1000);
  _g();
  delay(1000);
  _u();
  delay(1000);
  _l();
  delay(1000);
  _a();
  delay(1000);
  _d();
  delay(1000);
  _o();
  delay(1000);
  _r();
  delay(1000);
  _e();
  delay(1000);
  _s();
  delay(1000);
}

//   AUTORREGULADORES
void _a(){
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, l);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _u(){
  digitalWrite(a, l);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, l);
}

//   AUTORREGULADORES
void _t(){
  digitalWrite(a, l);
  digitalWrite(b, l);
  digitalWrite(c, l);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _o(){
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, l);
}

//   AUTORREGULADORES
void _r(){
  digitalWrite(a, l);
  digitalWrite(b, l);
  digitalWrite(c, l);
  digitalWrite(d, l);
  digitalWrite(e, h);
  digitalWrite(f, l);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _e(){
  digitalWrite(a, h);
  digitalWrite(b, l);
  digitalWrite(c, l);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _g(){
  digitalWrite(a, h);
  digitalWrite(b, l);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _l(){
  digitalWrite(a, l);
  digitalWrite(b, l);
  digitalWrite(c, l);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, l);
}

//   AUTORREGULADORES
void _d(){
  digitalWrite(a, l);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, l);
  digitalWrite(g, h);
}

//   AUTORREGULADORES
void _s(){
  digitalWrite(a, h);
  digitalWrite(b, l);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, l);
  digitalWrite(f, h);
  digitalWrite(g, h);
}
