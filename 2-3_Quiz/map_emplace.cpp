#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> m;
    m["Bow"] = 1;

    auto result = m.emplace("Bow", 999);
    //auto result = m.insert({ "Bow", 999 });

    cout << (result.second ? "emplace success" : "emplace fail") << endl;
    cout << "Bow=" << m["Bow"] << endl;
}


/*
emplace fail
Bow=1

*/