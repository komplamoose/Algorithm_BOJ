// 11780, Gold 2, 플로이드 2
// https://www.acmicpc.net/problem/11780
// 경로 출력까지 한다. 
#include <iostream>
#include <string.h>
#include <vector>
#define INF 10000001
using namespace std;

vector<int> v;

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

void path(int i, int j)
{
    if (P[i][j]!=0)
    {
        path(i, P[i][j]);
        v.push_back(P[i][j]);
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
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            W[i][j]=D[i][j];
        }
    }
    floyd(n,D,P);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n ; j++){
            if (D[i][j]==INF) cout << 0 << " ";
            else cout << D[i][j] <<" ";
        }
        cout << "\n";
    }
    
    for (int i=1; i<=n;i++){
        for (int j=1; j<=n; j++){
            if (j==i||(W[i][j]==INF&&P[i][j]==0)){
                cout << "0";
            }else{
                path(i,j);
                int k = 2+v.size();
                cout << k << " ";
                cout << i << " ";
                for (auto loop : v){
                    cout << loop << " ";
                }
                cout << j;
                v.clear();
            }
            cout << "\n";
        }
    }
}