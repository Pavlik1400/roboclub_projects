#include<stdio.h>
#include<stdlib.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(52, 53); // RX, TX
AF_DCMotor motor2(3); //rotate motor
AF_DCMotor motor4(2); //main motor
int x = 0, y = 0, flag = 0, temp_val, left = 0, right =0;
char val;
int rotate_delay = 20;

void setup() {
  //bluetooth input
  mySerial.begin(9600);
  // bluetooth output
  Serial.begin(9600);
}

void loop() {
  if (mySerial.available())
  {
    val = mySerial.read();
    if (val == 'Y'){
      flag = 1;
      y = 0;
    }
    else if (val == 'X'){
      if (x > 10){
        x = x / 10;
      }
      if (y > 10){
        y = y / 10;
      }
      Serial.print(x);
      Serial.print("\n");
      Serial.print(y);
      Serial.print("\n\n");
      y = y - 50;
      if (y < 0){
        motor4.run(BACKWARD);
      }
      else{
        motor4.run(FORWARD);
      }
        motor4.setSpeed(5 * abs(y));

      x = x - 50;
      if (x < -25){
        motor2.run(BACKWARD);
        motor2.setSpeed(x * (-5));
        left = 1;
      }
      else if (x > 25){
        motor2.run(FORWARD);
        motor2.setSpeed(5 * x);
        right = 1;
      }
      else{
        if (left == 1){
          motor2.run(FORWARD);
          motor2.setSpeed(200);
          delay(rotate_delay);
          motor2.setSpeed(0);
          left = 0;
          right = 0;
        }
        else if (right == 1){
          motor2.run(BACKWARD);
          motor2.setSpeed(200);
          delay(rotate_delay);
          motor2.setSpeed(0);
          right = 0;
          left = 0;
        }
      }
      
      flag = 0;
      x = 0;
    }
    else if (flag == 0){
      if (val == '0'){
        temp_val = 0;
      }
      else if (val == '1'){
        temp_val = 1;
      }
      else if (val == '2'){
        temp_val = 2;
      }
      else if (val == '3'){
        temp_val = 3;
      }
      else if (val == '4'){
        temp_val = 4;
      }
      else if (val == '5'){
        temp_val = 5;
      }
      else if (val == '6'){
        temp_val = 6;
      }
      else if (val == '7'){
        temp_val = 7;
      }
      else if (val == '8'){
        temp_val = 8;
        }
      else if (val == '9'){
        temp_val = 9;
      }
      x = (x + temp_val) * 10;
      }
    else if (flag == 1){
      if (val == '0'){
        temp_val = 0;
      }
      else if (val == '1'){
        temp_val = 1;
      }
      else if (val == '2'){
        temp_val = 2;
      }
      else if (val == '3'){
        temp_val = 3;
      }
      else if (val == '4'){
        temp_val = 4;
      }
      else if (val == '5'){
        temp_val = 5;
      }
      else if (val == '6'){
        temp_val = 6;
      }
      else if (val == '7'){
        temp_val = 7;
      }
      else if (val == '8'){
        temp_val = 8;
      }
      else if (val == '9'){
        temp_val = 9;
      }
      y = (y + temp_val) * 10; 
    }   
  }
}
