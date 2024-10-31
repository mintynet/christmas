#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LEDPIN1 1
#define LEDPIN2 0

boolean led1 = false;
boolean led2 = false;
int brightness = 0;
int fadeAmount = 5;
int counterMax = 2500;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  analogWrite(LEDPIN1,127);
  analogWrite(LEDPIN2,127);
//  digitalWrite(LEDPIN2,led2);
//  led2 = !led2;
//  digitalWrite(LEDPIN2,led2);
}

void loop() {
  front(50);
  //rear(50);
  /*digitalWrite(LEDPIN1,HIGH);
  digitalWrite(LEDPIN2,HIGH);
  delay(100);
  digitalWrite(LEDPIN1,LOW);
  digitalWrite(LEDPIN2,LOW);
  delay(100);*/
}

void rear(uint8_t wait) {
  for (int counter=1;counter<counterMax;counter++) {
    analogWrite(LEDPIN1, brightness); 
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);
  }
  analogWrite(LEDPIN1,127);   
  analogWrite(LEDPIN2,127);   
}

void front(uint8_t wait) {
  uint16_t i;
  for (i=0; i<5000;i++) {
    led2 = !led2;
    digitalWrite(LEDPIN1,led2);
    digitalWrite(LEDPIN2,led2);
    delay(wait);
  }
  for (i=0;i<10000;i++) {
    led2 = !led2;
    digitalWrite(LEDPIN1,led2);
    digitalWrite(LEDPIN2,led2);
    delay(5);
  }
}
