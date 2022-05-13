/*
Greedy

1715, 카드 정렬하기
*/
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ;
int n;

void solve()
{
    int a, b;
    int answer=0;
    while(PQ.size()>1) {
        a=PQ.top(); PQ.pop();
        b=PQ.top(); PQ.pop();
        answer+=a+b;
        PQ.push(a+b);
    }

    cout << answer << "\n";
}

int main()
{
    cin >> n;

    for (int i=0; i<n; i++) {
        int input;
        cin >> input;
        PQ.push(input);
    }

    solve();
}