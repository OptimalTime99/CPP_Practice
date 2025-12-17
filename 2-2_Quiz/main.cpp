#include <iostream>
using namespace std;

//template <typename T1, typename T2>
//auto Add(T1 a, T2 b)
//{
//    return a + b;
//}
//
//
//template <typename T1, typename T2>
//decltype(T1{} + T2{}) Add(T1 a, T2 b)
//{
//    return a + b;
//}

template <typename T1, typename T2>
auto Add(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}


int main()
{
    cout << Add(3, 3.5) << endl;
    return 0;
}