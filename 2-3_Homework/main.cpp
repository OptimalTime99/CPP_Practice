#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    // 벡터와 맵 데이터 정의
    std::vector<int> vec = { 10, 20, 30, 40, 50 };
    std::map<std::string, int> mp = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    // 문제: 아래 부분을 완성하세요
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    /* 결과
    10 20 30 40 50
    */

    std::cout << "\n";

    for (std::vector<int>::const_reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    /* 결과
    50 40 30 20 10
    */

    std::cout << "\n";

    for (std::map<std::string, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }

    /* 결과
    Alice 90
    Bob 85
    Charlie 95
    */

    std::cout << "\n";

    for (std::map<std::string, int>::const_reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit) {
        std::cout << rit->first << " " << rit->second << "\n";
    }

    /* 결과
    Charlie 95
    Bob 85
    Alice 90
    */


    return 0;
}
