// 1182, Silver 2, 부분수열의 합
// https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int n, m;
vector<int> v;
int arr[20];
int check[20]={0,};

int result=0;

int solve(int cnt)
{
    if (accumulate(arr,arr+cnt,0)==m){
        result++;
        return 0;
    }else{
        for (int i=0; i<v.size(); i++){
            if (check[i]==0){
                arr[cnt]=v[i];
                check[i]=1;
                solve(cnt+1);
                check[i]=0;
            }
        }
    }
    return 1;
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    v.resize(n);
    for (int i=0; i<n;i++){
        int input;
        cin >> input;
        v[i]=input;
    }
    
    sort(v.begin(),v.end());

    solve(0);

    cout << result << "\n";
    return 0;
}