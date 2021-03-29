int sensorPin = A0;                //Sensörü bağlayacağımız pin
int esikDegeri = 500;              //Su miktarı için eşik değeri
int buzzerPin = D2;                 //Buzzerı bağlayacağımız pin
int veriYagmur;                         //Sensörden okuduğumuz değer

void setup() {
  pinMode(buzzerPin, OUTPUT);      //Buzzer bağladığımız pini OUTPUT olarak ayarlıyoruz.
  Serial.begin(115200);
}
void loop() {
  veriYagmur = 1023 - analogRead(sensorPin); //Sensörden analog veriyi okuyoruz.
  Serial.print("yagmur Sensor: ");
  Serial.print(veriYagmur);
  Serial.print("\n");
  if (veriYagmur > esikDegeri) {         //Sensör verisi eşik değerini geçerse if içerisindeki kodlar uygulanır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
  else {                           //Sensör verisi eşik değerinden küçük olursa if içerisindeki kodlar uygulanır.
    digitalWrite(buzzerPin, LOW);
  }
}
