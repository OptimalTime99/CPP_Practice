// const_all_tests.cpp
#include <iostream>
#include <string>

// 4) 함수 매개변수 const
void PrintInt(const int& x) {
     //x++; // ❌ (읽기 전용)
    std::cout << "PrintInt: " << x << "\n";
}

// 7-1) 값 반환 const (의미 없음)
const int ReturnConstValue() {
    return 10;
}

// 7-2) 참조 반환 const (중요)
class RefReturn {
    int x = 10;
public:
    const int& Get() const { return x; }
};

// 5,6) 멤버 함수 const + const 오버로딩
class A {
    int x = 0;

public:
    void Set(int v) { x = v; }

    void Show() const {
        // x = 10; // ❌ (const 멤버 함수: 비-mutable 멤버 변경 불가)
        std::cout << "A::Show x=" << x << "\n";
    }

    void Foo() { std::cout << "Foo: non-const\n"; }
    void Foo() const { std::cout << "Foo: const\n"; }
};

// 8) mutable
class Counter {
    mutable int hits = 0;
public:
    void Touch() const { hits++; } // ⭕ const 함수에서도 mutable은 변경 가능
    int Hits() const { return hits; }
};

int main() {
    std::cout << "=== 1) const variable ===\n";
    {
        const int x = 10;
        // x = 20; // ❌
        std::cout << x << "\n";
    }

    std::cout << "\n=== 2) pointer const cases ===\n";
    {
        int a = 10, b = 20;

        // 2-1) 대상이 const
        const int* p1 = &a;
        // *p1 = 3; // ❌
        p1 = &b;     // ⭕
        std::cout << "*p1=" << *p1 << "\n";

        // 2-2) 포인터 자체가 const
        int* const p2 = &a;
        *p2 = 30;    // ⭕
        // p2 = &b;  // ❌
        std::cout << "*p2=" << *p2 << "\n";

        // 2-3) 둘 다 const
        const int* const p3 = &a;
        // *p3 = 40; // ❌
        // p3 = &b;  // ❌
        std::cout << "*p3=" << *p3 << "\n";
    }

    std::cout << "\n=== 3) const reference ===\n";
    {
        int a = 10;
        const int& r1 = a;
        // r1 = 20; // ❌
        std::cout << "r1=" << r1 << "\n";

        const int& r2 = 10; // 임시 바인딩 ⭕
        std::cout << "r2=" << r2 << "\n";
    }

    std::cout << "\n=== 4) const parameter ===\n";
    {
        int a = 42;
        PrintInt(a);
    }

    std::cout << "\n=== 5) member function const ===\n";
    {
        A a;
        a.Set(5);
        a.Show();
    }

    std::cout << "\n=== 6) const overload ===\n";
    {
        A a;
        const A ca;
        a.Foo();   // non-const
        ca.Foo();  // const
    }

    std::cout << "\n=== 7) return const cases ===\n";
    {
        int v = ReturnConstValue(); // const 붙어도 의미 없음
        std::cout << "ReturnConstValue=" << v << "\n";

        RefReturn rr;
        // rr.Get() = 20; // ❌ (const 참조 반환)
        std::cout << "RefReturn::Get=" << rr.Get() << "\n";
    }

    std::cout << "\n=== 8) mutable ===\n";
    {
        const Counter c;
        c.Touch();
        c.Touch();
        std::cout << "hits=" << c.Hits() << "\n";
    }

    std::cout << "\n=== 9) lambda const/mutable ===\n";
    {
        int x = 10;

        auto f1 = [x]() {
            // x++; // ❌ 기본은 캡처된 x가 const 취급
            std::cout << "f1 x=" << x << "\n";
            };

        auto f2 = [x]() mutable {
            x++; // ⭕ mutable로 캡처 값 변경 가능
            std::cout << "f2 x=" << x << "\n";
            };

        f1();
        f2();
        f2();
        std::cout << "outer x=" << x << " (원본은 안 바뀜)\n";
    }

    return 0;
}
