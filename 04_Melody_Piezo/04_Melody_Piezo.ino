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
int buzzer = 8;
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
