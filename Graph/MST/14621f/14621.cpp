// 14621, 나만 안되는 연애
// 반드시 M-W 혹은 W-M 대학으로 가는 경로만 포함한다.
// 크루스칼로 구현
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge_t{
    int u, v, w;
};

struct edge_compare {
    bool operator() (edge_t e1, edge_t e2) {
        if (e1.w > e2.w) return true;
        else return false;
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;
// edge_t 자료형을 담는 우선순위 큐 정의.
// vector는 내부 컨테이너 형태
// 구조체로 지정해주어야 w가 작은 순서대로 정렬함. 안해주면 자동으로 큰거 기준으로 정렬
// 구조체 내부에 있는 operator 기준으로 정렬해줌. 
PriorityQueue PQ;
set_of_edges E;
vector<int> dset;
/*
dset -> disjoint set (서로소 집합 자료구조, Union - Find)
지원 연산
1) 초기화 : n개의 원소가 각각의 집합에 포함되어 있도록 초기화
2) Union : 원소 a, b가 주어질 때, 이들이 속한 집합을 하나로 합쳐버림
3) Find : 어떤 원소 a가 주어져있을 때, 이 원소가 속해있는 집합을 반환
*/

int n, m;
char univ[1001];

void dset_init(int n) // 초기화 함수
{
    dset.resize(n+1);
    for (int i = 1; i <= n; i++) {
        dset[i] = i;
    }
}

int dset_find1(int i) { // 재귀 안쓰고 구현, 연결관계 최적으로 안바꾸고 할때마다 계속 파고들어서 탐색함
    while (dset[i] != i) {
        i = dset[i];
    }
    return i;
}

void dset_merge1(int p, int q) // 원래 노드 갯수가 적은 애가 큰 애를 가리키는게 효율적인데, 이건 그거 고려 안함.
{
    dset[p] = q;
}

// 최적화 한 유니온-파인드
int good_Find(int x){
    if (x==dset[x]) return x;
    else {
        int y = good_Find(dset[x]);
        dset[x] = y;
        return y;
    }
}

void good_Union (int x, int y){
    y = good_Find(y);
    x = good_Find(x);
    if (x!=y){
        dset[y] = x;
    }
}

int kruskal(int n, int m, set_of_edges& E, set_of_edges& F) {
    int p, q;
    int x=0;
    unsigned long long int sum = 0;
    int y=0;
    edge_t e;
    int size = PQ.size();

    for (auto loop : E) {
        PQ.push(loop);
    }

    F.clear(); // 집합은 공집합부터 시작.
    dset_init(n);
    while (x < size) { // 엣지가 n-1개 골라지면 탈출. n-2일때 진입해서 n-1번째 엣지 추가함.
        e = PQ.top(); PQ.pop(); // 가중치 가장 낮은 간선 선택
        p = good_Find(e.u); // 버텍스 u가 어디 집합에 존재하는지 체크
        q = good_Find(e.v); // 버텍스 v가 어디 집합에 존재하는지 체크
        if (p != q) { // 만약 p == q라면, 둘은 이미 같은 집합 내에 존재한다는 것. -> 싸이클 생김.
            good_Union(p, q); // 두 집합 합친다.
            sum += e.w;
            if (++y==n-1){
                cout << sum << "\n";
                return 1;
            }
        }else{
            x++;
        }
    }

    cout << "-1" << "\n";
    return 0;
}

void solve()
{
    set_of_edges F;
    kruskal(n, m, E, F);
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i <= n; i++) { // 1은 안씀
        char sex;
        cin >> sex;
        univ[i]=sex;
    }

    for (int i=0; i<m; i++) {
        edge_t e;
        cin >> e.u >> e.v >> e.w;
        if (univ[e.u]==univ[e.v]) continue;
        PQ.push(e);
    }

    solve();
}