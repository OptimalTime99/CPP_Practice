// ConsoleUI.h
// copyright junhyeok
#pragma once

class ConsoleUI {
 public:
    void ShowTitle();

    void ShowDisplayMode(bool isCelsiusMode);

    void ShowTemperature(bool isCelsiusMode, double temperature);
};
