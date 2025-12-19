#include <iostream>
#include <memory>

using namespace std;

// 공통 인터페이스 정의
class Engine {
public:
    virtual void start() = 0;
    virtual ~Engine() = default;
};

// DieselEngine 구현
class DieselEngine : public Engine {
public:
    void start() {
        cout << "Diesel Engine started" << endl;
    }
};

// 새로운 ElectricEngine 구현
class ElectricEngine : public Engine {
public:
    void start() {
        cout << "Electric Engine started silently" << endl;
    }
};

// Car 클래스는 Engine 인터페이스에만 의존
class Car {
private:
    unique_ptr<Engine> engine;

public:
    Car(unique_ptr<Engine> eng) : engine(move(eng)) {}

    void startCar() {
        engine->start();
        cout << "Car started" << endl;
    }
};

int main() {
    // DieselEngine을 사용하는 경우
    auto dieselEngine = make_unique<DieselEngine>();
    Car dieselCar(move(dieselEngine));
    dieselCar.startCar();

    // ElectricEngine을 사용하는 경우
    auto electricEngine = make_unique<ElectricEngine>();
    Car electricCar(move(electricEngine));
    electricCar.startCar();

    return 0;
}
