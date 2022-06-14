// Variables
bool is_led_on = true;
int ledPin = 13;

// The setup() function . It only runs once
void setup() {
  pinMode(ledPin, OUTPUT);        //Set the ledPin to be OUTPUT
  cli();                      //Stop all interrupts until all the settings are made
  // Reset the control register to make sure that it starts with everything disabled
  TCCR1A = 0;                 // Reset entire TCCR1A to 0 
  TCCR1B = 0;                 // Reset entire TCCR1B to 0
 
  //Set the prescalar to the desired value by changing the CS10 CS12 and CS12 bits.  
  TCCR1B |= B00000100;        //Set CS12 to 1 so we get prescalar 256  
  
  //Enable compare match mode on register A
  TIMSK1 |= B00000010;        //Set OCIE1A to 1 so we enable compare match A 
  
  //Set the value of register A to 31250
  OCR1A = 31250;             //Set compare register A to this value  
  sei();                     //Enable back the interrupts
}

// The loop() function. It runs again and again until the board is reset or loses power.
void loop() {
  // nothin here
}

// This timer will get triggered every 500 ms or 0.5 seconds
ISR(TIMER1_COMPA_vect){
  //Set the timer back to 0 so it resets for next interrupt
  TCNT1  = 0;                  
  is_led_on = !is_led_on;      // Invert LED state
  digitalWrite(ledPin,is_led_on);  // Output the inverted state to the LED
}
