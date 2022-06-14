// Variables
int ledPin = 13;  // LED is attached to digital pin 13

// The setup() function . It only runs once
void setup() {                
  pinMode(ledPin, OUTPUT);
  // Attach an interrupt and tell it which function to call during an interrupt
  attachInterrupt(0, turn_on_led, HIGH);
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {
  // Turn off the LED
  digitalWrite(ledPin, LOW);
  // Wait for an interrupt
  delay(3000);
}

// Interrupt Servie Routine (ISR) which is to be called when an interrupt occurs
void turn_on_led() {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
}
