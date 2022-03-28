// 23627, Bronze 2, driip
// https://www.acmicpc.net/problem/23627
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
string t, p;
int pi[1000]={0,};

void solve()
{
    int i=t.length()-5, j=0, trg=0;
    while(i<t.length())
    {
        while (j>0&&t[i]!=p[j]) // while 문 순서 바꾸면 안됨. ㅠㅠ
        {
            j=pi[j-1];
        }
        if (t[i]==p[j])
        {
            if (j==p.length()-1){
                cout << "cute\n";
                exit(0);
            }else{
                j++;
            }
        }
        i++;
    }
    cout << "not cute\n";
}

void table()
{
    int j=0;
    for (int i=1; i<p.size(); i++){
        while(j>0&&p[i]!=p[j]){
            j=pi[j-1];
        }
        if (p[j]==p[i]){
            pi[i]=++j;
        }
    }
}

int main()
{
    getline(cin,t);
    p = "driip";
    
    table();
    solve();

    return 0;
}