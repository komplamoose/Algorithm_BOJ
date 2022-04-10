// 10871, Bronze 3, X보다 작은 수
// https://www.acmicpc.net/problem/10871
// 수학, 구현
// 숫자 N개로 이뤄진 수열과 정수 X를 입력받아, 수열에서 X보다 작은 수를
// "입력받은 대로" 모두 출력한다.
#include <iostream>

using namespace std;


void solve(int n, int x)
{
    for (int i=0; i<n ; i++)
    {
        int input;
        cin >> input;
        if (input<x)
            cout << input << " ";
    }
}

int main()
{
    int n, x;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    solve(n, x);
    return 0;
}