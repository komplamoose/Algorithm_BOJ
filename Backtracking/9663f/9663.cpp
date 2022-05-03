/*
9663, N-Queen

1. 퀸은 한 행에 하나만 있을 수 있다.
2. 일단 퀸을 한 칸에 놓는다.
3. 가능한 아래 행 칸에 퀸을 놔본다. 같은 열, 대각선에 퀸이 존재하면 못놓는다.
4. 불가능하다면 다시 돌아와서 다음 칸에 퀸을 놔둔다.
5. 마지막 행에 퀸을 놓으면, n-queen을 만족한 것이므로 체크해주고 그 전으로 돌아간다. 
*/
#include <iostream>

using namespace std;

int n;
int cnt=0;
bool isused1[16]; // 열에 대응, (x,y)칸에 퀸을 놨으면 isused1[y]에 true;
bool isused2[32]; // 우상향하는 대각선에 대응 (x,y)칸에 퀸을 놨으면 isused2[x+y]칸에 true;
bool isused3[32]; // 우하향하는 대각선에 대응, (x,y)칸에 퀸을 놨다면 isused2[x-y+n-1]에 true, n-1 더해주는 이유는 음수 방지용



void solve(int cur)
{
    if (cur==n) {
        cnt++;
        return;
    }else {
        for (int i=0; i<n; i++) {
            if (isused1[i]==false&&isused2[cur+i]==false&&isused3[cur-i+n-1]==false) {
                isused1[i]=true; isused2[cur+i]=true; isused3[cur-i+n-1]=true;
                solve(cur+1);
                isused1[i]=false; isused2[cur+i]=false; isused3[cur-i+n-1]=false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    solve(0);

    cout << cnt;
}