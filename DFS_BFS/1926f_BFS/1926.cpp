// 1로 채워진 그림의 갯수와, 가장 넓은 길이의 그림 출력
#include <iostream>
#include <queue>

using namespace std;

int board[502][502] = {0,};

bool vis[502][502];

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 상 하 좌 우

int bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int,int> > Q;
    vis[x][y] = 1;
    Q.push({x,y});
    cnt++;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            cnt++;
            Q.push({nx,ny});
        }
    }

    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }
    int picture=0;
    int max=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            if (board[i][j]==1&&vis[i][j]==0) { // 여기 그림이 있고, 방문 안했다면
                int size = bfs(i,j);
                if (size>max) max=size;
                picture++;
            }
        }
    }

    cout << picture << "\n" << max << "\n";
}