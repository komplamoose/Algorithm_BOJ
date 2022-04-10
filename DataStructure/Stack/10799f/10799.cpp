// Silver 3, 쇠막대기
// 스택
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string laser;
stack<char> s;

void solve()
{
    int pieces=0;
    int lcnt=0;
    for (int i=0; i<laser.length(); i++)
    {
        if (laser[i]=='('){
            s.push(laser[i]);
        }else if (laser[i]==')'){
            if (s.top() == '('){ // Laser!
                s.push(laser[i]);
                lcnt+=2;
                pieces+=s.size()-lcnt;
            }else if (s.top()==')'){// End of stick
                s.push(laser[i]);
                lcnt+=2;
                pieces++;
            }
        }
    }
    cout << pieces << "\n";
}

int main()
{
    cin >> laser;
    solve();
}