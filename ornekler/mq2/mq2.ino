
int Buzzer = D2;
int Gas_analog = A0;

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);

  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");

  if (gassensorAnalog > 150) {
    Serial.println("Gas");
    digitalWrite (Buzzer, HIGH) ; //send tone
    delay(1000);
    digitalWrite (Buzzer, LOW) ;  //no tone
  }

  delay(100);
}
