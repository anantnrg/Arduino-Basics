
const int gasPin = A0;
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gas Detector");
  delay(3000);
  lcd.clear();
  lcd.print("Let Gas Sensor");
  lcd.setCursor(0, 1);
  lcd.print("heat up for 20s.");
  delay(20000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor heated up");
  delay(2000);
  lcd.clear();

}

void loop(){
  read_sensor();
}

void read_sensor() {
  int gasValue = analogRead(gasPin);
  delay(300);
  lcd.setCursor(0, 0);
  lcd.print("Gas Value:" );
  lcd.print(gasValue);
  lcd.setCursor(0, 1);
  if (gasValue >= 400){
    lcd.print("Gas Detected !!!");
  }

  else {
    lcd.print("Gas Level Normal");
  }
 
}
