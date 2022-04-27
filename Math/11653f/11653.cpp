// 소인수분해
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int i=2;
    while(n!=1) {
        if (n%i==0) {
            n/=i;
            cout << i << "\n";
        } else {
            i++;
        }
    }
}