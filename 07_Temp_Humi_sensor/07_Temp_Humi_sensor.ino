/*#include <LiquidCrystal_I2C.h>  // Include LiquidCrystal Library
#include "DHT.h"

#define DHTPIN 8

LiquidCrystal_I2C lcd(0x27, 16, 2); // Create an LCD object.
#define DHTTYPE DHT11   // Create a DHT object
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  lcd.begin(16,2); // Initialize the LCD
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  
  lcd.setCursor(0,0);
  lcd.print("Temp.: ");
  lcd.print(t);
  lcd.print((char)223);//shows degrees character
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humi.: ");
  lcd.print(h);
  lcd.print("%");
  
  delay(2000);
}*/

#include <dht.h>  // Include library
#define outPin 8  // Defines pin number to which the sensor is connected

dht DHT;      // Creates a DHT object

void setup() {
  Serial.begin(9600);
}

void loop() {
  int readData = DHT.read11(outPin);

  float t = DHT.temperature;  // Read temperature
  float h = DHT.humidity;   // Read humidity

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");
  Serial.print((t*9.0)/5.0+32.0); // Convert celsius to fahrenheit
  Serial.println("°F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

  delay(1000); // wait two seconds
}
