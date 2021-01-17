void setup() {
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), change_dir, RISING);

}

int FADE_DELAY = 20;
int DELAY = 50;
int DIRECTION = 1;


int fading(int pin){
  for (int i = 0 ; i < FADE_DELAY; i++){
    digitalWrite(pin, HIGH);
    delay(FADE_DELAY - i);
    digitalWrite(pin, LOW);
    delay(i);
  }
}

int light_diodes(int direction){
  if (direction == 1){
    digitalWrite(22, HIGH);
    fading(28);
    delay(DELAY);
    digitalWrite(24, HIGH);
    fading(22);
    delay(DELAY);
    digitalWrite(26, HIGH);
    fading(24);
    delay(DELAY);
    digitalWrite(28, HIGH);
    fading(26);
    delay(DELAY);
  }
  else if (direction == 0){
    digitalWrite(28, HIGH);
    fading(22);
    delay(DELAY);
    digitalWrite(26, HIGH);
    fading(28);
    delay(DELAY);
    digitalWrite(24, HIGH);
    fading(26);
    delay(DELAY);
    digitalWrite(22, HIGH);
    fading(24);
    delay(DELAY);
  }
}
void loop() {
  light_diodes(DIRECTION);
}

int change_dir(){
  if (DIRECTION == 1){
    DIRECTION = 0;
  }
  else{
    DIRECTION = 1;
    
  }
}
