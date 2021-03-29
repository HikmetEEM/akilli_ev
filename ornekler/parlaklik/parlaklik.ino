
void setup()
{
Serial.begin(115200);
pinMode(D0,INPUT);

}
void loop()
{
Serial.println(digitalRead(D0));
}
