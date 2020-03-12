int another;

void move_in_direction(int direction, int DELAY){
  int PINS[4];
  if (direction == 0){
    PINS[0] = 2; PINS[1] = 3; PINS[2] = 4; PINS[3] = 5;
  }
  else if (direction == 1){
    PINS[0] = 5; PINS[1] = 4; PINS[2] = 3; PINS[3] = 2;
  }

  for(int i = 0; i < 4; i++){
    for (int j = 0 ; j < 4; j++){
      digitalWrite(PINS[j], LOW);
    }
//    another = i + 1;
//    if (another > 3){
//      another = 0;
//    }
//    digitalWrite(PINS[another], HIGH);
    digitalWrite(PINS[i], HIGH);
    delay(DELAY);
    for (int j = 0 ; j < 4; j++){
      digitalWrite(PINS[j], LOW);
      
    }
  }
}

void move_on_degree(int degree, int DELAY, int direction){
  int times = degree * DELAY * 0.75;
  for (int i = 0; i < times; i++){
    move_in_direction(direction, DELAY);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

int DELAY = 2;
void loop() {
  move_on_degree(180, DELAY, 1);
  delay(1000);
  move_on_degree(180, DELAY, 0);
  delay(1000);

}
