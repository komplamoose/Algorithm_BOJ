// 1966. silver 3, Printer Queue
// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>

using namespace std;

int n;

struct Paper{
    int num;
    int priority;
};

bool priorityCheck(queue<Paper> Q, int p)
{
    int maxP=p;
    if (Q.size()==1)
        return false;
    for (int i=0 ; i<Q.size() ;i++){
        if (maxP < Q.front().priority){
            return true;
        }else{
            Paper temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
    }
    return false;
}

void printQ(queue<Paper> Q, int a)
{
    int cnt=1;
    while(!Q.empty())
    {
        int fp;
        fp=Q.front().priority;
        if (priorityCheck(Q,fp)){
            Paper temp = Q.front();
            Q.pop();
            Q.push(temp);
        }else{
            if (Q.front().num==a){
                cout << cnt << "\n";
            }
            cnt++;
            Q.pop();
        }
    }
}

void solve()
{
    for (int i=0; i<n ;i++){
        queue<Paper> q;
        int x, a;
        cin >> x >> a;
        for (int j=0; j<x; j++){
            Paper temp;
            temp.num=j;
            cin >> temp.priority;
            q.push(temp);
        }
        printQ(q,a);
    }
}

int main()
{
    cin >> n;

    solve();
}