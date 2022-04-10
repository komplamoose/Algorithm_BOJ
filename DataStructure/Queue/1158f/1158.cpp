// 1158, Silver 4, 요세푸스 문제
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

int n, k;

void solve(int n, int k)
{
    queue<int> q;
    for (int i=0 ; i<n;i++){
        q.push(i+1);
    }
    cout << "<";

    while(q.size()!=1)
    {
        for (int i=0;i<k-1;i++){
            int temp = q.front();
            q.push(temp);
            q.pop();
        }

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">";
}


int main()
{
    cin >> n;
    cin >> k;

    solve(n,k);

    return 0;
}