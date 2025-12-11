// Thermometer.cpp
// copyright junhyeok
#include "Thermometer.h"

Thermometer::Thermometer(bool isCelsiusMode, double celsiusTemperature) :
    isCelsiusMode(isCelsiusMode), celsiusTemperature(celsiusTemperature) {}

double Thermometer::GetCelsiusTemperature() const {
    if (!isCelsiusMode) return celsiusTemperature * 1.8 + 32;
    return celsiusTemperature;
}

bool Thermometer::GetIsCelsiusMode() const {
    return isCelsiusMode;
}

void Thermometer::SetCelsiusTemperature(double celsiusTemperature) {
    if (celsiusTemperature > 100) celsiusTemperature = 100;
    if (celsiusTemperature < -100) celsiusTemperature = -100;
    this->celsiusTemperature = celsiusTemperature;
}

void Thermometer::SetIsCelsiusMode() {
    this->isCelsiusMode = !isCelsiusMode;
}
