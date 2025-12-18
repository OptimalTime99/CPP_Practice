//#include <iostream>
//#include <string>
//#include <map>
//
//int main() {
//    std::string a;
//
//    // 기본적인 map 선언 및 사용 (키와 값이 다른 경우)
//    std::map<int, std::string>  studentMap;
//
//    // 기본적인 map 선언 및 사용 (키와 값이 같은 경우)
//    std::map<std::string, std::string> countryMap;
//
//    // 요소 추가
//    studentMap[101] = "Alice";
//    studentMap[102] = "Bob";
//    studentMap[103] = "Charlie";
//
//    countryMap["KR"] = "Korea";
//    countryMap["US"] = "United States";
//    countryMap["JP"] = "Japan";
//
//    // 요소 출력(실제로는 STL에서 이 형태를 더 많이 사용한다)
//    for (const auto& pair : studentMap) {
//        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
//    }
//
//    /* 결과
//    ID: 101, Name: Alice
//    ID: 102, Name: Bob
//    ID: 103, Name: Charlie
//
//    */
//
//
//    for (const std::pair<const int, std::string>& pair : studentMap) {
//        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
//    }
//
//    /* 결과
//    ID: 101, Name: Alice
//    ID: 102, Name: Bob
//    ID: 103, Name: Charlie
//
//    */
//
//    for (const auto& pair : countryMap) {
//        std::cout << "Country Code: " << pair.first << ", Country Name: " << pair.second << "\n";
//    }
//
//    /* 결과
//    Country Code: JP, Country Name: Japan
//    Country Code: KR, Country Name: Korea
//    Country Code: US, Country Name: United States
//
//    */
//
//    return 0;
//}
