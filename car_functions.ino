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
void forward(){
  analogWrite(5, 230);
  digitalWrite(6, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void backward(){
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

void turn_180() {
  right();
  delay(470);
}
