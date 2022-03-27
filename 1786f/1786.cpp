// 1786, Platinum 5, 찾기
// https://www.acmicpc.net/problem/1786
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string t, p;
int pi[10000000]={0,};
vector<int> v;

void solve()
{
    int i=0, j=0;
    while(i<t.length())
    {
        while (j>0&&t[i]!=p[j]) // while 문 순서 바꾸면 안됨. ㅠㅠ
        {
            j=pi[j-1];
        }
        if (t[i]==p[j])
        {
            if (j==p.length()-1){
                v.push_back(i-j+1);
                j=pi[j];
            }else{
                j++;
            }
        }
        i++;
    }
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
    getline(cin,p);
    
    table();
    solve();


    cout << v.size() << "\n";
    for (auto loop : v)
    {
        cout << loop << " ";
    }
    cout<<"\n";

    return 0;
}