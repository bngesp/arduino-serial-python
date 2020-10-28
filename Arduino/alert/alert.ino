
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  float temperature = random(25, 35);
  //Serial.println(temperature);
  if(temperature > 30)
    Serial.println("ALERT");
    
  delay(5000);

}
