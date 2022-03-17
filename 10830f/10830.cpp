// 10830, Gold 4, 행렬 제곱, Not Solved
// https://www.acmicpc.net/problem/10830
// TODO: https://www.acmicpc.net/problem/13171 거듭제곱 문제 먼저 풀고 도전하자. 
#include <iostream>

using namespace std;

long long matrix[5][5] = {0,};
long long result[5][5] = {0,};
long long temp[5][5] = {0,};

int n; 

void calc(int n, long long a[][5], long long b[][5], long long c[][5])
{
    for (int i=0 ; i<n ; i++){
        for (int j=0; j<n ; j++){
            int sum=0;
            for (int k=0; k<n;k++){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}

void solve(int n, long long m)
{

    

    for (int i=0; i<n; i++){
        for (int j=0 ; j<n ; j++){
            cout << result[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    long long m;
    cin >> n;
    cin >> m;

    for (int i=0 ; i<n ;i++){
        for (int j=0 ; j<n ;j++){
            cin >> matrix[i][j];
            temp[i][j]=matrix[i][j];
        }
    }

    solve(n, m);

    return 0;
}