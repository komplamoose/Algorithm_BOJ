// 11404, Gold 4, 플로이드
// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <string.h>
#define INF 10000001
using namespace std;

int W[110][110], D[110][110];

void floyd(int n, int D[][110])
{
    int i, j, k;
    for (k=1; k<=n; k++){
        for (i=1; i<=n ; i++){
            for (j=1; j<=n ;j++){
                if (D[i][k]+D[k][j]<D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int main()
{
    int n, m;

    memset(D,-1,sizeof(D));
    cin >> n >> m;
    for (int i=0; i<m ; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if (D[v1][v2]!=-1){ // 값이 이미 들어있는 상태라면?
            if (D[v1][v2]>w){
                D[v1][v2]=w;
            }
        }else
            D[v1][v2] = w;
    }

    for (int i=1; i<=n;i++){
        for (int j=1;j<=n;j++){
            if (D[i][j]==-1) D[i][j]=INF;
            if (i==j){
                D[i][j]=0;
            }
        }
    }

    floyd(n,D);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n ; j++){
            if (D[i][j]==INF) cout << 0 << " ";
            else cout << D[i][j] << " ";
        }
        cout << "\n";
    }
}