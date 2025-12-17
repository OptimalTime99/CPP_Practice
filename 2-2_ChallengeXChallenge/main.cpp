// 목적: 클래스 템플릿으로 배열을 일반화하여 원소 추가 및 삭제 기능 구현하기
#include <iostream>
using namespace std;

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

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }
};

int main() {
    Array<int> arr; // 정수형 배열 생성
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.print();

    for (int num : arr) {
        cout << "원소: " << num << "\n";
    }

    arr.remove();
    arr.print();
    return 0;
}

/* 결과
10 20 30
원소: 10
원소: 20
원소: 30
10 20

*/
