//// 메모리 누수 발생 코드 분석하고 보완하기
//#include <iostream>
//using namespace std;
//
//class MyClass {
//private:
//    int* ptr;
//
//public:
//    // 생성자
//    MyClass() {
//        ptr = new int(10); // 동적 메모리 할당
//        cout << "메모리 할당 완료!" << endl;
//    }
//
//    // 소멸자
//    ~MyClass() {
//        delete ptr;
//    }
//
//    void print() const {
//        cout << "값: " << *ptr << endl;
//    }
//};
//
//int main() {
//    MyClass obj;
//    obj.print();
//
//    // main 함수 종료
//    return 0;
//}
