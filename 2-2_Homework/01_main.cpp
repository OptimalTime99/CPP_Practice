#include <iostream>

using namespace std;

//아래 3개의 함수를 하나의 템플릿 함수로 통합하세요
//int add(int a, int b) {
//    return a + b;
//}
//
//double add(double a, double b) {
//    return a + b;
//}
//
//std::string add(const std::string& a, const std::string& b) {
//    return a + b;
//}

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // 정수 더하기
    cout << "3 + 5 = " << add(3, 5) << endl;

    // 실수 더하기
    cout << "2.5 + 4.3 = " << add(2.5, 4.3) << endl;

    // 문자열 합치기
    cout << "\"Hello, \" + \"World!\" = " << add(string("Hello, "), string("World!")) << endl;

    cout << add(true, false) << endl; // 오버로딩 방식으로 구현 시 int add(int a, int b) 함수로 실행됨.

    return 0;
}

/* 결과 동일
3 + 5 = 8
2.5 + 4.3 = 6.8
"Hello, " + "World!" = Hello, World!
1
*/


/* 결과
3 + 5 = 8
2.5 + 4.3 = 6.8
"Hello, " + "World!" = Hello, World!
1
*/
