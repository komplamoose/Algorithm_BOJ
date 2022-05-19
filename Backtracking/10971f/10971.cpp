#include <iostream>
#include <vector>
#include <queue>
#define INF 10000001

using namespace std;

int W[100][100];

int vert, edge;

typedef struct node* node_ptr;
typedef struct node {
    int level;
    vector<int> path;
    int bound;
    node() { // 생성자, new 호출시 자동으로 호출된다.
        level=0;
        path.clear();
        bound=INF;
    }
}nodetype;

struct compare{
    bool operator()(node_ptr a, node_ptr b) {
        return a->bound > b->bound; // 오름차순
    }
};

int length(vector<int> path) {
    int len=0;
    for (auto it=path.begin(); it!=path.end(); it++) {
        if (it!=path.end()-1) { // end의 경우 더이상 갈 곳이 없기 때문에, "경로"는 없음
            len += W[*it][*(it+1)];
        }
    }
    return len;
}

bool hasOutGoing(int v, vector<int> path) { // 1부터 end-1까지에 위치한 버텍스들은, 최소한 다음 버텍스에게 OUT 하는 엣지를 가지고 있다. 여기서 누군가를 밟으러간다.
    for (auto it = path.begin(); it!=path.end()-1; it++) {
        if (*it==v) return true; 
    }
    return false;
}

bool hasInComing(int v, vector<int> path) { // 2부터 end까지에 위치한 버텍스들은, 누군가에 의해 밟혀진다. 
    for (auto it = path.begin()+1; it != path.end(); it++) {
        if (*it==v) return true;
    }
    
    return false;
}

int bound(node_ptr temp) {
    int lower = length(temp->path); // 이 노드의 현재까지 걸어온 길의 가중치 합
    for (int i=1; i<=vert; i++) { // 모든 버텍스 검사 
        if (hasOutGoing(i, temp->path)) continue; // 만약 이 버텍스가 out-going에 속한다면? => 이미 밟음
        int min = INF;
        for (int j=1; j<=vert; j++) { // 이 i버텍스에서 갈 수 있는 버텍스 검사
            if (i==j) continue; // 자기 자신 패스
            if (j==1 && i == temp->path[temp->path.size()-1]) continue; // 시작점(1번버텍스)이면서, 출발정점이 내가 걸어왔던 path의 마지막 정점이면 패스
            if (hasInComing(j, temp->path)) continue; // 밟으려고 하는 j가 이미 밟혔으면 패스

            if (min > W[i][j]) min = W[i][j];
        }
        lower+=min;
    }

    return lower;
}

node_ptr create_node() {
    node_ptr temp = new struct node;
    return temp;
}

bool isIn(int i, vector<int> path) {
    for (auto loop : path) { // 끝까지 검사해서 찾으면 트루
        if (loop==i) return true;
    }

    return false;
}

int remaining_vertex(vector<int> path) {
    int sum=0;
    for (auto loop : path) {
        sum+=loop;
    }
    
    return ((vert*(vert+1))/2)-sum; // 어짜피 모든 버텍스 밟아야하니 인덱스는 1부터 n까지 존재, 
    //마지막 하나 안밟은 애는 1부터 n까지의 합에서 내가 여태까지 밟은 버텍스 인덱스합을 빼면 
    //안밟은 버텍스의 인덱스가 나온다.
}

void travel2(vector<int>& opttour, int& minLength) {
    priority_queue<node_ptr, vector<node_ptr>, compare> PQ;
    node_ptr u, v;
    opttour.resize(vert+1); // Copy할라면 capacity 늘어나야함.
    v=create_node();
    minLength=INF;
    v->level=0; v->path.push_back(1); v->bound = bound(v); // 첫번쨰 출발점 루트노드 설정
    PQ.push(v);
    while(!PQ.empty()) {
        v=PQ.top(); PQ.pop();
        if (v->bound < minLength) {
            for (int i=2; i <= vert; i++) {
                if (isIn(i,v->path)) continue; // 만약 이 버텍스에서 내가 가려고 하는 다음 버텍스가, 이미 path에 존재한다면, 한번 밟은 애임. 
                u=create_node();
                u->level=v->level+1; // 다음 레벨
                u->path=v->path; // 패스 이어받음
                u->path.push_back(i); // 내가 밟으려고 하는 버텍스를 패스에 추가함. 
                if (u->level == vert-2) { // 만약 n-2 단계까지 왔다면, 남은거 뭔지 찾아서 그냥 계산하면 됨.
                    u->path.push_back(remaining_vertex(u->path));
                    u->path.push_back(1);
                    if (length(u->path) < minLength) {
                        minLength = length(u->path);
                        copy(u->path.begin(), u->path.end(), opttour.begin());
                    }
                }
                else {
                    u->bound = bound(u); // 이 노드의 bound 구함
                    cout << u->level << " " << u->bound << endl;
                    if (u->bound < minLength) {
                        PQ.push(u); // 안유망하면 (바운드가 minlength보다 같거나 크면, 더이상 탐색 필요 없음) 안넣음
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> vert;



    for (int i=1; i<=vert; i++){
        for (int j=1; j<=vert; j++) {
            int temp;
            cin >> temp;
            W[i][j]=temp;
        }
    }

    for (int i=1; i<=vert; i++){
        for (int j=1; j<=vert; j++) {
            if (i==j) continue;
            if (W[i][j]=0) W[i][j]=INF;
        }
    }

    vector<int> opttour;
    int minLength=INF;

    travel2(opttour, minLength);

    cout << minLength << endl;
}