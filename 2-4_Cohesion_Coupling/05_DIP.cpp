#include <iostream>
#include <string>


// --- 1. DIP를 위한 인터페이스 추상화 (추상화에 의존하라) ---
class ILogger
{
 public:
    virtual ~ILogger() {}
    virtual void logAction(std::string action) = 0;
};

class IDataManager
{
 public:
    virtual ~IDataManager() {}
    virtual void saveToDatabase(std::string type) = 0;
};

// --- 2. 구체적인 도구 구현 (저수준 모듈) ---
// 로깅 전담 클래스
class Logger : public ILogger
{
 public:
    void logAction(std::string action) override
    {
        std::cout << "[Log]: " << action << std::endl;
    }
};

// 데이터 저장 전담 클래스
class DataManager : public IDataManager 
{
 public:
    void saveToDatabase(std::string type) override
    {
        std::cout << "데이터베이스에 " << type << " 플레이어 저장...\n";
    }
};

// --- 3. OCP: 공격 전략 (Strategy) ---
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

// --- 4. ISP: 기능별 인터페이스 분리 ---
class IAttackable
{
 public:
    virtual ~IAttackable() {}
    virtual void attack() = 0;
};

class IRepairer
{
 public:
    virtual ~IRepairer() {}
    virtual void repair() = 0;
};

class ITrade
{
 public:
    virtual ~ITrade() {}
    virtual void trade() = 0;
};

// --- 5. LSP & DIP를 준수하는 기본 계층 ---
// 모든 캐릭터의 공통 속성만 정의 (공격 능력은 없을 수도 있음)
class Character
{
 protected:
    std::string type;
    IDataManager* db; // DIP: 구체 클래스가 아닌 인터페이스에 의존

 public:
    Character(std::string InType, IDataManager* InDb) : type(InType), db(InDb) {}
    virtual ~Character()
    {
        db->saveToDatabase(type);
    }

    std::string getType() const
    {
        return type;
    }
};

// --- 6. 인터페이스 조합을 통한 클래스 구현 ---
// 공격 능력을 갖춘 플레이어 (Character를 상속받아 정당하게 대체 가능)
class Player : public Character, public IAttackable
{
 private:
    IAttackBehavior* attackBehavior; // OCP: 전략 주입
    ILogger* logger;    // DIP: 인터페이스에 의존

 public:
    Player(std::string InType, IAttackBehavior* InBehavior
        , ILogger* InLogger, IDataManager* InDb)
        : Character(InType, InDb), attackBehavior(InBehavior), logger(InLogger) {}

    // 부모의 기대에 부응하는 완벽한 기능 수행
    void attack() override
    {
        // 1. 실제 공격 수행 (OCP에 의해 구체적 로직은 숨겨짐)
        attackBehavior->execute();

        // 2. 로그 기록 (SRP에 의해 분리된 Logger 사용)
        logger->logAction(type + " used " + attackBehavior->getAttackName());
    }
};

// LSP를 지키는 새로운 클래스 추가 예시: 공격 기능이 없는 상인
class Merchant : public Character, public ITrade
{
 public:
    Merchant(IDataManager* InDb) : Character("Merchant", InDb) {}

    void trade() override
    {
        std::cout << "물건들 사고팝니다.\n";
    }

    // attack()을 억지로 상속받지 않으므로 LSP를 위반하지 않는다.
};

// Blacksmith는 수리만 가능한 NPC (공격 인터페이스 의존 없음)
class Blacksmith : public Character, public IRepairer
{
 public:
    Blacksmith(IDataManager* InDb) : Character("Blacksmith", InDb) {}
    void repair() override
    {
        std::cout << "대장장이가 장비를 수리합니다.\n";
    }
};

// Paladin은 공격과 수리가 모두 가능한 클래스 (다중 상속 활용)
class Paladin : public Character, public IAttackable, public IRepairer
{
 public:
    Paladin(IAttackBehavior* InBehavior, ILogger* InLogger, IDataManager* InDb)
        : Character("Paladin", InDb), attackBehavior(InBehavior), logger(InLogger) {}

    void attack() override
    {
        attackBehavior->execute();
        logger->logAction(type + " used " + attackBehavior->getAttackName());
    }

    void repair() override
    {
        std::cout << "성기사가 축복으로 장비를 수리합니다.\n";
    }

 private:
    IAttackBehavior* attackBehavior;
    ILogger* logger;
};

int main()
{
    // 인프라스트럭처 준비 (필요한 부품들 생성)
    Logger logger;
    DataManager dbManager;
    SwordAttack sword;
    MagicAttack magic;

    // 객체 생성 시 부품들을 주입 (DIP의 핵심)
    Player* warrior = new Player("Warrior", &sword, &logger, &dbManager);
    Player* mage = new Player("Mage", &magic, &logger, &dbManager);
    IAttackable* paladin = new Paladin(&sword, &logger, &dbManager);
    Merchant* npc = new Merchant(&dbManager);
    IRepairer* smith = new Blacksmith(&dbManager);
    

    warrior->attack();
    std::cout << "-------------------\n";

    mage->attack();
    std::cout << "-------------------\n";

    npc->trade();
    std::cout << "-------------------\n";
 
    smith->repair();

    IRepairer* smithPaladin = dynamic_cast<IRepairer*>(paladin);
    if (smithPaladin) smithPaladin->repair();
    std::cout << "-------------------\n";

    // 자원 해제
    delete warrior;
    delete mage;
    delete npc;
    delete smith;
    delete paladin;

    return 0;
}

/* 결과
칼 휘두르기!
[Log]: Warrior used Sword Attack
-------------------
파이어볼!
[Log]: Mage used Mage Attack
-------------------
물건들 사고팝니다.
-------------------
대장장이가 장비를 수리합니다.
성기사가 축복으로 장비를 수리합니다.
-------------------
데이터베이스에 Warrior 플레이어 저장...
데이터베이스에 Mage 플레이어 저장...
데이터베이스에 Merchant 플레이어 저장...
데이터베이스에 Blacksmith 플레이어 저장...
데이터베이스에 Paladin 플레이어 저장...

*/