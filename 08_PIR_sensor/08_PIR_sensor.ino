int ledPin = 13;                // choose the pin for the LED
int pirPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int beep = 0;
int buzzerPin = 12;
int val = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  detect();
  
}

void detect() {
  int val = digitalRead(pirPin);
  delay(500);
  Serial.println(val);
  beep = 0;

  if (val == 1) {
   while (beep < 5) {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 2000);
      delay(500);
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
      delay(500);
      beep++;
     }
  }
}
