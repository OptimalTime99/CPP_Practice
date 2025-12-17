#include <iostream>
#include <memory>

using namespace std;

class Data
{
public:
    int value;

    Data(int v) : value(v)
    {
        cout << "[INFO] Data(" << value << ") 객체 생성됨.\n";
    }

    ~Data()
    {
        cout << "[INFO] Data(" << value << ") 객체 소멸됨.\n";
    }
};


void RepresentDanglingPointer()
{
    std::cout << "\n === 메모리 테스트 ===\n";

    // 1. 힙에 Data 객체를 할당하고, 두 개의 Raw Pointer에 주소를 저장하세요.
    Data* raw_ptr1 = new Data(2);
        Data * raw_ptr2 = raw_ptr1;

    cout << "Raw Ptrs 값: " << raw_ptr1->value << "\n";
    // 2. raw_ptr1을 사용하여 메모리를 해제합니다.
    delete raw_ptr1;
    cout << "raw_ptr1로 메모리 해제 완료.\n";

    // 3. raw_ptr2를 이용하여 메모리를 해제합니다.
    // 런타임 에러(Crash)를 유발할 수 있습니다.
    cout << "raw_ptr2로 해제 시도...\n";
    delete raw_ptr2;
}

int main() {
    RepresentDanglingPointer();

    return 0;
}