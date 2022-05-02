// 미로찾기, 미로로 가는 경로까지의 거리를 구하라!
#include <iostream>
#include <queue>

using namespace std;

string board[502];
int dist[502][502];

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 상 하 좌 우

void bfs()
{
    queue<pair<int,int> > Q;
    dist[0][0] = 0; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny] >=0 || board[nx][ny] != '1') continue; // 이미 방문했거나(시작점은 0, 방문 안한 칸은 음수) 파란 칸이 아닐 경우
            dist[nx][ny] = dist[cur.first][cur.second]+1; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1] + 1 << "\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> board[i];
    }
    for (int i=0 ; i<n; i++) {
        fill(dist[i], dist[i]+m, -1);
    }

    bfs();
}