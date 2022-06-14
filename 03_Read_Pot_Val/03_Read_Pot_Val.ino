// The setup() function . It only runs once
void setup() {
    // Start a serial connection at 9600 baud
    Serial.begin(9600);
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {
  // Read the potentiometer's value on Analog Pin 0
  int sensorValue = analogRead(A0);
  // Print out the value of the potentiometer to the serial monitor
  Serial.println(sensorValue);
  delay(100);        // Add a delay for stability
}
