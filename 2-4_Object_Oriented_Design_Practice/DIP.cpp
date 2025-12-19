#include<string>
class InputDevice {
public:
    virtual std::string getInput() = 0;
};

class OutputDevice {
public:
    virtual void display(const std::string& data) = 0;
};

class Keyboard : public InputDevice {
public:
    std::string getInput() override {
        return "키보드 입력 데이터";
    }
};

class Monitor : public OutputDevice {
public:
    void display(const std::string& data) override {
        // 화면에 출력
    }
};

class Computer {
private:
    InputDevice* inputDevice;
    OutputDevice* outputDevice;

public:
    Computer(InputDevice* input, OutputDevice* output)
        : inputDevice(input), outputDevice(output) {
    }

    void operate() {
        std::string data = inputDevice->getInput();
        outputDevice->display(data);
    }
};
