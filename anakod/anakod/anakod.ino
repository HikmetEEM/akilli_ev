#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define BLYNK_PRINT Serial
char auth[] = "kkqN8sP_2Fv_PBKl5T5PPfn1CP4PWe_B";
char ssid[] = "Furkan Parlak";
char pass[] = "RV7CUUPTJTFC";
int MUXPinS0 = D5;
int MUXPinS1 = D6;
int MUXPinS2 = D7;
#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;



void isinem()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}
 
void setup()
{
  Serial.begin(115200);
  pinMode(MUXPinS0, OUTPUT);
  pinMode(MUXPinS1, OUTPUT);
  pinMode(MUXPinS2, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, isinem);
}

void loop()
{
  
  
  Blynk.run();
  timer.run();
}

float getAnalog(int MUXyPin) {
  digitalWrite(MUXPinS2, HIGH && (MUXyPin & B00000100));
  digitalWrite(MUXPinS1, HIGH && (MUXyPin & B00000010));
  digitalWrite(MUXPinS0, HIGH && (MUXyPin & B00000001));
  return (float)analogRead(A0);
}
