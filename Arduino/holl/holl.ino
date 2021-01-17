int hallSensorPin = A2;      
int ledPin =  13;     
int state = 0;      
   
void setup() {   
  pinMode(ledPin, OUTPUT);         
  pinMode(hallSensorPin, INPUT);
  Serial.begin(9600);        
} 
void loop(){      
  state = analogRead(hallSensorPin);   
  
  Serial.println(state);



  /*if (state == HIGH) {             
  digitalWrite(ledPin, HIGH);     
  }    
  else {     
  digitalWrite(ledPin, LOW);    
  }*/
}
