// LifetimeChecker.cpp

#include <string>
#include <iostream>
#include "LifetimeChecker.h"

LifetimeChecker::LifetimeChecker(std::string checkerName) : name(checkerName) {
    std::cout << name << " Constructor" << std::endl;
}

LifetimeChecker::~LifetimeChecker() {
    std::cout << name << " Destructor" << std::endl;
}