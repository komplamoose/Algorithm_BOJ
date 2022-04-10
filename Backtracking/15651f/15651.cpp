// 15651, Silver 3, N과 M 3
// https://www.acmicpc.net/problem/15649
// 백트래킹
// 조건 추가 : 중복된 수를 골라도 됨.
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int v[10];
int check[10]={0,};

int solve(int cnt)
{
    if (cnt == m){
        for (int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return 0;
    }else{
        for (int i=1; i<=n; i++){
            v[cnt]=i;
            check[i]=1;
            solve(cnt+1);
            check[i]=0;
        }
    }
    return 1;
}

int main()
{

    cin >> n >> m;

    solve(0);
    return 0;
}