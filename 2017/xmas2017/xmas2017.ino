int led1 = 2;
int led2 = 1;
int led3 = 0;
int brightness = 0;
int fadeAmount = 5;
int counterMax = 500;
int interval = 90;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  for (int counter=1;counter<counterMax;counter++)
  {
    analogWrite(led1, brightness); 
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    delay(20);   
    analogWrite(led2, brightness);    
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    delay(20);   
    analogWrite(led3, brightness);    
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    delay(20);
  } 
  for (int counter=1;counter<counterMax/10;counter++)
  {
    digitalWrite(led1, HIGH); 
    delay(interval);
    digitalWrite(led2, HIGH);
    delay(interval);
    digitalWrite(led3, HIGH);  
    delay(interval);  
    digitalWrite(led2, LOW);   
    delay(interval);      
    digitalWrite(led3, LOW);  
    delay(interval);
    digitalWrite(led1, LOW);   
    delay(interval);     
    digitalWrite(led2, HIGH);   
    delay(interval);      
    digitalWrite(led3, HIGH);  
    delay(interval);
    digitalWrite(led2, LOW);   
    delay(interval);      
    digitalWrite(led3, LOW);  
    delay(interval);
  }
  interval = 1;
  for (int counter=1;counter<counterMax*10;counter++)
  {
    digitalWrite(led1, HIGH); 
    delay(interval);
    digitalWrite(led2, HIGH);
    delay(interval);
    digitalWrite(led3, HIGH);  
    delay(interval);  
    digitalWrite(led2, LOW);   
    delay(interval);      
    digitalWrite(led3, LOW);  
    delay(interval);
    digitalWrite(led1, LOW);   
    delay(interval);     
    digitalWrite(led2, HIGH);   
    delay(interval);      
    digitalWrite(led3, HIGH);  
    delay(interval);
    digitalWrite(led2, LOW);   
    delay(interval);      
    digitalWrite(led3, LOW);  
    delay(interval);
  }
  interval = 90;
}
