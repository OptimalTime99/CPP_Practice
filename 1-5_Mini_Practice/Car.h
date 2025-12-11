// Car.h
// copyright junhyeok
#pragma once
#include <string>

class Car {
 private:
    std::string model;
    float speed;
    void DisplayInfo(std::string model, float speed);

 public:
    explicit Car(std::string model, float speed = 0.0f);
    void Accelerate();
    void Break();
};
