#include <iostream>

using namespace std;

int tri[500][500];
int DP[500][500];

int main()
{
    int n;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            cin >> tri[i][j];
        }
    }

    DP[0][0]=tri[0][0];

    for (int i=1; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (j==0)
            {
                DP[i][j]=DP[i-1][j]+tri[i][j];
            }
            else if (j==i)
            {
                DP[i][j]=DP[i-1][j-1]+tri[i][j];
            }
            else
            {
                DP[i][j]=max(DP[i-1][j], DP[i-1][j-1])+tri[i][j];
            }
        }
    }

    int maxSum=0;
    for (int i=0; i<n; i++)
    {
        if (maxSum<DP[n-1][i]) {
            maxSum=DP[n-1][i];
        }
    }

    cout << maxSum << endl;
}