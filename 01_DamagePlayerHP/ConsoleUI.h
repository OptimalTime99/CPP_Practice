// ConsoleUI.h
// copyright junhyeok

#pragma once
#include <string>

class ConsoleUI {
 public:
    void ShowPlayerHP(int HP);

    void ShowPreviewResult(int currentHP, int damage, int previewHP);

    void ShowTitle(std::string str);
};
