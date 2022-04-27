// 10814, 나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool COMPARE(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int n;

int main()
{
    cin >> n;

    vector<pair<int, string>> v;
    for (int i=0; i<n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), COMPARE);

    for (auto loop : v) {
        cout << loop.first << " " << loop.second << "\n";
    }
}