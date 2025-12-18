#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> teamScores;

    teamScores[85] = "라프 코스터";
    teamScores[92] = "비야네 스트롭스트룹";
    teamScores[78] = "제프리 리처";

    cout << "--- 결과 ---" << endl;

    for (const auto& pair : teamScores)
    {
        cout << pair.first << " 점수: " << pair.second << endl;
    }

    return 0;
}

/*
--- 결과 ---
78 점수: 제프리 리처
85 점수: 라프 코스터
92 점수: 비야네 스트롭스트룹

*/
// map 컨테이너가 내부적으로 오름차순 정렬을 하고 있기 때문에 입력순서는 출력순서에 관계 없다.