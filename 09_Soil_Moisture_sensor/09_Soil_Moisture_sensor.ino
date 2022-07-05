int sensorPin = A0; 
int sensorValue;  
int limit = 300; 
int ledPin = 13;

void setup() {
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 
 if (sensorValue<limit) {
 digitalWrite(ledPin, HIGH); 
 }
 else {
 digitalWrite(ledPin, LOW); 
 }
 
 delay(1000); 
} 
