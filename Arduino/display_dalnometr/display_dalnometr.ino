//Тестировалось на Arduino IDE 1.0.1
#define Trig 9
#define Echo 8
#define ledPin 13
#include <PCD8544.h>

PCD8544 lcd;

void setup() 
{  
  pinMode(Trig, OUTPUT); //инициируем как выход 
  pinMode(Echo, INPUT); //инициируем как вход 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
  lcd.begin(84, 48);
  /* задаем скорость общения. В нашем случае с компьютером */
} 
float impulseTime=0; 
float distance_sm=0; 

void loop() 
{  
  
    
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10);  
  digitalWrite(Trig, LOW); 
  impulseTime=pulseIn(Echo, HIGH);  
  distance_sm=impulseTime/58; 
  /*if(distance_sm < 10){
    distance_sm = distance_sm / 10;
    */
  //Serial.println(distance_sm); 
  /*if (distance_sm<30) 
  {     
    digitalWrite(ledPin, HIGH); 
  }  
  else 
  {   
    digitalWrite(ledPin, LOW);  
  } */  

  lcd.setContrast(60);
  lcd.setCursor(0, 1);
  lcd.print(distance_sm);
  delay(100); 

}
