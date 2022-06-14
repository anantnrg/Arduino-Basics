// Variables
int ledPin = 13;


// The setup() function . It only runs once
void setup() {
  // Initialize Digital Pin 13 as an OUTPUT.
  pinMode(ledPin, OUTPUT);
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {
  digitalWrite(ledPin, HIGH);   //Turn the LED on 
  delay(1000);                  //Wait for a second
  digitalWrite(ledPin, LOW);    //Turn the LED off by making the voltage LOW
  delay(1000);                  //Wait for a second
}
