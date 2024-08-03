int deg = 0;
int i = 0;

int ls = 0;
int ms = 0;
int rs = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

int turn_degrees(int degree) {
  int b = 3 * degree;
  int c = round(b);
  return c;
}

int n_degrees(int sides) {
  int a = 180*(sides-2)/sides;
  int b = a - 90;
  int c = 90 - b;
  return c;
}

void forward(){
  analogWrite(5, 217);
  digitalWrite(6, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void back(){
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void brake(){
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
}

void right(){
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void left(){
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
}


void left_90() {
  left();
  delay(270);
}

void right_90() {
  right();
  delay(230);
}

void oct(int seconds) {
  int i = 0;
  if (i < 8){
    forward();
    delay(seconds * 1000);
    left();
    delay(turn_degrees(45));
  }

}

void hex(int seconds) {
  int i = 0;
  if (i < 6){
    forward();
    delay(seconds * 1000);
    left();
    delay(turn_degrees(60));
  }

}

void penta(int seconds) {
  int i = 0;
  if (i < 5){
    forward();
    delay(seconds * 1000);
    left();
    delay(turn_degrees(72));
  }
}

void tri(int seconds) {
  int i = 0;
  if (i < 3){
    forward();
    delay(seconds * 1000);
    left();
    delay(turn_degrees(120));
  }
}

void square(int seconds){
  int i = 0;
  if (i < 4) {
    forward();
    delay(seconds * 1000);
    left_90();
  }
}

void rect(int seconds_a, int seconds_b) {
  int i = 0;
  if (i < 2) {
  forward();
  delay(seconds_a * 1000);
  left_90();
  forward();
  delay(seconds_b * 1000);
  left_90();
  i += 1;
  } 
}


void loop() {
  square(1);
  brake();
  delay(1000);
}
