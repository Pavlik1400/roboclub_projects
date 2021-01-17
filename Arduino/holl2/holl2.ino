void setup() {
  pinMode(7, OUTPUT);
}
int flag = 0;
void loop() {
  delay(1000);
  digitalWrite(7, HIGH); 
  delay(1000);
  digitalWrite(7, LOW);
}
