#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом 


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(100);
  motor1.run(RELEASE);
  motor2.setSpeed(100);
  motor2.run(RELEASE);
  motor3.setSpeed(100);
  motor3.run(RELEASE);
  motor4.setSpeed(100);
  motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.setSpeed(100); // Задаем скорость движения
  motor1.run(BACKWARD); // Задаем движение вперед
  motor2.setSpeed(100); // Задаем скорость движения
  motor2.run(BACKWARD); // Задаем движение вперед
  motor3.setSpeed(100); // Задаем скорость движения
  motor3.run(BACKWARD); // Задаем движение вперед
  motor4.setSpeed(100); // Задаем скорость движения
  motor4.run(BACKWARD); // Задаем движение вперед
}
