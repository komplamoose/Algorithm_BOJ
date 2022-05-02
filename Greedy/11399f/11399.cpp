// ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> line;
    for (int i=0; i<n ; i++) {
        int input;
        cin >> input;
        line.push_back(input);
    }

    sort(line.begin(), line.end());

    int time=0;
    for (int i=0; i<n; i++){
        time += line[i]*(n-i);
    }

    cout << time << "\n";
}