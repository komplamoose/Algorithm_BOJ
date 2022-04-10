// 13171, Silver 4, A
// https://www.acmicpc.net/problem/13171
#include <iostream>

using namespace std;

unsigned long long a, x;
const unsigned long long M = 1000000007;

void solve(unsigned long long a, unsigned long long b)
{
    unsigned long long temp = 1;
    if (b==0){
        cout << 1;
    }

    while(b)
    {
        a=a%M;
        if (b&1) // 비트연산 b가 짝수면 False, 홀수면 True
            temp = (temp* a)%M;
        
        a=(a*a)%M;
        b >>= 1; //오른쪽으로 비트 한칸 밀기, 2로 나누는 것과 같음.
    }

    cout << temp%M;
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    cin >> a;
    cin >> x;

    solve(a,x);

    return 0;
}