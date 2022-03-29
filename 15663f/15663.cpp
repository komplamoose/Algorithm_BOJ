// 15663, silver 2, n과 m 9
// https://www.acmicpc.net/problem/15663
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
            if (check[i]==0){
                int kk=i+1;
                while(v[kk]==v[i]){
                    check[kk++]=0;
                }
                arr[cnt]=v[i];
                check[i]=1;
                solve(cnt+1);
                check[i]=0;
                kk=i+1;
                while(v[kk]==v[i]){
                    check[kk++]=1;
                }
            }
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