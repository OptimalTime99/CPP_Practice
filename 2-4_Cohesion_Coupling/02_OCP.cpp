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

// 공격을 추상화 (Strategy Pattern)
class IAttackBehavior
{
 public:
    virtual ~IAttackBehavior() {}
    virtual void execute() = 0;
    virtual std::string getAttackName() = 0; // 로그 출력을 위해 이름 반환 추가
};

class SwordAttack : public IAttackBehavior
{
 public:
    void execute() override
    {
        std::cout << "칼 휘두르기!\n";
    }

    std::string getAttackName() override
    {
        return "Sword Attack";
    }
};

class MagicAttack : public IAttackBehavior
{
 public:
    void execute() override
    {
        std::cout << "파이어볼!\n";
    }

    std::string getAttackName() override
    {
        return "Mage Attack";
    }
};

// 플레이어 클래스
class Player
{
 private:
    std::string type;
    IAttackBehavior* attackBehavior; // OCP: 전략 주입
    Logger logger;    // 내부 의존 (아직 DIP 위반 상태)
    DataManager db;   // 내부 의존

 public:
    Player(std::string InType, IAttackBehavior* InBehavior)
        : type(InType), attackBehavior(InBehavior) {}

    ~Player()
    {
        db.saveToDatabase(type);
    }

    void attack()
    {
        // 1. 실제 공격 수행 (OCP에 의해 구체적 로직은 숨겨짐)
        attackBehavior->execute();

        // 2. 로그 기록 (SRP에 의해 분리된 Logger 사용)
        logger.logAction(type + " used " + attackBehavior->getAttackName()) ;
    }
};

int main()
{
    // 전사 생성 (검 공격 전략 주입)
    SwordAttack sword;
    Player* warrior = new Player("Warrior", &sword);
    warrior->attack();

    std::cout << "-------------------\n";

    // 마법사 생성 (마법 공격 전략 주입)
    MagicAttack magic;
    Player* mage = new Player("Mage", &magic);
    mage->attack();

    std::cout << "-------------------\n";

    delete warrior;
    delete mage;

    return 0;
}

/* 결과
칼 휘두르기!
[Log]: Warrior used Sword Attack
-------------------
파이어볼!
[Log]: Mage used Mage Attack
-------------------
데이터베이스에 Warrior 플레이어 저장...
데이터베이스에 Mage 플레이어 저장...

*/