
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  float temperature = random(25, 35);
  Serial.println(temperature);
  delay(5000);

}
