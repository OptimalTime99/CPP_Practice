#include <iostream>

class Rectangle {
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getArea() const { return width * height; }

private:
    int width = 0;
    int height = 0;
};

class Square : public Rectangle {
public:
    void setWidth(int w) override {
        Rectangle::setWidth(w);
        Rectangle::setHeight(w); // 정사각형은 너비와 높이가 같아야 함
    }
    void setHeight(int h) override {
        Rectangle::setHeight(h);
        Rectangle::setWidth(h); // 정사각형은 너비와 높이가 같아야 함
    }
};

void testRectangle(Rectangle& rect) {
    rect.setWidth(5);
    rect.setHeight(10);
    std::cout << "Expected area: 50, Actual area: " << rect.getArea() << std::endl;
}

int main() {
    Rectangle rect;
    testRectangle(rect); // Expected area: 50

    Square square;
    testRectangle(square); // Expected area: 50, Actual area: 100 (문제 발생)
    return 0;
}
