class Shape {
public:
    virtual void draw() = 0; // 순수 가상 함수
};

class Circle : public Shape {
public:
    void draw() {
        // 원 그리기
    }
};

class Square : public Shape {
public:
    void draw() {
        // 사각형 그리기
    }
};

class ShapeManager {
public:
    void drawShape(Shape& shape) { // 인터페이스를 인자로 받는다.
        shape.draw(); // 다형성 활용
    }
};
