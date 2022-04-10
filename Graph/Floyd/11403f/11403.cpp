// 11403, Silver 1, 경로 찾기
// https://www.acmicpc.net/problem/11403
// 플로이드-와샬 알고리즘
#include <iostream>
#include <string.h>
#define INF 10000001
using namespace std;


int W[110][110], D[110][110], P[110][110]={0,};

void floyd(int n, int D[][110], int P[][110])
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


int main()
{
    int n, m;

    memset(D,-1,sizeof(D));
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int input;
            cin >> input;
            D[i][j]=input;
        }
    }
    for (int i=1; i<=n;i++){
        for (int j=1;j<=n;j++){
            if (D[i][j]==0) D[i][j]=INF;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            W[i][j]=D[i][j];
        }
    }
    floyd(n,D,P);
    for (int i=1; i<=n;i++){
        for (int j=1; j<=n; j++){
            if ((W[i][j]==INF&&P[i][j]==0)){
                cout << "0 ";
            }else{
                cout << "1 ";
            }
        }
        cout << "\n";
    }
}