/*
시뮬레이션, 15683

CCTV 1 : 한쪽 방향으로만 감시 가능 
CCTV 2 : 양방향 감시 가능
CCTV 3 : 직각방향 ('ㄴ') 으로 감시 가능
CCTV 4 : 좌, 우, 상단으로 감시 가능
CCTV 5 : 4방향 모두 감시 가능

CCTV는 CCTV를 뛰어넘을 수 있다.

각 CCTV를 틀어서 배열에서 0의 값이 최소가 되는 경우를 구하라
*/
#include <iostream>
#include <vector>

using namespace std;

int rotType[5]={4, 2, 4, 4, 1};

// 동서남북


int minValue=10000001;

struct camera{
    int type;
    int row;
    int col;
};

int map[8][8];
int X, Y;
vector<camera> v;

void copy(int cp[][8], int og[][8])
{
    for (int i=0; i<X; i++) {
        for (int j=0; j<Y; j++) {
            cp[i][j]=og[i][j];
        }
    }
}

void watch(int dir, camera cam) {
    int d=dir%4;

    if (d==0) { // 동
        for (int i=cam.col+1; i<Y; i++) {
            if (map[cam.row][i]==6) break;
            map[cam.row][i]=-1;
        }
    } else if (d==1) { // 북 
        for (int i=cam.row-1; i>=0; i--) {
            if (map[i][cam.col]==6) break;
            map[i][cam.col]=-1;
        }
    } else if (d==2) { // 서
        for (int i=cam.col-1; i>=0; i--) {
            if (map[cam.row][i]==6) break;
            map[cam.row][i]=-1;
        }
    } else { // 남
        for (int i=cam.row+1; i<X; i++) {
            if (map[i][cam.col]==6) break;
            map[i][cam.col]=-1;
        }
    }
}

void solve(int idx)
{
    if (idx==v.size()) {
        int cnt=0;
        for (int i=0; i<X; i++) {
            for (int j=0; j<Y; j++) {
                if (map[i][j]==0) cnt++;
            }
        }
        minValue=min(minValue, cnt);
        return;
    }
    camera c = v[idx];
    int temp[8][8];

    for (int i=0; i<rotType[c.type]; i++) {
        copy(temp, map);
        switch(c.type) {
            case 0:
                watch(i, c);
                break;
            case 1:
                watch(i, c);
                watch(i+2, c);
                break;
            case 2:
                watch(i, c);
                watch(i+1, c);
                break;
            case 3:
                watch(i,c);
                watch(i+1, c);
                watch(i+2,c);
                break;
            case 4:
                watch(i,c);
                watch(i+1, c);
                watch(i+2,c);
                watch(i+3, c);
        }
        solve(idx+1);

        copy(map, temp);
    }
}

int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cin >> X >> Y;
    
    for (int i=0; i<X; i++) {
        for (int j=0; j<Y; j++) {
            cin >> map[i][j];
            if (map[i][j]!=0&&map[i][j]!=6){
                camera temp;
                temp.type=map[i][j]-1;
                temp.row=i;
                temp.col=j;
                v.push_back(temp);
            }
        }
    }

    solve(0);

    cout << minValue << endl;
}