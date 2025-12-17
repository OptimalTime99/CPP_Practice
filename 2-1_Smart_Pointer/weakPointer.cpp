#include <iostream>
#include <memory>

//class a {
//public:
//    void say_hello() {
//        std::cout << "hello from a\n";
//    }
//};
//
//class b {
//public:
//    std::weak_ptr<a> a_ptr;
//
//    void usea() {
//        if (auto a_shared = a_ptr.lock()) {
//            a_shared->say_hello();
//        }
//        else {
//            std::cout << "a is no longer available.\n";
//        }
//    }
//};
//
//int main() {
//    std::shared_ptr<b> b = std::make_shared<b>();
//
//    {
//        std::shared_ptr<a> a = std::make_shared<a>();
//        b->a_ptr = a;
//        b->usea();
//    }
//
//    b->usea();
//
//
//    return 0;
//}


// 순환 참조 문제 해결
//class B;
//
//class A {
//public:
//    std::shared_ptr<B> b_ptr;
//    ~A() { std::cout << "A destroyed\n"; }
//};
//
//class B {
//public:
//    std::weak_ptr<A> a_ptr;
//    ~B() { std::cout << "B destroyed\n"; }
//};
//
//int main() {
//    auto a = std::make_shared<A>();
//    auto b = std::make_shared<B>();
//
//    a->b_ptr = b;
//    b->a_ptr = a;
//
//    return 0;
//}


 //Player는 자신의 HPBar를 소유한다
 //HPBar는 Player의 HP를 참조해서 화면에 표시한다
 //Player가 죽으면 Player + HPBar 모두 제거

//순환 참조 문제 있음
class HPBar;

class Player {
public:
    std::shared_ptr<HPBar> hpbar_ptr;
    ~Player() { std::cout << "Player 파괴\n"; }
};

class HPBar {
public:
    std::shared_ptr<Player> player_ptr;
    ~HPBar() { std::cout << "HPBar 파괴\n"; }
};

int main() {
    std::shared_ptr<Player> player = std::make_shared<Player>();
    std::shared_ptr<HPBar> hpbar = std::make_shared<HPBar>();

    player->hpbar_ptr = hpbar;
    hpbar->player_ptr = player;

    std::cout << "player의 참조 카운트: " << player.use_count() << "\n";
    std::cout << "hpbar의 참조 카운트: " << hpbar.use_count() << "\n";

    player.reset();

    std::cout << "player의 참조 카운트: " << player.use_count() << "\n";
    std::cout << "hpbar의 참조 카운트: " << hpbar.use_count() << "\n";

    // 순환참조 문제가 있기에 소멸자가 동작하지 않는다.
    return 0;
}
/* 결과
player의 참조 카운트: 2
hpbar의 참조 카운트: 2
player의 참조 카운트: 0
hpbar의 참조 카운트: 2
*/


// 순환 참조 문제 해결
class HPBar;

class Player {
public:
    std::shared_ptr<HPBar> hpbar_ptr;
    ~Player() { std::cout << "Player 파괴\n"; }
};

class HPBar {
public:
    std::weak_ptr<Player> player_ptr;
    ~HPBar() { std::cout << "HPBar 파괴\n"; }

    void Draw() {
        if (auto p = player_ptr.lock()) {
            std::cout << "Draw HP of Player\n";
        }
        else {
            std::cout << "Player already gone\n";
        }
    }
};

int main() {
    std::shared_ptr<Player> player = std::make_shared<Player>();
    std::shared_ptr<HPBar> hpbar = std::make_shared<HPBar>();

    player->hpbar_ptr = hpbar;  // player가 hpbar를 소유한다. => hpbar의 참조 카운트 + 1
    hpbar->player_ptr = player; // hpbar가 player를 관찰한다. => player의 참조 카운트 그대로 유지

    std::cout << "player의 참조 카운트: " << player.use_count() << "\n";
    std::cout << "hpbar의 참조 카운트: " << hpbar.use_count() << "\n";

    hpbar->Draw();
    player.reset(); // Player 소멸 → hpbar_ptr 멤버 소멸 → 참조한 HPBar 카운트 감소
    hpbar->Draw();

    std::cout << "player의 참조 카운트: " << player.use_count() << "\n";
    std::cout << "hpbar의 참조 카운트: " << hpbar.use_count() << "\n";

    return 0;
}

/* 결과
player의 참조 카운트: 1
hpbar의 참조 카운트: 2
Draw HP of Player
Player 파괴
Player already gone
player의 참조 카운트: 0
hpbar의 참조 카운트: 1
HPBar 파괴
*/