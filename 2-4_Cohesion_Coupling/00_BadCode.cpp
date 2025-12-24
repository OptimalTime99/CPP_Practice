#include <iostream>
#include <string>


class Player
{
 public:
    std::string type; // "Warrior", "Mage"

    Player(std::string InType) : type(InType) {}

    ~Player()
    {
        saveToDatabase();
    }

    void attack()
    {
        // OCP 위반: 직업 추가 시 여기를 수정해야 함
        if (type == "Warrior") std::cout << "칼 휘두르기!\n";
        else if (type == "Mage") std::cout << "파이어볼!\n";
        logAction(type + " attack");
    }

    void saveToDatabase()
    {
        // SRP 위반: 플레이어가 DB 로직까지 가짐
        std::cout << "데이터베이스에 " << type << " 플레이어 저장...\n";
    }

    void logAction(std::string action)
    {
        // SRP 위반: 플레이어가 로그 출력 책임까지 가짐
        std::cout << "[Log]: " << action << std::endl;
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