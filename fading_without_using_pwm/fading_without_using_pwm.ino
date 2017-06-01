/* fade w/o pwm
 
Fades an LED that is not connected to a PWM pin
This was modified from the Blink without Delay code
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 */

// constants won't change. Used here to  set pin numbers:
const int ledPin =  A0;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMicros = 0;        // will store the last time the blink cycle occured

// the follow variables is a long because the time, measured in microseconds,
// will quickly become a bigger number than can be stored in an int.
long intervalLength = 500;     // interval at which to blink (microseconds)
long onInterval = 20;          // on or HIGH interval length
long currentInterval;          // length of the current interval
int  fadeLength = 200;
int  fadeCount = 0;
int  intervalDirection = 1;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);      
}

void loop()
{

  unsigned long currentMicros = micros();

  currentInterval = currentMicros - previousMicros;

  if (currentInterval <= onInterval) {
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }

  if(currentInterval > intervalLength) {
    // save the last time you blinked the LED 
    previousMicros = currentMicros;
    fadeCount++;
    if (fadeCount > fadeLength) {
      fadeCount = 0;
      onInterval += (intervalDirection * 20);
      if (onInterval <= 20 || onInterval >= intervalLength) {
        intervalDirection *= -1;  // change the direction of the fade ( positive - brighter / negative - dimmer)
      }
    }
  }

  // set the LED with the ledState of the variable:
  digitalWrite(ledPin, ledState);
}
