// 6603, Silver 2, Lotto
// https://www.acmicpc.net/problem/6603
// TODO: 백트래킹 좀 더 공부하고 다시 공부하자. 
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& v)
{

}

void solve()
{
    int n;
    while(1)
    {
        cin >> n;
        if (n==0) break;

        vector<int> chosen;
        for (int i=0 ; i<n; i++)
        {
            int input;
            cin >> input;
            chosen.push_back(input);
        }
    }
}

int main()
{
    solve();

    return 0;
}