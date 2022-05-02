// 비밀번호 찾기, 사이트와 비밀번호를 입력받아 사이트 입력받으면 비밀번호 출력하라
#include <iostream>
#include <map>

using namespace std;

map<string, string> pwbook;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    while(n--)
    {
        string site, pw;
        cin >> site >> pw;

        pwbook.insert({site,pw});
    }

    while(m--){
        string order;
        cin >> order;

        cout << pwbook[order] << "\n";
    }
}