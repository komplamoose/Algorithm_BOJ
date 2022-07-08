#include <iostream>

using namespace std;

long long a,b,c;

long long solve(int x, int y)
{
    if (y==0)
        return 1;
    long long n = solve(x, y/2);
    long long temp = n*n%c;

    if (y%2==0)
        return temp;
    else
        return x*temp%c;
}

int main()
{
    cin >> a >> b >> c;

    cout << solve(a,b)%c << endl;
}