#include <iostream>
#include <vector>

// 다음시간에

using namespace std;


int main()
{
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<long long int> DP(n*n+1);
    DP[0]=0;
    for (int i=1; i<=n*n; i++)
    {
        long long int num;
        cin >> num;

        DP[i]=DP[i-1]+num;
    }

    while(m--)
    {
        int aX, aY, bX, bY;
        cin >> aX >> aY >> bX >> bY;

        cout << DP[bX*bY]-DP[aX*aY-1] << "\n";
    }
}