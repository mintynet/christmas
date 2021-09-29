int delayCount = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
