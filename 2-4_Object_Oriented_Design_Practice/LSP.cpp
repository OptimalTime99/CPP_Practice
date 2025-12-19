#include <iostream>

class Shape {
public:
    virtual int getArea() const = 0; // 넓이를 계산하는 순수 가상 함수
};

class Rectangle : public Shape {
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getArea() const override { return width * height; }

private:
    int width = 0;
    int height = 0;
};

class Square : public Shape {
public:
    void setSide(int s) { side = s; }
    int getSide() const { return side; }
    int getArea() const override { return side * side; }

private:
    int side = 0;
};

void testShape(Shape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
}

int main() {
    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(10);
    testShape(rect); // Area: 50

    Square square;
    square.setSide(7);
    testShape(square); // Area: 49
    return 0;
}
