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

  pinMode(5, OUTPUT);
  pinMode(4, INPUT);

  digitalWrite(5, h);
}

void loop() {
  cero();
  delay(r);
  uno();
  delay(r);
  dos();
  delay(r);
  tres();
  delay(r);
  cuatro();
  delay(r);
  cinco();
  delay(r);
  seis();
  delay(r);
  siete();
  delay(r);
  ocho();
  delay(r);
  nueve();
  delay(r);
}

void apagar() {
  digitalWrite(a, l);
  digitalWrite(b, l);
  digitalWrite(c, l);
  digitalWrite(d, l);
  digitalWrite(e, l);
  digitalWrite(f, l);
  digitalWrite(g, l);
}

void cero() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, l);
}

void uno() {
  digitalWrite(a, l);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, l);
  digitalWrite(e, l);
  digitalWrite(f, l);
  digitalWrite(g, l);
}

void dos() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, l);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, l);
  digitalWrite(g, h);
}

void tres() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, l);
  digitalWrite(f, l);
  digitalWrite(g, h);
}

void cuatro() {
  digitalWrite(a, l);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, l);
  digitalWrite(e, l);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

void cinco() {
  digitalWrite(a, h);
  digitalWrite(b, l);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, l);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

void seis() {
  digitalWrite(a, h);
  digitalWrite(b, l);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

void siete() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, l);
  digitalWrite(e, l);
  digitalWrite(f, l);
  digitalWrite(g, l);
}

void ocho() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, h);
  digitalWrite(f, h);
  digitalWrite(g, h);
}

void nueve() {
  digitalWrite(a, h);
  digitalWrite(b, h);
  digitalWrite(c, h);
  digitalWrite(d, h);
  digitalWrite(e, l);
  digitalWrite(f, h);
  digitalWrite(g, h);
}
