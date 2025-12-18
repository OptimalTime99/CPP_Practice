//#include <iostream>
//#include <string>
//#include <map>
//
//int main() {
//    std::map<int, std::string> fruitsMap;
//
//    // 1. make_pair()를 사용하여 insert()
//    fruitsMap.insert(std::make_pair(1, "Apple"));
//    fruitsMap.insert(std::make_pair(2, "Banana"));
//    fruitsMap.insert(std::make_pair(3, "Cherry"));
//
//    // 출력
//    for (const auto& pair : fruitsMap) {
//        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//    }
//
//    /* 결과
//    Key: 1, Value: Apple
//    Key: 2, Value: Banana
//    Key: 3, Value: Cherry
//    
//    */
//
//    // 2. {}를 사용하여 insert()
//    std::map<std::string, std::string> animalMap;
//
//    animalMap.insert({ "Dog", "bark bark!" });
//    animalMap.insert({ "Cat", "Meow..." });
//    animalMap.insert({ "Elephant", "Booooo!!" });
//
//    // 출력
//    for (const auto& pair : animalMap) {
//        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//    }
//
//    /* 결과
//    Key: Cat, Value: Meow...
//    Key: Dog, Value: bark bark!
//    Key: Elephant, Value: Booooo!!
//    
//    */
//
//    // 3. [] 연산자로 값 추가
//    std::map<const int, std::string> STLMap;
//
//    STLMap[0] = "Vector";
//    STLMap[1] = "Map";
//    STLMap[2] = "Unordered_Map";
//
//    // 출력
//    for (const auto& pair : STLMap) {
//        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
//    }
//
//    /* 결과
//    Key: 0, Value: Vector
//    Key: 1, Value: Map
//    Key: 2, Value: Unordered_Map
//    
//    */
//
//    return 0;
//}