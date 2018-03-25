#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

extern "C" {
typedef void (*voidCallback)(void);
typedef void (*valueCallback)(uint16_t);
};

class Potentiometer {
public:
  Potentiometer(byte pin);

  Potentiometer(byte pin, uint16_t maxValue);

  uint16_t getOriginalValue();

  uint16_t getValue();

  void setMaxValue(uint16_t maxValue);

  void setOnChangeListener(valueCallback newFunction);

  void tick(void);

private:
  byte pin;
  uint16_t value;
  uint16_t originalValue;
  uint16_t maxValue;

  valueCallback onChange;
};

#endif