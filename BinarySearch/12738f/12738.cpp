// 12738, 가장 긴 증가하는 부분수열 3
#include <iostream>
#include <algorithm>

using namespace std;

int L[1000001], len, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        int here;
        cin >> here;
        auto pos = lower_bound(L+1, L+len+1, here);
        *pos=here;
        if (pos==L+len+1) { // here보다 더 크거나 같은 값이 List에 없다면
            len++;
        }
    }

    cout << len << endl;
}