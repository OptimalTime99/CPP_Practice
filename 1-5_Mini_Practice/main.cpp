// main.cpp
// copyright junhyeok
#include <iostream>
#include <string>
#include "Car.h"

int main() {
    Car car("차1");
    Car car2("차2", 3);
    int choice = 0;

    std::cout << "[--- 메시지 표시하는 라인 ---]\n";
    std::cout << "1) 가속\n";
    std::cout << "2) 브레이크\n";
    std::cout << "3) 종료\n";

    while (choice != 3) {
        std::cout << "번호를 입력해주세요: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            car.Accelerate();
            break;
        case 2:
            car.Break();
            break;
        case 3:
            break;
        default:
            std::cout << "잘못된 번호 입력입니다.\n";
        }
    }

    return 0;
}
