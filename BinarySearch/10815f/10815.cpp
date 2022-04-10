#include <iostream>
#include <algorithm>

using namespace std;

int a[500000];

void solve(int n)
{
    for (int i =0 ; i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);

    int m;

    cin >> m;

    for (int i = 0 ; i < m ; i++){
        int ck;
        cin >> ck;
        if (binary_search(a,a+n,ck)){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
}

int main()
{
    int n;

    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    cin >> n;

    solve(n);

    return 0;
}