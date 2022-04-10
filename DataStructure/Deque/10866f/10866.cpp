// BOJ 10866, Silver 4, 덱 
// https://www.acmicpc.net/problem/10866
// 앞 뒤에서 모두 입출력이 가능한 자료구조다. 
#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;


void solve(int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        string order;
        cin >> order;
        

        if (order=="push_front"){
            int input;
            cin >> input;
            dq.push_front(input);
        }else if (order=="push_back"){
            int input;
            cin >> input;
            dq.push_back(input);
        }else if (order=="pop_front"){
            if (dq.empty()){
                cout << "-1\n";
            }else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }else if (order=="pop_back"){
            if (dq.empty()){
                cout << "-1\n";
            }else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }else if (order=="size"){
            cout << dq.size() << "\n";
        }else if (order=="empty"){
            if (dq.empty()){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else if (order=="front"){
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << "\n";
        }else if (order=="back"){
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << "\n";
        }
    }
}

int main()
{
    int n;

    cin >> n;

    solve(n);
}

