// 15656, silver 3, N과 M 7
// https://www.acmicpc.net/problem/15656
// 조건 추가 : n의 숫자가 주어짐, 중복 허용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int arr[10];
int check[10]={0,};

int solve(int cnt)
{
    if (cnt == m){
        for (int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return 0;
    }else{
        for (int i=0; i<v.size(); i++){
            arr[cnt]=v[i];
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

    for (int i=0; i<n;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());

    solve(0);
    return 0;
}