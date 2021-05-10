#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
bool sanalBtn = 0;
bool realBtn = 0;
bool role = 1;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "OOIf08f_mrjdIzj4KQyFw9GTQiCPsRqt";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HIKMET";
char pass[] = "1999_XqC_2001";

#define btnPin 5
#define rolePin 2

void setup()
{

  // Debug console
  Serial.begin(9600);
  pinMode(btnPin, INPUT);
  pinMode(rolePin, OUTPUT);
  digitalWrite(rolePin, role);
  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V2)
{
  // You'll get uptime value here as result of syncAll()
  Serial.print("sanal buton: ");
  Serial.println(param.asInt());
  sanalBtn = param.asInt();
  roleKonum();
}
void butonOku() {
  if (realBtn != digitalRead(btnPin))
  {
    realBtn = digitalRead(btnPin);
    Serial.print("anahtar: ");
    Serial.println(realBtn);
    roleKonum();
  }
}
void roleKonum() {
  role = !role;
  digitalWrite(rolePin, role);
  Blynk.virtualWrite (V2, role);
}
void loop() {
  Blynk.run();
  butonOku();
  delay (200);
}
