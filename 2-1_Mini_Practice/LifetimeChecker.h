// LifetimeChecker.h

#pragma once
#include <string>

class LifetimeChecker {
private:
    std::string name;

public:
    LifetimeChecker(std::string checkerName);
    ~LifetimeChecker();
};