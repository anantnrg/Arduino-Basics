# Arduino Basics

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)  ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

This repository contains all the Arduino sketches and circuit diagrams used in my video tutorial series 'Arduino For Beginners'.

<!-- TOC -->

- [Arduino Basics](#arduino-basics)
  - [Commonly used pins for each boards](#commonly-used-pins-for-each-boards)
  - [Pinouts](#pinouts)
    - [Arduino Mega](#arduino-mega)
    - [Arduino Uno Rev 3](#arduino-uno-rev-3)
    - [Arduino Nano](#arduino-nano)
    - [Arduino Leonardo](#arduino-leonardo)
  - [Examples](#Examples)
    - [Blink](#Blink)
      - [Code](#Blink-Code)
      - [Schematic](#Blink-Schematic)
    - [Fade](#Fade) 
      - [Code](#Fade-Code)
      - [Schematic](#Fade-Schematic)
    - [Analog Potentiometer](#Read-Analog-Potentiometer-value)
      - [Code](#Potentiometer-Code) 
      - [Schematic](#Potentiometer-Schematic)  
    - [Play Melody using a Piezo Buzzer](#Play-a-Melody-using-a-Piezo-Buzzer) 
      - [Code](#Pizeo-buzzer-Code)
      - [Schematic](#Pizeo-buzzer-Schematic)
    - [Pin Change Interrupts](#Pin-Change-Interrupts)
      - [Code](#Pin-Change-Interrupt-Code)
      - [Schematic](#Pin-Change-Interrupt-Schematic) 
    - [LCD I2C](#LCD)
      - [Code](#LCD-Display-Code)
      - [Schematic](#LCD-Display-Schematic)  
    - [PIR Sensor](#PIR-Sensor)
      - [Code](#PIR-Sensor-Code)
      - [Schematic](#PIR-Sensor-Schematic) 

<!-- /TOC -->
It contains 10 different examples using the Arduino Mega and various different components such as LEDs, pushbuttons, piezo buzzers, LCDs etc.. These example should work fine with any Arduino board with the only difference being the pins which are to be used.

## Commonly used pins for each boards

| Boards | Arduino Mega 2560 | Arduino Uno | Arduino Nano | Arduino Leonardo |
| ------ | ----------------- | ----------- | ------------ | ----------- |
| Inbuilt LED Pin | 13 | 13 | 13 | 13
| Digital Pins | 1, 2, 3, 5, 6, 7, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 63, and 64 | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, and 13 | D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, and D13 | 4, 6, 8, 9, 10, and 12 |
| Analog Pins | A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14 and A15 | A0, A1, A2, A3, A4, and A5 | A0, A1, A2, A3, A4, A5, A6 and A7 | A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, and A11 |
| Pin Interrupts  | 2, 3, 18, 19, 20, 21 | 2, 3 | 2, 3 | 0, 1, 2, 3, 7|
| I2C SDA and SCL | 20, 21 | A4, A5 | A4, A5 | 3, 2 |

## Pinouts

### Arduino Mega

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Arduino-Mega-Pinout.png?raw=true)

### Arduino Uno Rev 3

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Arduino-Uno-Pinout.png?raw=true)

### Arduino Nano

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Arduino-Nano-Pinout.png?raw=true)

### Arduino Leonardo

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Arduino-Leonardo-Pinout.png?raw=true)


## Examples

### Blink

This example blinks an LED connected to Digital Pin 13 by turning on the LED for a second or 1000 milliseconds ,
then turning it off for another 1 second.

#### Blink Code

```
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
```

#### Blink Schematic
![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/led_blink_diag.jpg?raw=true)


### Fade

This example fades an LED in and out using a Pulse Width Modulation (PWM) signal
from Digital Pin 9.

#### Fade Code

```
/*
Fade

Fades an LED by using a PWM signal

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, fades and LED connected to Digital pin 9. It uses PWM
signals to control the fading.

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

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
```

#### Fade Schematic
![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/led_fade_diag.jpg?raw=true)


### Read Analog Potentiometer value

In this example, we read the value of a potentiometer which is also known as a variable resistor
using the analogRead() function. The potentiometer is connected to Analog Pin 0 or A0.

#### Potentiometer Code

``` 
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
```

#### Potentiometer Schematic

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Analog_pot.jpg?raw=true)


### Play a melody using a piezo buzzer

This example uses the tone() function to play a melody using a piezo buzzer connected to 
Digital Pin 7. An additional file called ```pitches.h``` contains the tones which are to 
be played.

#### Pizeo buzzer Code

```
/*
Melody

Plays a simple melody using a piezo buzzer.

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, plays a very simple melody using a piezo 
buzzer which is connected to Digital Pin 8. It uses the tone library which is installed
by default. 

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

// Additional imports
#include "pitches.h"

// Variables
int buzzer = 7;
int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

// The setup() function . It only runs once
void setup() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);

  }
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {

  // no need to repeat the melody.
}                                                                 
```

```
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
```

#### Piezo Buzzer Schematic

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Piezo.jpg?raw=true)



### Pin Change Interrupts

In this example, we attach an interrupt to Digital Pin 2 so that whenever the voltage of
the pin changes, which in this case is the press of a button, switches on an LED connected to 
Digital Pin 13

#### Pin Change Interrupt Code
```
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
```

#### Pin Change Interrupt Schematic

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/Pin_change_interrupt.jpg?raw=true)

### LCD 

In this example we use an LCD display to print characters which we input into the serial monitor.
The LCD display is connected with an I2C module which makes it easier to control the display. To
use the module, you have to install the ```LiquidCrystal_I2C``` library from the Arduino IDE 
Library Manager.

#### LCD Display Code

```
/*
LCD using I2C adapter

Prints an inputted character to the LCD connected to the Arduino with an I2C module

This code is a part of the Arduino For Beginners video tutorial series by Anant Narayan.
This code when uploaded to an Arduino and run, waits for an input from the serial monitor
and when a word or character is recieved, prints it to the LCD display.

Created 06/15/2022
by Anant Narayan

This code is licensed under the MIT license
 */

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
```

#### LCD Display Schematic

![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/LCD_I2C.jpg?raw=true)


### PIR Sensor

A PIR sensor or Passive Infra-red sensor uses a pyroelectric sensor module to detect when a human or animal comes into its field of view (FOV). It works by detecting
the infra-red radiation emitted by any living being in the form of heat.

#### PIR Sensor Code

```int ledPin = 13;                // choose the pin for the LED
int pirPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int beep = 0;
int buzzerPin = 12;
int val = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  detect();
  
}

void detect() {
  int val = digitalRead(pirPin);
  delay(500);
  Serial.println(val);
  beep = 0;

  if (val == 1) {
   while (beep < 5) {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 2000);
      delay(500);
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
      delay(500);
      beep++;
     }
  }
}
```

#### PIR Sensor Schematic
![ ](https://github.com/anantnrg/Arduino-Basics/blob/main/Diagrams/PIR_sensor.png?raw=true)
