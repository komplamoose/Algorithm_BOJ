// 소수 찾기
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
    int nb;
    cin >> nb;

    int cnt=0;
    for (int i=0; i<nb; i++) {
        int x;
        cin >> x;
        if (isPrime2(x)) cnt++;
    }

    cout << cnt << "\n";
}