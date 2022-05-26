/*
Bin Packing
최대 용량이 M인 가방이 무한대로 주어지고 N개의 아이템들이 주어졌을 때, 가장 적은 가방 꾸리는 경우를 만들어라

<전략> (Greedy)
1. 물건을 가중치 기준으로 정렬시킨다.
2. 가중치가 가장 큰 놈을 백팩에 담는다.
3. 가장 작은 놈을 꺼내서 용량 - 가중치랑 비교한다.
3-1. 넣을 수 있으면 넣는다.
4-1. 못넣으면 다시 집어넣고 패스한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int Bsize;
vector<int> w;

void solve()
{
    int answer=0;
    int lgP=0, smP=w.size()-1; // 각각 큰 것, 작은 것 가리키는 중

    while(lgP<=smP) // lgP가 smP보다 커지면, 리스트 다 탐색했단 뜻
    {
        int currentItem=w[lgP++]; // 제일 큰 놈 무조건 뽑음. 뽑으면 무조건 백팩 하나 쓰는거
        if (Bsize-currentItem >= w[smP]) smP--; // 넣을 수 있으면 넣고 아니면 놔둠
        answer++;
    }

    cout << answer << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> Bsize;

    w.resize(n);
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end(), greater<>()); // 큰 순으로 정렬

    solve();
}