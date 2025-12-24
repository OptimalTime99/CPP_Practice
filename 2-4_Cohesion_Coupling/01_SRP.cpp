#include <iostream>
#include <string>


// 로깅 전담 클래스
class Logger
{
 public:
    void logAction(std::string action)
    {
        std::cout << "[Log]: " << action << std::endl;
    }
};

// 데이터 저장 전담 클래스
class DataManager
{
 public:
    void saveToDatabase(std::string type)
    {
        std::cout << "데이터베이스에 " << type << " 플레이어 저장...\n";
    }
};

// 플레이어 클래스
class Player
{
 public:
    std::string type;
    Logger logger;    // 내부 의존 (아직 DIP 위반 상태)
    DataManager db;   // 내부 의존

    Player(std::string InType) : type(InType) {}

    ~Player()
    {
        db.saveToDatabase(type);
    }

    void attack()
    {
        if (type == "Warrior") std::cout << "칼 휘두르기!\n";
        else if (type == "Mage") std::cout << "파이어볼!\n";
        logger.logAction(type + " attack");
    }
};

int main()
{
    Player* warrior = new Player("Warrior");
    Player* mage = new Player("Mage");

    warrior->attack();

    std::cout << "-------------------\n";

    mage->attack();

    std::cout << "-------------------\n";

    delete warrior;
    delete mage;

    return 0;
}

/* 결과
칼 휘두르기!
[Log]: Warrior attack
-------------------
파이어볼!
[Log]: Mage attack
-------------------
데이터베이스에 Warrior 플레이어 저장...
데이터베이스에 Mage 플레이어 저장...

*/