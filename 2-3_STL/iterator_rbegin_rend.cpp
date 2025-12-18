#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<string> words = { "apple", "banana", "cherry", "date", "aaaaa", "bbbbb"};

    string target = "cherry";

    auto it = find(words.rbegin(), words.rend(), target);

    if (it != words.rend()) {
        cout << "Word \"" << target << "\" found at reverse index "
            << distance(words.rbegin(), it) << " (from the back)" << endl;
        cout << "Word \"" << target << "\" found at forward index "
            << distance(words.begin(), it.base()) - 1 << " (from the front)" << endl;
    }
    else {
        cout << "Word \"" << target << "\" not found." << endl;
    }

    return 0;
}
// 출력:
// Word "banana" found at reverse index 3 (from the back)
// Word "banana" found at forward index 2 (from the front)
