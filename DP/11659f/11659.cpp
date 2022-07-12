#include <iostream>
#include <vector>

using namespace std;


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    long nums;

    cin >> n >> m;
    vector<long> preSums(n+1);

    preSums[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin >> nums;
        preSums[i]=preSums[i-1]+nums;
    }

    for (int i=0; i<m; i++)
    {
        int from, to;
        cin >> from >> to;
        cout << preSums[to]-preSums[from-1] << "\n";
    }
}