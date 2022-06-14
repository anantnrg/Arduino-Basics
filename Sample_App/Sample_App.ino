/*
 Anant's TechLogs

 This sketch is based on the video series Arduino For Beginners

 In this sketch, all the knowledge about the different components and software design are used
 to build an application that can be used as a base for  projects in the real world.
 */
// EXTERNAL  LIBRARIES
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "intro.h"


//VARIABLES
//Pin Definitions
const int ledPin = 13;
const int buzzer = 8;
const int trigPin = 7;
const int echoPin = 6;
const int btn_pin = 4;

//Other Variables
int x = 0; 
long duration;
int distance;
bool led_state = false  ;
bool buzzer_state = true;
int is_btn_pressed = 1;
int tempo = 80;
int melody[] = {

  NOTE_D4, -8, NOTE_G4, 16, NOTE_C5, -4, 
  NOTE_B4, 8, NOTE_G4, -16, NOTE_E4, -16, NOTE_A4, -16,
  NOTE_D5, 2,
  
};
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

String str_copyr = "Copyright Anant's TechLogs"; 

// LCD definition
LiquidCrystal_I2C lcd(0x27,16,2);

// setup() function. This only runs once during the start of the code
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(btn_pin, INPUT);
  lcd.init();                  
  lcd.backlight();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  //Display welcome lines on the LCD
  lcd_print_msg();
  play_intro_melody();
  lcd.clear();

  // Timer Interrupt Settings
 /* cli();                      
  TCCR1A = 0;
  TCCR1B = 0;
    
  TCCR1B |= B00000100;
 
  TIMSK1 |= B00000010;
  
  OCR1A = 31250;
  sei();   */                 


}

// loop() function. This runs over and over again.
void loop()
{
  check_distance();
  emergency();
}

//This function prints a message to the lcd
void lcd_print_msg()
{
  lcd.setCursor(14, 0);
  lcd.print(str_copyr);

  for (int positionCounter = 0; positionCounter < 38; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  lcd.clear(); 

  lcd.setCursor(0, 0);
  lcd.print("Threat Detector"); 
}


//This function plays the intro melody at the start of the program
void play_intro_melody()
{
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }


    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
    
  }
  
}


//This function finds out the distance between an object and the ultrasonic sensor by calculating the time it takes
//to recieve the bounced signal and sets it to a variable
void check_distance()
{
  // Find the distance using the ultrasonic sensor and save it to a variable
    digitalWrite(trigPin, LOW);
    digitalWrite(ledPin, HIGH);
    tone(buzzer, 2000);
    delay(250);
    digitalWrite(ledPin, LOW);
    noTone(buzzer);
    
  }
}

/*
ISR(TIMER2_COMPA_vect){

  
  buzzer_state = !buzzer_state;
  int is_btn_pressed = digitalRead(btn_pin);
  if (is_btn_pressed == 1) {

    TCNT1  = 0;
    led_state = !led_state;
    tone(buzzer, 1000);    
    digitalWrite(13,led_state); 
    delay(500);
    //led_state = !led_state;
    noTone(buzzer);
   // digitalWrite(13,led_state);
  }
  else{
    digitalWrite(13,LOW);
  }

}
 */
