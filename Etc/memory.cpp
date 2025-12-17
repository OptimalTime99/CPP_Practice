//#include <iostream>
//
//int main() {
//    int arr[] = { 10, 20, 30, 40, 50 };
//    int* ptr = arr; // &arr[0]
//
//    for (int i = 0; i < 5; i++) { // 10 20 30 40 50 모두 동일
//        std::cout << *(ptr + i) << " "; 
//        std::cout << ptr[i] << " ";
//        std::cout << arr[i] << " ";
//    }
//
//    ptr += 2;       // &arr[2]
//
//    // ptr[1] == *(ptr + 1) == *(&arr[2] + 1) == *(&arr[3]) == arr[3]
//    //   *ptr == *&arr[2]   == arr[2]         == 30
//    ptr[1] = *ptr + 10; // arr[3] = arr[2] + 10 = 40 
//
//    for (int a : arr) {
//        std::cout << a << " "; // 10 20 30 40 50
//    }
//
//    return 0;
//}




//void foo(int& x, int* y) {
//    // x → a (10), y → &b (20)
//
//    x = *y;
//    // *y == b == 20
//    // x → a = 20
//    // y는 여전히 &b
//
//    *y = 30;
//    // b = 30
//    // x = 20 (변화 없음)
//    // y는 여전히 &b
//
//    y = &x;
//    // y가 이제 a의 주소를 가리킴 (&a)
//    // b와의 연결이 끊김
//
//    *y = 40;
//    // a = 40
//    // b는 변하지 않고 여전히 30
//}
//
//int main() {
//    int a = 10;
//    int b = 20;
//    foo(a, &b);
//
//    std::cout << a << " " << b; // 40 30
//}
