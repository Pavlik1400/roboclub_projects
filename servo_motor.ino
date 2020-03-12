// Include servo library and init control pin
#include <Servo.h>
int myservoPin = 7;
int servoPin = 6;

Servo myServo;
void setup() {
  myServo.attach(myservoPin);
  pinMode(servoPin, OUTPUT);
}

void turn_servo(int degree, int direction, int DELAY){
  int freq = 0.5;
  int counter;
  if (direction == 0){
    freq = 0.5;
  }
  else if (direction == 1){
    freq = 2.5;
  }
  counter = degree / 15;
  for (int j = 0; j < counter; j++){
    digitalWrite(servoPin, HIGH);
    delay(freq);
    digitalWrite(servoPin, LOW);
    delay(DELAY-freq);
  }
}

void loop() {
  turn_servo(360, 0, 20);
  myServo.write(180);
  delay(1000);
  turn_servo(360, 1, 20);
  myServo.write(0);
  delay(1000);
}
