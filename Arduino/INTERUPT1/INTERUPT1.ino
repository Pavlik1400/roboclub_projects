void setup() {
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), change_dir, RISING);
}

//int pins = {22, 24, 26, 28, 30}
int DELAY = 200;

volatile int direction = 1;

int light_diodes(int direction){
  if (direction == 1){
    digitalWrite(22, HIGH);
    digitalWrite(28, LOW);
    delay(DELAY);
    digitalWrite(24, HIGH);
    digitalWrite(22, LOW);
    delay(DELAY);
    digitalWrite(26, HIGH);
    digitalWrite(24, LOW);
    delay(DELAY);
    digitalWrite(28, HIGH);
    digitalWrite(26, LOW);
    delay(DELAY);
    digitalWrite(30, HIGH);
    digitalWrite(28, LOW);
    delay(DELAY);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
  else if (direction == 0){
    digitalWrite(30, HIGH);
    digitalWrite(22, LOW);
    delay(DELAY);
    digitalWrite(28, HIGH);
    digitalWrite(30, LOW);
    delay(DELAY);
    digitalWrite(26, HIGH);
    digitalWrite(28, LOW);
    delay(DELAY);
    digitalWrite(24, HIGH);
    digitalWrite(26, LOW);
    delay(DELAY);
    digitalWrite(22, HIGH);
    digitalWrite(24, LOW);
    delay(DELAY);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(26, LOW);
    digitalWrite(24, LOW);
    digitalWrite(22, LOW);
  }
}
void loop() {
  light_diodes(direction);
}

int change_dir(){
  if (direction == 1){
    direction = 0;
  }
  else{
    direction = 1;
  }
}

