// 1620, 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;


    map<string,int> poke_to_int;
    map<int, string> int_to_poke;
    for (int i=1; i<=n; i++) {
        string p;
        cin >> p;
        poke_to_int.insert({p,i});
        int_to_poke.insert({i,p});
    }

    for (int i=0; i<m; i++) {
        string order;
        cin >> order;
        if (atoi(order.c_str())) { // if order is int
            cout << int_to_poke[atoi(order.c_str())] << "\n";
        }else {
            cout << poke_to_int[order] << "\n";
        }
    }
}