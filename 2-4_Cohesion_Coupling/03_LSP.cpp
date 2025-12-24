#include <iostream>
#include <string>


// --- SRP: 분리된 책임들 ---
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

// --- OCP: 공격 전략 (Strategy) ---
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

// --- LSP: 상속 구조 최적화 ---
// 모든 캐릭터의 공통 속성만 정의 (공격 능력은 없을 수도 있음)
class Character
{
 protected:
    std::string type;
    DataManager db; // 데이터 저장 책임

 public:
    Character(std::string InType) : type(InType) {}
    virtual ~Character()
    {
        db.saveToDatabase(type);
    }

    std::string getType() const
    {
        return type;
    }
};

// 공격 능력을 갖춘 플레이어 (Character를 상속받아 정당하게 대체 가능)
class Player : public Character
{
 private:
    IAttackBehavior* attackBehavior; // OCP: 전략 주입
    Logger logger;    // 내부 의존 (아직 DIP 위반 상태)

 public:
    Player(std::string InType, IAttackBehavior* InBehavior)
        : Character(InType), attackBehavior(InBehavior) {}


    // 부모의 기대에 부응하는 완벽한 기능 수행
    void attack()
    {
        // 1. 실제 공격 수행 (OCP에 의해 구체적 로직은 숨겨짐)
        attackBehavior->execute();

        // 2. 로그 기록 (SRP에 의해 분리된 Logger 사용)
        logger.logAction(type + " used " + attackBehavior->getAttackName());
    }
};

// LSP를 지키는 새로운 클래스 추가 예시: 공격 기능이 없는 상인
class Merchant : public Character
{
 public:
    Merchant() : Character("Merchant") {}

    void trade()
    {
        std::cout << "물건들 사고팝니다.\n";
    }

    // attack()을 억지로 상속받지 않으므로 LSP를 위반하지 않는다.
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

    // 3. LSP 덕분에 상인도 Character 타입으로 안전하게 관리 가능
    Merchant* npc = new Merchant();
    // npc->attack(); // 이 코드는 컴파일 단계에서 차단됨 (안전성 확보)
    npc->trade();

    std::cout << "-------------------\n";

    delete warrior;
    delete mage;
    delete npc;

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
데이터베이스에 Warrior 플레이어 저장...
데이터베이스에 Mage 플레이어 저장...
데이터베이스에 Merchant 플레이어 저장...

*/