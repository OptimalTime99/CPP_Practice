//#include <iostream>
//#include <memory>
//
//void useUniquePtr() {
//    // unique_ptr 생성
//    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
//
//    // unique_ptr이 관리하는 값 출력
//    std::cout << "unique_ptr 값: " << *ptr1 << "\n";
//
//    // unique_ptr은 복사가 불가능하고
//    // std::unique_ptr<int> ptr2 = ptr1; // 컴파일 에러 발생
//
//    // unique_ptr은 소유권 이전만 가능하다
//    std::unique_ptr<int> ptr2 = std::move(ptr1);
//
//    // std::cout << "ptr1 값: " << *ptr1 << "\n"; // 이제 비어 있으므로 예외 발생(프로그램 멈춤)
//    std::cout << "ptr2 값: " << *ptr2 << "\n";
//
//    // 범위를 벗어나면 메모리 자동 해제
//}
//
//void useSharedPtr() {
//    // shared_ptr 생성
//    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
//    std::shared_ptr<int> ptr2 = std::make_shared<int>(30);
//    std::shared_ptr<int> ptr3 = ptr2;
//
//    // ptr1의 참조 카운트 출력
//    std::cout << "ptr1의 참조 카운트: " << ptr1.use_count() << "\n"; // 1
//
//    // ptr2의 참조 카운트 출력
//    std::cout << "ptr2의 참조 카운트: " << ptr2.use_count() << "\n"; // 2
//
//    // ptr2가 ptr1과 리소스를 공유
//    ptr2 = ptr1;
//    std::cout << "ptr1의 참조 카운트: " << ptr1.use_count() << "\n"; // 2
//    std::cout << "ptr2의 참조 카운트: " << ptr2.use_count() << "\n"; // 2
//    std::cout << "ptr3의 참조 카운트: " << ptr3.use_count() << "\n"; // 1
//
//    // ptr2가 범위를 벗어나면 참조 카운트 감소
//    ptr2.reset();
//    std::cout << "ptr1의 참조 카운트: " << ptr1.use_count() << "\n"; // 1
//    std::cout << "ptr2의 참조 카운트: " << ptr2.use_count() << "\n"; // 0
//    std::cout << "ptr3의 참조 카운트: " << ptr3.use_count() << "\n"; // 1
//
//    // 범위를 벗어나면 ptr1도 자동 해제
//}
//
//
//int main() {
//    useUniquePtr();
//
//    std::cout << "\n=============\n\n";
//
//    useSharedPtr();
//
//    std::cout << "\n=============\n\n";
//
//
//}
//
///* 결과
//unique_ptr 값: 10
//ptr2 값: 10
//*/
//
///* 결과
//ptr1의 참조 카운트: 1
//ptr2의 참조 카운트: 2
//ptr1의 참조 카운트: 2
//ptr2의 참조 카운트: 2
//ptr3의 참조 카운트: 1
//ptr1의 참조 카운트: 1
//ptr2의 참조 카운트: 0
//ptr3의 참조 카운트: 1
//*/