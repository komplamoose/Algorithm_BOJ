// 11651, Silver 5 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinate{
    int x;
    int y;
};

vector<Coordinate> v;

bool COMP(Coordinate a, Coordinate b)
{
    if (a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

void solve(int n)
{
    for (int i=0; i<n ;i++){
        Coordinate input;
        cin >> input.x >> input.y;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), COMP);
}

int main(void)
{
    int n;

    cin >> n;

    solve(n);

    for (int i=0 ; i<n ;i++){
        cout << v[i].x << " " << v[i].y << "\n";
    }
}