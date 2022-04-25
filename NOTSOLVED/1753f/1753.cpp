// 1753, 최단경로
// 다익스트라 알고리즘
// 우선순위 큐로 구현해야 됨 ㅋㅋ 
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001

using namespace std;

typedef pair<int, int> edge_t;
typedef vector<edge_t> set_of_edges;

int W[2001][2001] = {0, };
vector<int> touch, length;
set_of_edges F;
int n, m;
int start;

void printVector(vector<int> v)
{
    for (int i=2; i< v.size() ; i++) {
        cout << v[i];
        if (i < v.size() -1) cout << " ";
    }
    cout << "\n";
}

void dijkstra(int n, int W[][2001], set_of_edges& F)
{
    int vnear, min;

    F.clear(); // 초기 Y는 공집합
    for (int i = 1; i <= n; i++) {
        if (i==start) continue; // 원하는 시작지점 버텍스 값을 넣어준다
        touch[i] = start; // 원하는 시작지점 버텍스 값을 넣어준다
        length[i] = W[start][i]; // 원하는 시작지점 버텍스 값을 넣어준다
    } // TODO: 현재 네 번째 버텍스 기준으로 초기화.
    for (int cnt=0; cnt < n-1 ; cnt++) { // n-1번 반복. 한번은 이미 앞에서 했으니까.
        min = INF;
        for (int i=1; i<=n ;i++) { // 1부터 돌린다. 원하는 시작지점 버텍스가 나오면 점프한다.
            if (i==start) continue; // 원하는 시작지점 버텍스 값을 넣어준다
            if (0 <= length[i] && length[i] < min) {
                min = length[i]; // 가능한 최단경로 찾기
                vnear = i; // 최단경로로 도달할 수 있는 버텍스 찾기
            }
        }

        F.push_back(make_pair(vnear, touch[vnear])); // 찾은 간선 저장. 저장하는 간선은 총 경로가 아니고 vnear로 가는 최단 경로에서, vnear과 가장 가까운 버텍스와의 경로임.
        // 최단 경로로 도착할 수 있는 집합 Y 이외의 버텍스 찾아서, 그 버텍스와 그 최단경로의 마지막을 잇는 엣지 추가 

        for (int i = 1; i <= n; i++) {
            if (i==start) continue; // 원하는 시작지점 버텍스 값을 넣어준다
            if (length[i] > length[vnear] + W[vnear][i]) { // Prim과 다른 점. 이젠 vnear기준으로 최단경로와 단순 비교하는 것이 아니라, 
                length[i] = length[vnear] + W[vnear][i];   // vnear까지 도달하는데 걸리는 경로 + vnear에서 주변 버텍스로 도달할 수 있는 최단 경로를 합쳐서 비교함. 
                touch[i] = vnear;
            } // 만약에 vnear를 통해서 도달할 수 있는 경로가 직통으로 가는 경로보다 빠르다면, 도달가능 최단경로인 length를 바꿔줌. 최단경로가 바뀌었으니 그 최단경로 바로 직전 버텍스인 touch도 vnear로 바꿔줌. vnear를 통과하는 루트가 최단루트가 되었기 때문이다.
        }

        length[vnear] = -1; // vnear은 이제 집합에 포함되었으니 최종경로로 고려대상 X
    }
}

int navigate(int dest) // 최단 경로의 Pass 찾는 함수
{
    int pass=0;
    int f = dest; //TODO: 아래 수정할것 
    if (touch[f]!=start) {
        while (touch[f]!=start) { // touch[f] == 1 이라는 뜻은 그 버텍스까지 도달하는데 가장 가까운 경로의 바로 직전 버텍스가 1이라는 뜻임. 1과 직통으로 이어졌다는 뜻.
            pass += W[touch[f]][f];
            f = touch[f]; // 그 버텍스 기준으로 다시 가장 가까운 버텍스 찾기
        }
    }
    pass+=W[touch[f]][f];
    return pass;
}

void solve()
{
    touch.resize(n+1); length.resize(n+1);
    dijkstra(n, W, F);
    for (int i=1;i<=n;i++){
        if (i==start) cout << "0" << "\n";
        else{
            int weight = navigate(i);
            if (weight>=INF) {
                cout << "INF" << "\n";
            }else{
                cout << weight << "\n";
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> start;
    for (int i=0; i<m ; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        W[a][b] = weight; // Directed Graph이므로 한방향으로만 넣어줌. 
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) continue; // 자기자신이면 스킵 (0)
            if (W[i][j] == 0) W[i][j] = INF; // 직통으로 가는 길 없으면 INF 
        }
    }

    solve();
}