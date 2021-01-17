#include <PCD8544.h>
#include <stdio.h>

using namespace std;

const int line = 6;

 PCD8544 lcd;
void setup() {
   lcd.begin(84, 48);
}
void loop() {
  lcd.setContrast(60);
  for(int i =0 ; i < line; ++i){
    lcd.setCursor(0, i);
    lcd.print("hello world");
    
    delay(200);
  }
  for(int i =0 ; i < line; ++i){
    lcd.setCursor(0, i);
    lcd.clearLine();
    delay(200);
  }
  //lcd.print("hello world");
  //lcd.setCursor(0, 1);
  //lcd.print("     To");
  //lcd.setCursor(0,2);
  //lcd.print("ElectronicsHobbyists.com");
  //delay(200);
 }
