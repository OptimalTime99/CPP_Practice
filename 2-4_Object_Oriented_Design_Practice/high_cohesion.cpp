#include <iostream>
#include <string>
#include <algorithm> // for transform
using namespace std;

class MessageHandler {
public:
    void printMessage(const string& message) {
        string upperMessage = message;
        transform(upperMessage.begin(), upperMessage.end(), upperMessage.begin(), ::toupper);
        cout << "Message: " << upperMessage << endl;
    }
};

class Calculator {
public:
    void calculateSum(int a, int b) {
        cout << "Sum: " << (a + b) << endl;
    }

    void calculateProduct(int a, int b) {
        cout << "Product: " << (a * b) << endl;
    }
};

class StringManipulator {
public:
    void reverseString(const string& str) {
        string reversed = string(str.rbegin(), str.rend());
        cout << "Reversed: " << reversed << endl;
    }
};

int main() {
    MessageHandler messageHandler;
    messageHandler.printMessage("Hello");

    Calculator calculator;
    calculator.calculateSum(5, 10);
    calculator.calculateProduct(5, 10);

    StringManipulator stringManipulator;
    stringManipulator.reverseString("world");

    return 0;
}
