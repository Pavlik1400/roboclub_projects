void setup() {
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), change_dir, RISING);
}

int DELAY = 300, pin_current = 22, pin_next = 30;

volatile int direction = 1;

int light_diodes(int direction){
  if (direction == 1){
    digitalWrite(pin_current, HIGH);
    digitalWrite(pin_next, LOW);
    for(int i = 0; i < 10; i++){
      digitalWrite(pin_next, HIGH);
      delay(10 - i);
      digitalWrite(pin_next, LOW);
      delay(10 + i);
      }
    if (pin_current == 30){
      pin_current = 22;
      }
    else {
      pin_current += 2;
      }
    if (pin_next == 30){
      pin_next = 22;
      }
    else {
      pin_next += 2;
      }
  }
  else if (direction == 0){
    digitalWrite(pin_next, HIGH);
    digitalWrite(pin_current, LOW);
    for(int i = 0; i < 10; i++){
      digitalWrite(pin_current, HIGH);
      delay(10 - i);
      digitalWrite(pin_current, LOW);
      delay(10 + i);
      }
    if (pin_current == 22){
      pin_current = 30;
      }
    else {
      pin_current -= 2;
      }
    if (pin_next == 22){
      pin_next = 30;
      }
    else {
      pin_next -= 2;
      }
  }
  delay(DELAY);
}
void loop() {
  light_diodes(direction);
  //delay(DELAY);
}

int change_dir(){
  delay(30);
  if (digitalRead(2)){
    if (direction == 1){
      direction = 0;
    }
    else{
      direction = 1;
    }
  }
 
}
