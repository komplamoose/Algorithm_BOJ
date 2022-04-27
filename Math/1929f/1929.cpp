// 소수 구하기
#include <iostream>


using namespace std;

bool isPrime2(int n)
{
    if (n==1) return false;
    for (int i=2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;

    int cnt=0;
    for (int i=x; i<=y; i++) {
        if (isPrime2(i)) cout << i << "\n";
    }
}