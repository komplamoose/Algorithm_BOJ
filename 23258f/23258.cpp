// 23258, Gold 1, 밤편지
// https://www.acmicpc.net/problem/23258
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
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
    
    for (int i=0; i<m; i++){ //TODO: 마지막 출력 찾아야 함.
        int C, a, b;
        cin >> C >> a >> b;
        while(1){
            int checker=1;
            v.clear();
            path(a,b);
            int sum=0;
            for (int j=0; j<v.size();j++){
                sum+=pow(2,v[i]);
                if (sum>=pow(2,C)){
                    checker=0;
                    P[v[i-1]][v[i]]=0;
                    break;
                }
            }
            if (checker==1) break;
        }
        int s=0;
        if (v.size()==0){
            s=W[a][b];
        }else{
            s=W[a][v[0]];
            for (int j=1; j<v.size(); j++){
                s+=W[v[j-1]][v[j]];
            }
            s+=W[v.back()][b];
        }
        cout << s << endl;
        cout << "\n";
    }
}
