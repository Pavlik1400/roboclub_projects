#include<stdio.h>
#include<stdlib.h>

int x = 0,y = 0, flag = 0, temp_val;
char val;
int DIG = 2;

void setup() {
  // bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available())
  {
     val = Serial.read();
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
      if (y < 40){
        Serial.print("GOO\n");
        digitalWrite(DIG, HIGH);
      }
      else{
        Serial.print("NOO\n");
        digitalWrite(DIG, LOW);
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
