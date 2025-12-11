// main.cpp
// copyright junhyeok
#include "ConsoleUI.h"
#include "Thermometer.h"
#include <iostream>
int main() {
    ConsoleUI consoleUI;
    Thermometer thermometer;
    int choice = 0;
    double temperature;

    consoleUI.ShowTitle();

    while (choice != 4) {
        std::cout << "번호를 입력해주세요: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "설정할 온도를 입력해주세요: ";
            std::cin >> temperature;
            thermometer.SetCelsiusTemperature(temperature);
            break;
        case 2:
            thermometer.SetIsCelsiusMode();
            consoleUI.ShowDisplayMode(thermometer.GetIsCelsiusMode());
            break;
        case 3:
            consoleUI.ShowTemperature(thermometer.GetIsCelsiusMode()
                                    , thermometer.GetCelsiusTemperature());
        case 4:
            break;
        }
    }

    return 0;
}
