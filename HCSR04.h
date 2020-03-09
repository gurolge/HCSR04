#ifndef HCSR04_H_
#define HCSR04_H_

#include <Arduino.h>

const float v_s = 340; // speed of sound in [m/s]

class HCSR04 {
  private:
    byte trig; // trigger pin
    byte echo; // echo pin
    void sendTrigger();
  public:
    HCSR04(byte trig_in, byte echo_in);
    word readDistance();
};

#endif // HCSR04_H_
