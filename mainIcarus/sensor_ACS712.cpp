#include "sensor_ACS712.h"

const float ACS712::_ADC_RES = 1023;



ACS712::ACS712(uint8_t pin, float sensitivity, float vref) : _PIN(pin), _SENSITIVITY(sensitivity / 1000.0), _VREF(vref), _FACTOR(_VREF / _ADC_RES), _VMID(_VREF / 2), current(0.0) {}


void ACS712::init() {
  pinMode(_PIN, INPUT);

  Serial.println(F("ACS712 correct initialization"));
  delay(20);
}


// Processes raw analog readings into current values [A]
void ACS712::processData() {
  int rawValue = analogRead(_PIN);
  float voltage = rawValue * _FACTOR;
  current = (voltage - _VMID) / _SENSITIVITY;
}


String ACS712::readData() {
  String data = String(current) + ",";

  return data;
}