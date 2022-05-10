// 2217, 로프
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int w[100001];

void solve()
{
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }
    
    sort(w, w+n);

    int answer=0;
    for (int i=1; i<=n; i++) {
        answer = max(answer,w[n-i]*i);
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    solve();
}