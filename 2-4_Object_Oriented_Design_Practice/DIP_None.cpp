#include<string>

class Keyboard {
public:
    std::string getInput() {
        return "입력 데이터";
    }
};

class Monitor {
public:
    void display(const std::string& data) {
        // 출력
    }
};

class Computer {
    Keyboard keyboard;
    Monitor monitor;

public:
    void operate() {
        std::string input = keyboard.getInput();
        monitor.display(input);
    }
};
