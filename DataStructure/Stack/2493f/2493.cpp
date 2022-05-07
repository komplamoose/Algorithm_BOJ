// 2493, top
/*
만약 쏴서 top에 닿았다 -> 이새끼가 제일 가까우면서 맞은 애임. 뒤에 잇는 애들도 얘한테 쳐맞을 수 잇음
top보다 target이 크다 -> 뒤에 오는 애들이 쏴봣자 어짜피 target이 받을거니까 탑 빼버려
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

stack<int> tops;
int idx[500001];
vector<int> v;
int top=0;

void solve()
{
    int max=-1;
    for (int i=0; i<n; i++) {
        int tg;
        cin >> tg;
        while (!tops.empty()){
            if (tops.top()>=tg){
                cout << idx[top] << " ";
                break;
            } else {
                top--;
                tops.pop();
            }
        }

        if (tops.empty()) cout << "0 ";
        top++;
        idx[top]=i+1;
        tops.push(tg);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    solve();
}