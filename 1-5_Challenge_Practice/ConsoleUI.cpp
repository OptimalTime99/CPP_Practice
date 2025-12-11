// ConsoleUI.cpp
// copyright junhyeok
#include <iostream>
#include "ConsoleUI.h"

void ConsoleUI::ShowTitle() {
    std::cout << "[--- 메시지 표시하는 라인 ---]\n";
    std::cout << "1) 온도 설정\n";
    std::cout << "2) 표시 모드 전환\n";
    std::cout << "3) 온도 표시\n";
    std::cout << "4) 종료\n";
}

void ConsoleUI::ShowDisplayMode(bool isCelsiusMode) {
    std::cout << "표시 모드를 " << (isCelsiusMode ? "'섭씨'" : "'화씨'")
              << "로 전환했습니다.\n";
}

void ConsoleUI::ShowTemperature(bool isCelsiusMode, double temperature) {
    std::cout << "현재 온도는 " << (isCelsiusMode ? "섭씨" : "화씨")
              << temperature << "도 입니다.\n";
}
