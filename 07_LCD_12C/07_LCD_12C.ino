// External Imports
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Define the LCD
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// The setup() function . It only runs once
void setup()
{
  lcd.init();                      // Initialize the lcd 
  lcd.backlight();
  // Begin serial communication at 9600 baud
  Serial.begin(9600);

}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop()
{
 if (Serial.available()) {
    // Wait for a message to arrive
    delay(100);
    // Clear the LCD screen
    lcd.clear();
    // Read all the inputted characters
    while (Serial.available() > 0) {
      // Display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
