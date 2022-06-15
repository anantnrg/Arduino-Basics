/*
Blink

Blinks an LED by turning it on for a second and then turning it off

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, blinks the inbuilt led on pin 13. An external
5mm LED can also be added with a 330 ohm resistor

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

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
