// ConsoleUI.cpp
// copyright junhyeok

#include <iostream>
#include <string>
#include "ConsoleUI.h"

void ConsoleUI::ShowPlayerHP(int HP) {
    std::cout << "현재 플레이어 HP: " << HP << "\n";
}

void ConsoleUI::ShowPreviewResult(int currentHP, int damage, int previewHP) {
    std::cout << "데미지 " << damage << "를 맞으면 HP가 "
              << currentHP << " → " << previewHP << "로 줄어듭니다\n";
}

void ConsoleUI::ShowTitle(std::string str) {
    std::cout << "\n" << str << "\n";
}
