#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int n;

int main()
{
    long long int answer=0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    v.resize(n);

    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
    }

    sort(v.begin(), v.end()); // 데드라인 기준으로 오름차순 정렬

    int index=n-1; // 데드라인 가장 긴 놈부터 선택
    priority_queue<int> PQ;

    for (int i=n-1; i>=0; i--) { // 스케줄을 뒤에서부터 선택함
        while(index>=0 && v[index].first == i){ // 제일 끝 데드라인과 동일한 데드라인들끼리 비교
            PQ.push(v[index].second);
            index--;
        }

        // 만약 데드라인이 i라면, i+1의 데드라인을 가진 놈도 거기 들어갈 수 있음
        if (!PQ.empty()) {
            answer += PQ.top(); // i번째 스케줄 선택
            PQ.pop();
        }
    }

    cout << answer << endl;
}