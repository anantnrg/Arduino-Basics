/*
Pin change interrupts

Pin change interrupts

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, waits for a value change on pin 2 (interrupt_pin 0)
which occurs when a button is pressed. It then turns on an LED connected to Digital Pin 13

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

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
