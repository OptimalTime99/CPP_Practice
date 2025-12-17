// main.cpp
// 생성한 코드의 속도 알아보기

#include "ScopeTimer.h"                  // 우리가 만든 ScopeTimer 사용
#include <thread>                        // std::this_thread::sleep_for
#include <vector>                        // std::vector (이동 테스트용)
#include <memory>                        // std::unique_ptr (이동 테스트용)
#include <iostream>                      // std::cout

// 시간이 좀 걸리는 작업을 흉내내는 함수
static void FakeWork(int loops)          // loops만큼 반복해서 CPU 시간을 소비
{
    volatile int sink = 0;               // 최적화로 루프가 날아가지 않게 방지(측정 안정)
    for (int i = 0; i < loops; ++i) {    // 단순 반복 작업
        sink += i;                       // 의미 없는 누적
    }
}

int main()
{
    std::cout << "==== Test 1) 기본 RAII 스코프 측정 ====\n";
    {
        ScopeTimer t("Test1: FakeWork"); // 여기서 시작(생성자에서 start_ 기록)
        FakeWork(20'000'000);            // 측정 대상 코드
    }                                    // 여기서 종료(소멸자에서 Stop() 호출 → 출력)

    std::cout << "\n==== Test 2) 수동 Stop()으로 조기 종료 ====\n";
    {
        ScopeTimer t("Test2: EarlyStop"); // 시작
        FakeWork(5'000'000);              // 일부 작업만 측정
        t.Stop();                         // 여기서 즉시 출력(이후 코드는 측정 제외)
        FakeWork(20'000'000);             // 측정에서 제외됨(Stop이 이미 됨)
    }                                     // 소멸자에서 Stop() 호출해도 stopped_라 중복 출력 없음

    std::cout << "\n==== Test 3) 이동 생성자/이동 대입 동작 확인 ====\n";
    {
        ScopeTimer a("Test3-A: moved-from will not print twice"); // a 시작

        // (1) 이동 생성자 테스트: a를 b로 이동
        ScopeTimer b(std::move(a));       // a의 타이머 상태를 b로 이전
        // a는 stopped_=true 처리되어 소멸 시 출력 안 함

        FakeWork(10'000'000);             // b가 측정 중인 구간

        // (2) 이동 대입 테스트
        ScopeTimer c("Test3-C: will be stopped when assigned"); // c 시작(짧게라도 측정 시작)
        FakeWork(2'000'000);              // c가 잠깐 측정

        c = std::move(b);                 // c 이동 대입:
        // - 기존 c는 Stop() 호출되어 먼저 출력됨
        // - b의 타이머가 c로 이전됨
        // - b는 stopped_=true 되어 소멸 시 출력 안 함

        FakeWork(8'000'000);              // 이제 c가 b의 측정을 이어받아 계속 측정
    }                                     // 스코프 끝: c만 최종 출력됨 (a,b는 중복 출력 방지)

    std::cout << "\n==== Test 4) ElapsedMicroseconds() 중간 조회 ====\n";
    {
        ScopeTimer t("Test4: elapsed polling");          // 시작
        std::this_thread::sleep_for(std::chrono::milliseconds(30)); // 일부 시간 경과
        std::cout << "elapsed(us): " << t.ElapsedMicroseconds()
            << "\n";                               // 중간 경과 출력(측정은 계속)
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // 추가 경과
    }                                                    // 소멸자에서 최종 출력

    std::cout << "\n==== Done ====\n";
    return 0;
}
