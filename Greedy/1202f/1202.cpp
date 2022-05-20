// 1202, 보석도둑, 그리디
// 물건 중 가장 비싼 물건을 찾아서,
// 가방 중 그 물건을 담을 수 있는 가장 작은 용량에 담는다.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;

pair<int, int> jewel[300003]; // 가격 - 무게
multiset<int> pack;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long answer=0;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> jewel[i].second >> jewel[i].first; // 무게 - 가격으로 받음, 이후 가격으로 정렬
    }
    sort(jewel, jewel+n); // 가격 작은 순으로 정렬됨

    for (int i=0; i<k; i++) {
        int temp;
        cin >> temp;
        pack.insert(temp);
    }

    for (int i=n-1; i>=0; i--) { // 가격 큰 놈부터 찾기
        int value = jewel[i].first;
        int steel = jewel[i].second;

        auto it = pack.lower_bound(steel);
        if (it==pack.end()) continue; // 못넣으면 스킵
        answer+=value; // 넣으면 가방에 넣고, 목록에서 지움
        pack.erase(it);
    }

    cout << answer << endl;
}