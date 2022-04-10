// 1406, Silver 3. 에디터
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> str;
list<char>::iterator cursor;

void solve(int n)
{
    cursor = str.end();

    for (int i = 0 ; i<n;i++){
        char input;
        cin >> input;
        if (input=='L'){
            if (cursor==str.begin()){
            }else{
                cursor--;
            }
        }else if (input=='D'){
            if (cursor==str.end()){
            }else{
                cursor++;
            }
        }else if (input=='B'){
            if (cursor==str.begin()){
            }else{
                cursor = str.erase(--cursor); // Vector는 자동으로 빈 자리를 채워주지만 list는 그러지 않는다. erase의 리턴값을 이용해 iter를 재지정해줘야한다. 아니면 갈 길을 잃어버림.
            }
        }else if (input=='P'){
            char c;
            cin >> c;
            str.insert(cursor,c);
        }
    }

    for (auto loop : str){
        cout << loop;
    }
    cout << "\n" ;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    int n;
    cin >> n;
    string::iterator iter = s.begin();

    for (iter = s.begin(); iter!=s.end(); iter++){
        str.push_back(*iter);
    }

    solve(n);
}