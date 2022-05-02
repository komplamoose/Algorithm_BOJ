// 토마토, 토마토가 다 익을때까지의 날짜를 계산하라.
#include <iostream>
#include <queue>

using namespace std;

int  board[1001][1001];
int dist[1001][1001];

queue<pair<int,int> > Q;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 상 하 좌 우

void bfs()
{
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny] > 0 || board[nx][ny] != 0) continue; // 이미 방문했거나(시작점은 0, 방문 안한 칸은 음수) 파란 칸이 아닐 경우
            dist[nx][ny] = dist[cur.first][cur.second]+1; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++) {
        for (int j=0 ; j<n ; j++) {
            dist[i][j] = -1;
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
            if (board[i][j]==1){
                Q.push({i,j});
                dist[i][j]=0;
            }else if (board[i][j]==-1){
                dist[i][j]=0;
            }
        }
    }

    bfs();

    int max = 0;
    bool check=false;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (dist[i][j]==-1) 
            {
                check = true; // 안익은 토마토가 존재한다면
            }
            if (dist[i][j]>max){
                max = dist[i][j];
            }
        }
    }

    if (check) {
        cout << "-1\n";
    }else{
        cout << max << "\n";
    }
}