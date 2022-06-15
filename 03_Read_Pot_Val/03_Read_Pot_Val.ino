/*
Read Analog Value

Reads the value of potentiometer connected to Analog pin 0

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, reads the value of the potentiometer connected to analog pin 0
and prints the value to the serial monitor.

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

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
