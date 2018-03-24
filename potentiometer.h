#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {
public:
  explicit Potentiometer(byte pin);

  uint16_t getValue();

private:
  byte _pin;
};

#endif