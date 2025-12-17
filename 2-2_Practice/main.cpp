// 목적: 함수 템플릿을 이용해 두 값을 더하는 일반화된 함수 작성하기
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 5) << endl;        // 정수 더하기
    cout << add(2.5, 4.1) << endl;    // 실수 더하기
    return 0;
}

// 출력결과:
// 8
// 6.6
