// Variables go here
// data_type variable_name = value

int button = 0;

void setup() {
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // Variable button will read how much voltage we are getting from pin 4
  button = digitalRead(4);
  if(button == 1) {
    digitalWrite(10, HIGH);
    delay(200);
    digitalWrite(10,LOW);
    delay(200);
  }

  else {
    digitalWrite(10, LOW);
  }
}
