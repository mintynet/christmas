#define POWER 1

#if POWER
#include <avr/sleep.h>
boolean Power __attribute__ ((section (".noinit")));

void PowerDown () {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  ADCSRA &= ~(1<<ADEN);     // Turn off ADC to save power
  sleep_enable();
  sleep_cpu();
}
#endif

int delayCount = 0;

void setup() {
#if POWER
  Power = !Power;
  if (Power) {
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(2,OUTPUT);
  } else {
    PowerDown();
  }
#else
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
#endif  
}

void loop() {
  digitalWrite (2,HIGH);
  delay(delayCount/20);
  digitalWrite (1,HIGH);
  delay(delayCount/20);
  digitalWrite (0,HIGH);
  delay(delayCount/10);
  digitalWrite (2,LOW);
  delay(delayCount/20);
  digitalWrite (1,LOW);
  delay(delayCount/20);
  digitalWrite (0,LOW);
  delay(delayCount/10);
  delayCount++;
  if (delayCount > 1001) {
    delayCount = 0;
  }
}
