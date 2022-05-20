// 1781, 컵라면, Greedy
// 데드라인 스케줄링
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

typedef long long int lli;

bool compare(pair<lli, int> a, pair<lli, int> b)
{
    if (a.first==b.first) {
        return a.second> b.second;
    }
    return a.first > b.first;
}

pair<lli, int> schedule[200002]; // profit - deadling
bool s[200002];

bool possibleCheck(vector<pair<lli, int>> temp)
{
    for (int i=0; i < temp.size(); i++) {
        if (temp[i].second < i+1) return 0;
    }
    return 1;
} 


void solve()
{
    vector<pair<lli, int>> S;
    vector<pair<lli, int>> K;
    S.push_back(schedule[0]); // 제일 큰거 일단 집어넣음
    
    for (int i=1; i<n; i++) {
        K.resize(S.size());
        copy(S.begin(), S.end(), K.begin());
        int index=0;
        while(index < K.size() && K[index].second <= schedule[i].second)
            index++;
        K.insert(K.begin()+index, schedule[i]);

        if (possibleCheck(K)){
            S.resize(K.size());
            copy(K.begin(), K.end(), S.begin());
        }
    }

    int sum=0;
    for (auto loop : S) {
        sum += loop.first;
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> schedule[i].second >> schedule[i].first;
    }

    sort(schedule, schedule+n, compare);

    solve();
}