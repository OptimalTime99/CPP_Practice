// Car.cpp
// copyright junhyeok
#include "Car.h"
#include <string>
#include <iostream>

Car::Car(std::string model, float speed) : model(model), speed(speed) {}

void Car::DisplayInfo(std::string model, float speed) {
    std::cout << "모델 명: " << model << " 현재 속도: " << speed << "\n";
}

void Car::Accelerate() {
    speed++;
    DisplayInfo(model, speed);
}

void Car::Break() {
    speed--;
    DisplayInfo(model, speed);
}
