// ScopeTimer.cpp
#include "ScopeTimer.h"               // 클래스 선언 포함

ScopeTimer::ScopeTimer(std::string label, std::ostream& os)
    : label_(std::move(label))        // 문자열 복사 비용 방지 → 이동
    , os_(&os)                         // 출력 스트림 참조 저장
    , start_(Clock::now())            // 생성 시점 = 측정 시작 시점
    , stopped_(false)                 // 아직 종료되지 않음
{
    // 생성자는 "측정 시작"만 담당
}

ScopeTimer::~ScopeTimer()
{
    Stop();                           // 스코프 탈출 시 자동으로 종료 처리
}

ScopeTimer::ScopeTimer(ScopeTimer&& other) noexcept
    : label_(std::move(other.label_)) // 라벨 소유권 이전
    , os_(other.os_)                  // 스트림 참조 공유
    , start_(other.start_)            // 시작 시점 유지
    , stopped_(other.stopped_)        // 종료 상태 복사
{
    other.stopped_ = true;            // 원본 소멸 시 중복 출력 방지
}

ScopeTimer& ScopeTimer::operator=(ScopeTimer&& other) noexcept
{
    if (this != &other) {             // 자기 자신 대입 방지
        Stop();                       // 기존 타이머가 살아 있다면 먼저 종료

        label_ = std::move(other.label_);
        os_ = other.os_;
        start_ = other.start_;
        stopped_ = other.stopped_;

        other.stopped_ = true;        // 원본 무효화
    }
    return *this;
}

void ScopeTimer::Stop()
{
    if (stopped_) return;             // 이미 종료되었으면 아무 것도 하지 않음
    stopped_ = true;                  // 종료 상태로 전환

    const auto end = Clock::now();    // 종료 시점
    const auto us =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start_).count();
    // 시작~종료 구간을 마이크로초 단위 정수로 변환

    (*os_) << "[ScopeTimer] "
        << label_ << " : "
        << us << " us\n";             // 결과 출력
}

int64_t ScopeTimer::ElapsedMicroseconds() const
{
    const auto now = Clock::now();    // 현재 시점
    return std::chrono::duration_cast<std::chrono::microseconds>(
        now - start_).count();
    // 시작~현재까지 경과 시간 반환
}
