//#include <iostream>
//#include <vector>
//
//int main() {
//    // 1. 타입만 명시해서 선언하는 방법: 기본 생성 및 초기화 없이 선언
//    std::vector<int> vec1;
//    
//    for (int num : vec1) {
//        std::cout << "vec1: " << num << "\n";
//    }
//
//    /* 결과
//    */
//
//
//    // 2. 선언과 동시에 초기화하는 방법: 특정 크기와 초기값으로 벡터 선언
//    std::vector<int> vec2(5, 10); // 크기 5, 모든 원소가 10으로 초기화
//
//    for (int num : vec2) {
//        std::cout << "vec2: " << num << "\n";
//    }
//
//    /* 결과
//    vec2: 10
//    vec2: 10
//    vec2: 10
//    vec2: 10
//    vec2: 10
//
//    */
//    
//    // 3. 초기화 리스트를 사용하여 선언과 동시에 초기화하는 방법: 특정 값으로 초기화.
//    // 초기화하는 원소의 개수가 적을 때 주로 활용
//    std::vector<int> vec3 = { 1, 2, 3, 4, 5 };
//
//    for (int num : vec3) {
//        std::cout << "vec3: " << num << "\n";
//    }
//
//    /* 결과
//    vec3: 1
//    vec3: 2
//    vec3: 3
//    vec3: 4
//    vec3: 5
//
//    */
//
//
//    // 4. 다른 벡터 복사/대입하는 방법
//    // 기존에 생성된 벡터의 복사본을 만들 때 많이 사용한다.
//    // 원본을 훼손하지 않기 위해서 사용하는건가?
//    std::vector<int> vec4(vec3);
//
//    for (int num : vec4) {
//        std::cout << "vec4: " << num << "\n";
//    }
//
//    /* 결과
//    vec4: 1
//    vec4: 2
//    vec4: 3
//    vec4: 4
//    vec4: 5
//
//    */
//
//    // 5. 2차원 배열처럼 벡터 사용하는 방법
//    // 3x4 행렬, 모든 원소가 7로 초기화
//    const int ROW = 3;
//    const std::vector<int> COLUMN = std::vector<int>(4, 7);
//    std::vector<std::vector<int>> vec2D_1(ROW, COLUMN); 
//    
//    int count = 0;
//    for (std::vector<int> ROW : vec2D_1) {
//        std::cout << "[" << count << "번째 행]\n";
//        for (int value : ROW) {
//            std::cout << "vec2D_1: " << value << "\n";
//        }
//
//        ++count;
//    }
//
//    /* 결과
//    [0번째 행]
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    [1번째 행]
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    [2번째 행]
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    vec2D_1: 7
//    
//    */
//
//    return 0;
//}