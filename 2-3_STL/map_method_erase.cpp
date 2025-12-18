//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main() {
//    map<int, string> myMap = {
//        {1, "Apple"},
//        {2, "Banana"},
//        {3, "Cherry"}
//    };
//
//    cout << "Before erase, size: " << myMap.size() << endl;
//
//    // 특정 키 삭제
//    auto a = myMap.erase(2);
//
//    cout << "After erase(2), size: " << myMap.size() << endl;
//
//    // 남은 요소 출력
//    for (const auto& pair : myMap) {
//        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
//    }
//
//    return 0;
//}
//
///*
//출력 결과:
//Before erase, size: 3
//After erase(2), size: 2
//Key: 1, Value: Apple
//Key: 3, Value: Cherry
//*/
