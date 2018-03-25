#include "Potentiometer.h"

#define potPit 5

uint16_t value;

Potentiometer potentiometer(potPit, 10);

void setup() {
  Serial.begin(9600);
  potentiometer.setOnChangeListener(onChange);
}

void loop() {
  potentiometer.tick();
}

void onChange(uint16_t val) {
  Serial.println(val);
}