// 1389, Silver 1, 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389
#include <iostream>
#include <string.h>
#define INF 1000001
using namespace std;

int W[100][100], D[100][100], P[100][100]={0,};

void floyd(int n, int D[][100], int P[][100])
{
    int i, j, k;

    for (i=1; i<=n;i++){
        for (j=1; j<=n;j++){
            P[i][j]=0;
        }
    }
    for (k=1; k<=n; k++){
        for (i=1; i<=n ; i++){
            for (j=1; j<=n ;j++){
                if (D[i][k]+D[k][j]<D[i][j]){
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void path(int i, int j)
{
    if (P[i][j]!=0)
    {
        path(i, P[i][j]);
        cout << P[i][j] << " ";
        path(P[i][j], j);
    }
}

int main()
{
    int n, m;

    memset(D,-1,sizeof(D));
    cin >> n >> m;
    for (int i=0; i<m ; i++){
        int v1, v2, w;
        cin >> v1 >> v2;
        D[v1][v2] = 1;
        D[v2][v1] = 1;
    }
    for (int i=1; i<=n;i++){
        for (int j=1;j<=n;j++){
            if (D[i][j]==-1) D[i][j]=INF;
            if (i==j){
                D[i][j]=0;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            W[i][j]=D[i][j];
        }
    }
    floyd(n,D,P);

    int min = 0;
    int minI;
    for (int i=1; i<=n ;i++){
        int sum=0;
        for (int j=1; j<=n; j++){
            sum+=D[i][j];
        }
        if (min==0){
            min=sum;
            minI=i;
        }else{
            if (min>sum){
                min=sum;
                minI=i;
            }
        }
    }

    cout << minI <<"\n";
}