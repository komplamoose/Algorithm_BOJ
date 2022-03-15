// 1181, silver 5, 단어정렬
// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;

bool COMP(string s1, string s2)
{
    if (s1.length() == s2.length()) return s1 < s2;
    else{
        return s1.length() < s2.length();
    }
}

void solve(int n)
{
    for (int i=0 ; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(),v.end(),COMP);

    v.erase(unique(v.begin(),v.end()),v.end());

    for (auto loop : v){
        cout << loop << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;

    solve(n);
}