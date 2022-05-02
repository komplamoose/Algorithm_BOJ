// 7662, 이중 우선순위 큐
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        multiset<int> mset;
        int m;
        cin >> m;

        for (int i=0; i<m; i++){
            char od; int num;
            cin >> od >> num;
            if (od == 'I') mset.insert(num);
            else {
                if (mset.empty()) continue;
                else {
                    if (num == 1){
                        mset.erase(--mset.end());
                    }
                    else{
                        mset.erase(mset.begin());
                    }
                }
            }
        }
        if (mset.empty()) cout << "EMPTY\n";
        else cout << *(--mset.end()) << " " << *(mset.begin()) << "\n";
    }
}