#include <iostream>

using namespace std;

int a, b;
int minExp=1000000001;


bool promising(int c, int idx)
{
    if (idx+1 > minExp) return false;
    if (c*2 > b/2 && c*2!=b) return false;
    if (c*10+1>b/2&&c*10+1!=b) false;
    return true;
}

void solve(int idx, int current)
{
    if (current==b)
    {
        if (idx<minExp)
            minExp=idx;
    }
    else
    {
        if (promising(current, idx))
        {
            if (current*10+1<=b)
                solve(idx+1, current*10+1);
            solve(idx+1, current*2);
        }
    }
}

int main()
{
    cin >> a >> b;

    solve(0,a);

    if (minExp==1000000001)
        cout << -1 << endl;
    else
        cout << minExp+1 << endl;
}
