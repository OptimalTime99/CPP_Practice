// 목적: 클래스 템플릿으로 배열을 일반화하여 원소 추가 및 삭제 기능 구현하기
#include <iostream>

template <typename T>
class Array {
    T data[100];
    int size;
public:
    Array() : size(0) {}

    void add(const T& element) {
        if (size < 100)
            data[size++] = element;
    }

    void remove() {
        if (size > 0)
            size--;
    }


    // [] 연산자 읽기/쓰기 구현
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // [] 연산자 읽기 구현
    const T& operator[](int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    void print() {
        for (int i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    Array<int> arr; // 정수형 배열 생성

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.print();

    arr[1] = 200;
    std::cout << arr[1] << std::endl;

    try {
        std::cout << arr[10];
    }
    catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    arr.remove();
    arr.print();
    return 0;
}

/* 결과
10 20 30
200
Index out of range
10 200

*/
