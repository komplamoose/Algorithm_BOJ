/*
d[0][1] => 첫 번째 집 색으로 빨강을 선택했을 때의 최소 경우
d[1][1] => 첫 번째 집 색으로 초록을 선택했을 때의 최소 경우
d[2][1] => 첫 번째 집 색으로 파랑을 선택했을 때의 최소 경우

d[0][i] => min(d[1][i-1], d[2][i-1]) + a[i][0];
d[1][i] => min(d[0][i-1], d[2][i-1]) + a[i][1];
d[2][i] => min(d[1][i-1], d[2][i-1]) + a[i][2];
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int house[1001][3];
int d[3][1001];
int n;
char color;

int main()
{
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    d[0][1] = house[1][0];
    d[1][1] = house[1][1];
    d[2][1] = house[1][2];
    for (int i=2; i<=n; i++) {
        d[0][i]=min(d[1][i-1], d[2][i-1]) + house[i][0];
        d[1][i]=min(d[0][i-1], d[2][i-1]) + house[i][1];
        d[2][i]=min(d[0][i-1], d[1][i-1]) + house[i][2];
    }

    cout << min(min(d[0][n],d[1][n]),d[2][n]) << "\n";
}