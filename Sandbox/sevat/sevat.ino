const int timer = 100;
int ledPins[] = {2, 3, 4, 5, 6, 7};
int buttonState = 0;


void setup(){
  for(int pin = 0; pin <= 5; pin++) {
  pinMode(ledPins[pin], OUTPUT);
  pinmode(8, INPUT)
  }
 } 

void loop() {
  buttonState = digitalRead(8)
  if (buttonState == LOW) {
  for(int i = 2; i <= 7; i++) {
  digitalWrite(i, HIGH); //Tenner og slukker LED på pinne 2
  delay(timer);
  digitalWrite(i, LOW);
  delay(timer); 

  }
  for(int i = 6; i >=3; i--) {
  digitalWrite(i, HIGH);
  delay(timer);
  digitalWrite(i, LOW);
  delay(timer);
  }
  }
  else {}
} 