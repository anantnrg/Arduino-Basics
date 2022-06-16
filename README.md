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

<!-- /TOC -->
It contains 10 different examples using the Arduino Mega and various different components such as LEDs, pushbuttons, piezo buzzers, LCDs etc.. These example should work fine with and Arduino board with the only difference being the pins are to be used.

## Commonly used pins for each boards

| Boards | Arduino Mega 2560 | Arduino Uno | Arduino Nano | Arduino Leonardo |
| ------ | ----------------- | ----------- | ------------ | ----------- |
| Inbuilt LED Pin | 13 | 13 | 13 | 13
| Digital Pins | 1, 2, 3, 5, 6, 7, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 63, and 64 | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, and 13 | D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, and D13 | 4, 6, 8, 9, 10, and 12 |
| Analog Pins | A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14 and A15 | A0, A1, A2, A3, A4, and A5 | A0, A1, A2, A3, A4, A5, A6 and A7 | A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, and A11 |
| Pin Interrupts  | 2, 3, 18, 19, 20, 21 | 2, 3 | 2, 3 | 0, 1, 2, 3, 7|
| LCD SDA and SCL | 20, 21 | A4, A5 | A4, A5 | 3, 2 |

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
