// main.cpp
#include "LifetimeChecker.h"

int main() {
    LifetimeChecker localChecker("Local");
    LifetimeChecker* pChecker = new LifetimeChecker("Dynamic");

    for (int i = 0; i < 3; i++) {
        LifetimeChecker forChecker("For");
    }

    delete pChecker; // 실행 안하면 Dynamic Destructor가 출력되지 않음.

    return 0;
}