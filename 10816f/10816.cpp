// 10816, Silver4, 숫자 카드 2
// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;


void solve(int n)
{
    for (int i=0 ; i<n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int m;

    cin >> m;

    for (int i =0 ; i< m ;i++)
    {
        int input;
        cin >> input;
        cout << upper_bound(v.begin(), v.end(), input) - lower_bound(v.begin(),v.end(), input) << " ";
        // upper_bound의 반환값 -> key 값이 마지막으로 등장하는 인덱스 주소
        // lower_bound의 반환값 -> key 값이 처음으로 등장하는 인덱스 주소
        // 이 둘을 빼면 key 값이 배열 내에 몇 개 존재하는 지 알 수 있다.
    }
}

int main(void)
{
    int n;
    cin >> n;

    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    solve(n);

    return 0;
}