// 15665, silver 2, n과 m 11
// https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
vector<int> arr(4,0);
int check[10]={0,};
set<vector<int>> s;

int solve(int cnt)
{
    if (cnt == m){
        vector<int> cp(m);
        copy(arr.begin(),arr.end(),cp.begin());
        s.insert(cp);
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
    arr.resize(m);
    sort(v.begin(), v.end());

    solve(0);

    for (auto loop1 : s)
    {
        for (auto loop2 : loop1){
            cout << loop2 << " ";
        }
        cout << "\n";
    }
    return 0;
}