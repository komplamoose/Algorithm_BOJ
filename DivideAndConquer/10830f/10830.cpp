// 10830, Gold 4, 행렬 제곱, Not Solved
// https://www.acmicpc.net/problem/10830
#include <iostream>

using namespace std;
using ll = long long;

const int M = 1000;

long long matrix[5][5] = {0,};
long long result[5][5] = {0,};

int n; 

void calc(int n, long long a[][5], long long b[][5], long long c[][5])
{
    for (int i=0 ; i<n ; i++){
        for (int j=0; j<n ; j++){
            int sum=0;
            for (int k=0; k<n;k++){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum%1000;
        }
    }
}

void solve(int a, long long b)
{
    long long temp[5][5] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    while(b)
    {
        if (b&1){ // 비트연산 b가 짝수면 False, 홀수면 True
            calc(a,temp,matrix,result);
            for (int i=0 ; i<a ; i++){
                for (int j=0 ; j<a ; j++){
                    temp[i][j]=result[i][j];
                }
            }
        }
        calc(n,matrix,matrix,result);
        for (int i=0 ; i<a ; i++){
                for (int j=0 ; j<a ; j++){
                    matrix[i][j]=result[i][j];
                }
            }
        b >>= 1; //오른쪽으로 비트 한칸 밀기, 2로 나누는 것과 같음.
    }

    for (int i=0; i<n;i++){
        for (int j=0 ; j<n ; j++){
            cout << temp[i][j] << " ";
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
        }
    }

    solve(n, m);

    return 0;
}