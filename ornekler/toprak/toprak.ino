int sensorPin = A0;                  //Sensörün takılacağı pin
int buzzerPin = D2;                  //Buzzerın takılacağı pin
int veriToprak;                           //Sensörden okunan verinin tutulacağı değişken
int nemEsikDeger = 50;
void setup() {
  pinMode(sensorPin, INPUT);        //Sensörün takılacağı pini INPUT olarak ayarlıyoruz.
  pinMode(buzzerPin, OUTPUT);       //Buzzerın takılacağı pini OUTPUT olarak ayarlıyoruz.
  Serial.begin(115200);
}

void loop() {

  veriToprak = 1023-analogRead(sensorPin); //Sensörden analog veriyi okuyoruz
  Serial.print("toprak Sensor: ");
  Serial.print(veriToprak);
  Serial.print("\n"); if (veriToprak < nemEsikDeger) {         //Sensör verisi eşik değerini geçerse if içerisindeki kodlar uygulanır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
  else {                            //Sensör verisi eşik değerinden küçük olursa if içerisindeki kodlar uygulanır.
    digitalWrite(buzzerPin, LOW);
  }
}
