#include <iostream>
#include <string>
#include <algorithm> // for transform
using namespace std;

class Utility {
public:
    void printMessage(const string& message) {
        string upperMessage = message;
        transform(upperMessage.begin(), upperMessage.end(), upperMessage.begin(), ::toupper);
        cout << "Message: " << upperMessage << endl;
    }

    void calculateSum(int a, int b) {
        cout << "Sum: " << (a + b) << endl;
    }

    void calculateProduct(int a, int b) {
        cout << "Product: " << (a * b) << endl;
    }

    void reverseString(const string& str) {
        string reversed = string(str.rbegin(), str.rend());
        cout << "Reversed: " << reversed << endl;
    }
};

int main() {
    Utility util;
    util.printMessage("Hello");
    util.calculateSum(5, 10);
    util.calculateProduct(5, 10);
    util.reverseString("world");
    return 0;
}
