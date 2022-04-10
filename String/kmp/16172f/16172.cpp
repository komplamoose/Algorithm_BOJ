// 16172, Gold 2, 나는 친구가 적다 (Large)
// https://www.acmicpc.net/problem/16172
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
string t, p;
int pi[10000000]={0,};

void solve()
{
    int i=0, j=0, trg=0;
    while(i<t.length())
    {
        while (j>0&&t[i]!=p[j]) // while 문 순서 바꾸면 안됨. ㅠㅠ
        {
            j=pi[j-1];
        }
        if (t[i]==p[j])
        {
            if (j==p.length()-1){
                cout << "1\n";
                exit(0);
            }else{
                j++;
            }
        }
        i++;
    }
    cout << "0\n";
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
    t=regex_replace(t,regex("[0-9]"),"");
    getline(cin,p);
    
    table();
    solve();

    return 0;
}