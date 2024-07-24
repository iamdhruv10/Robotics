// LED Siren

void setup() {
  // What pinMode we use (Input/Output)
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  //How much power to give to which pin
  digitalWrite(10, HIGH);
  digitalWrite(7,HIGH);
  // Delay 200 milliseconds or .2 second
  delay(200);
  digitalWrite(10, LOW);
  digitalWrite(7,LOW);
  digitalWrite(3,HIGH);
  delay(200);
  digitalWrite(3,LOW);
}
