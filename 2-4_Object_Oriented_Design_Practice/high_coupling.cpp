#include <iostream>
#include <string>

using namespace std;

// 기존 Engine 클래스
class Engine {
public:
    string state;

    Engine() : state("off") {}

    void start() {
        state = "on";
        cout << "Engine started" << endl;
    }
};

// 새로운 ElectricEngine 클래스 (기존 Engine과는 별도)
class ElectricEngine {
public:
    string state;

    ElectricEngine() : state("off") {}

    void start() {
        state = "on";
        cout << "Electric Engine running silently" << endl;
    }
};

// 기존 Car 클래스 수정
class Car {
public:
    Engine engine; // Car 클래스는 여전히 Engine 클래스에 강하게 의존

    void startCar() {
        if (engine.state == "off") {
            engine.start();
            cout << "Car started" << endl;
        }
    }
};