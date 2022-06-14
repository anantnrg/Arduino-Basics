// Variables
int led = 9;           // The PWM pin the LED is attached to
int brightness = 0;    // How bright the LED is
int fadeAmount = 5;    // How much amount to fade the LED by

// The setup() function . It only runs once
void setup() {
  // Initialize Digital Pin 9 as an OUTPUT.
  pinMode(led, OUTPUT);
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {
  // Set the brightness of pin 9:
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount; // Fade the LED from dim to bright

  // Fade the LED from bright to dim
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // Wait 30 ms to see the LED brighten and dim
  delay(30);
}
