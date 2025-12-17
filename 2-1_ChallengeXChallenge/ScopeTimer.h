#pragma once                          // 헤더 중복 포함 방지(컴파일 시간 및 ODR 문제 예방)

#include <chrono>                     // 시간 측정을 위한 std::chrono
#include <iostream>                   // std::ostream 선언
#include <string>                     // std::string

class ScopeTimer final                // 상속 목적이 없는 유틸 클래스 → final로 명시
{
public:
    using Clock = std::chrono::steady_clock;
    // 시스템 시간 변경의 영향을 받지 않는 단조 증가 시계 (프로파일링에 적합)

    using TimePoint = Clock::time_point;
    // 특정 시점을 나타내는 타입 별칭 (가독성 향상)

    explicit ScopeTimer(std::string label,
        std::ostream& os = std::cout);
    // 생성자: 스코프 진입 시 호출됨
    // label : 어떤 코드 구간을 측정하는지 식별
    // os    : 출력 대상(기본값은 콘솔)

    ~ScopeTimer();
    // 소멸자: 스코프 탈출 시 자동 호출 (RAII 핵심)

    ScopeTimer(const ScopeTimer&) = delete;
    // 복사 금지: 타이머가 복사되면 중복 종료/출력 위험

    ScopeTimer& operator=(const ScopeTimer&) = delete;
    // 복사 대입도 동일한 이유로 금지

    ScopeTimer(ScopeTimer&& other) noexcept;
    // 이동 생성자: 조건 분기/컨테이너에서 안전하게 사용 가능

    ScopeTimer& operator=(ScopeTimer&& other) noexcept;
    // 이동 대입 연산자

    void Stop();
    // 수동 종료 함수: 원하는 시점에 측정 종료 가능

    int64_t ElapsedMicroseconds() const;
    // 현재까지 경과 시간 조회 (측정은 계속 유지)

private:
    std::string label_;
    // 측정 구간 이름 (출력용)

    std::ostream* os_;
    // 출력 스트림 참조 (소유하지 않음)

    TimePoint start_;
    // 측정 시작 시각 (생성자에서 기록)

    bool stopped_;
    // 종료 여부 플래그 (중복 출력 방지)
};
