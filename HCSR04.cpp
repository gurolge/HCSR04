#include "HCSR04.h"

/* Class instance declaration for a HCSR04 sensor
  f.e. HCSR04 mySensor = HCSR04(0,4); represents a sensor mySensor which is triggered using pin 0
  and whose echo is read at pin 4. */
HCSR04::HCSR04(byte trig_in, byte echo_in) {
  trig = trig_in;
  echo = echo_in;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

/* Sends a 10 microseconds trigger using the defined trigger pin */
void HCSR04::sendTrigger() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2); // clears the trigger pin for 2 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}

/* Returns the distance to a detected object in [cm]. Returns 0 if an object is not detected. */
word HCSR04::readDistance() {
  sendTrigger();
  return v_s / 20000 * pulseIn(echo, HIGH, 36000); // ignore echo signals arriving after 36 ms
}
