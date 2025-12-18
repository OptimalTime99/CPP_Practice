#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort 포함
using namespace std;

// 캐릭터 데이터 구조체
struct Character
{
    int id;         // 고유 식별자 (ID)
    int starRank;   // 성급
    int awakening;  // 각성 단계
    int level;      // 레벨

    void print() const
    {
        cout << "ID: " << id << " 성급: " << starRank;
        cout << " 각성: " << awakening << " Lv: " << level << endl;
    }
};

bool compareCharacters(const Character& a, const Character& b)
{
    if (a.starRank != b.starRank) return a.starRank > b.starRank;
    if (a.awakening != b.awakening) return a.awakening > b.awakening;
    if (a.level != b.level) return a.level > b.level;
    return a.id < b.id;
}

int main()
{
    vector<Character> characters =
    {
        {101, 5, 3, 50},
        {102, 5, 3, 70},
        {103, 5, 3, 70},
        {104, 4, 5, 99}
    };

    cout << "--- 정렬 전 ---" << endl;
    for (const auto& c : characters)
    {
        c.print();
    }

    sort(characters.begin(), characters.end(), compareCharacters);

    cout << "--- 정렬 후 ---" << endl;
    // 예상 결과: ID 102, 103, 101, 104 순으로 출력되어야 합니다.
    for (const auto& c : characters)
    {
        c.print();
    }

    return 0;
}

/* 결과
--- 정렬 전 ---
ID: 101 성급: 5 각성: 3 Lv: 50
ID: 102 성급: 5 각성: 3 Lv: 70
ID: 103 성급: 5 각성: 3 Lv: 70
ID: 104 성급: 4 각성: 5 Lv: 99
--- 정렬 후 ---
ID: 102 성급: 5 각성: 3 Lv: 70
ID: 103 성급: 5 각성: 3 Lv: 70
ID: 101 성급: 5 각성: 3 Lv: 50
ID: 104 성급: 4 각성: 5 Lv: 99

*/