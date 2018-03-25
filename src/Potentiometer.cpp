#include "potentiometer.h"

Potentiometer::Potentiometer(byte pin) {
  this->pin = pin;
  this->maxValue = 1023;
  this->originalValue = analogRead(pin);
}

Potentiometer::Potentiometer(byte pin, uint16_t maxValue) {
  this->pin = pin;
  this->maxValue = maxValue;
  this->originalValue = analogRead(pin);
}

uint16_t Potentiometer::getValue() {
  return this->value;
}

uint16_t Potentiometer::getOriginalValue() {
  return this->originalValue;
}

void Potentiometer::setMaxValue(uint16_t maxValue) {
  this->maxValue = maxValue;
}

void Potentiometer::setOnChangeListener(valueCallback callback) {
  this->onChange = callback;
}

void Potentiometer::tick(void) {
  uint16_t val = analogRead(pin);
  if (originalValue != val) {
    uint16_t oldValue = value;
    originalValue = val;
    if (maxValue != 1023) {
      value = map(val, 0, 1023, 0, maxValue);
    } else {
      value = val;
    }
    if (oldValue != value && onChange) {
      onChange(value);
    }
  }
}
