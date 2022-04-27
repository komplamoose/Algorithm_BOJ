// 소수
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
    int min=-1;
    int check=1;
    for (int i=x; i<=y; i++) {
        if (isPrime2(i)){
            cnt+=i;
            if (check){
                min = i;
                check=0;
            }
        }
    }

    if (min==-1) cout << "-1" << "\n";
    else cout << cnt << "\n" << min << "\n";
}