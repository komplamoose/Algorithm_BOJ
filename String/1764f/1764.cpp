/*
듣보잡, 1764
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> mapp;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> dbj;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        mapp.insert({s,i});
    }

    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        if (mapp.find(s)!=mapp.end()){ // find
            dbj.push_back(s);
        }
    }

    sort(dbj.begin(), dbj.end());

    cout << dbj.size() << "\n";
    for (auto loop : dbj) {
        cout << loop << "\n";
    }
}