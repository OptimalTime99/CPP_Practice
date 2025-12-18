//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//void Print(const map<string, int>& m)
//{
//    for (auto& p : m) cout << p.first << ":" << p.second << " ";
//    cout << endl;
//}
//
//int main()
//{
//    map<string, int> m;
//    m["C"] = 3;
//    m["A"] = 1;
//    m["B"] = 2;
//    m["D"] = 4;
//
//    // 첫 출력 ( 원본 )
//    Print(m);
//
//    // 범위 요소 삭제
//    if (m.size() > 2)
//    {
//        auto first = m.begin();
//        auto last = m.end();
//        --last;
//        m.erase(next(first), last);
//    }
//
//    // 범위 삭제 후 출력
//    Print(m);
//}
//
//
///*
//A:1 B:2 C:3 D:4
//A:1 D:4
//
//*/