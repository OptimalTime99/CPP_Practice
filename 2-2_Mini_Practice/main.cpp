#include <iostream>
using namespace std;

void process(int a)
{
    cout << "Int 버전 호출됨" << endl;
}

void process(char a)
{
    cout << "Char 버전 호출됨" << endl;
}

int main()
{
    short s = 50;
    process(s);

    return 0;
}

/* 결과
Int 버전 호출됨

*/

/* 이유
process 함수의 인자로 short 자료형이 들어갔지만, 매개변수로 short 자료형을 받는 오버로딩된 함수는 없다.
정확히 일치하는 자료형이 없는 경우, 컴파일러는 타입 승격을 시도하는데 short의 경우 int로만 승격할 수 있기에 위와 같은 결과가 나온다.
*/