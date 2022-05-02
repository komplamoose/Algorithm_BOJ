// 정석적인 BFS
#include <iostream>
#include <queue>

using namespace std;

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0},
{1,1,1,0,1,0,0,0,0,0},
{1,1,0,0,1,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0} };

bool vis[502][502];

int n =7, m = 10;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 상 하 좌 우

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        cout << "(" << cur.first << ", " << cur.second << ") -> "; 
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
}