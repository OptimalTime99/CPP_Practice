// Thermometer.h
// copyright junhyeok
#pragma once

class Thermometer {
 private:
    double celsiusTemperature;
    bool isCelsiusMode;

 public:
     explicit Thermometer(bool isCelsiusMode = true
                       , double celsiusTemperature = 0.0f);

    double GetCelsiusTemperature() const;

    bool GetIsCelsiusMode() const;

    void SetCelsiusTemperature(double celsiusTemperature);

    void SetIsCelsiusMode();
};
