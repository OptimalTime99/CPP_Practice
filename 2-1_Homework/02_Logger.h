// 02_Logger.h

#pragma once
#include <string>

class Logger {
 private:
    int logCount;
 public:
    Logger();
    ~Logger();

    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    void showTotalLogs() const;
};

/*
[std::string message가 아니라 const std::string& message 여야 하는 이유]

매개변수를 값으로 받으면 호출할 때마다 새 std::string 객체를 하나 더 만들게 된다.
→ 값으로 받는 경우 message 파라미터를 만들기 위해 값의 복사가 발생한다.

매개변수를 참조로 받으면 복사 없이 기존 문자열을 그대로 참조한다.
→ 불필요한 복사 비용을 없앨 수 있는 방법

함수의 성격에 읽기만 할 때, const를 붙여 의도를 명확히 드러낼 수 있다.


이를 통해 "읽기 전용, 복사 없음" 이라는 의도를 드러내는 것이다.
*/

/*
[std::make_unique<Logger>("")가 아니라 std::make_unique<Logger>()여야 하는 이유]

Logger(const char*) 또는 Logger(std::string) 같은 생성자가 없으므로
(" ")를 넘기면 오버로드 매칭 실패로 컴파일 에러가 난다.
*/

/*
[함수 뒤의 const (=멤버 함수 const)]

이 함수 안에서 this가 const A*로 취급되어 객체의 논리적 상태를 변경할 수 없다.

금지되는 것
- 모든 비-mutable 멤버 변수 수정
- 비-const 멤버 함수 호출

허용되는 것
- 함수 내 지역 변수 수정
- mutable 멤버 수정
- const 멤버 함수 호출
*/