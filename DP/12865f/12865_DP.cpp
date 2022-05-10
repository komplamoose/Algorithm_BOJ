/*
배낭 문제 => DP로 해결

1. 테이블 설정
d[i][k]
i => 배낭에 넣을 수 있는 물건의 번호들 (1~i번까지의 물건중에 담는다) (물건 갯수)
j => 가방의 가능한 무게 (가방 무게)
d[i][k]=> 1번 물건부터 i번 물건까지 담을 수 있는 상황에서, 가방 용량이 K일 경우
담을 수 있는 최대의 이익

d[i][j]=max(물건i의 이윤 + d[i-1][j-w[i]],d[i][j]);
=> 물건 i를 담았을 때의 최대 이윤과, 안담았을때의 최대 이윤 중 큰 값을 고르면 된다.
=> 만약 가방 용량보다 i 무게가 더 크면 저번에 같은 무게에서의 i안담고 최대 이윤을 그대로 적으면 된다.
=> 물건 i를 담은 이윤 + i 제외한 상황에서의 최대 용량에서 i 용량 제외했을때 담을 수 있었던 최대 밸류
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> d;
vector<int> v;
vector<int> w;

int n, k;

void solve()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (w[i]<=j)
                d[i][j]=max(v[i] + d[i-1][j-w[i]],d[i-1][j]);
            else
                d[i][j]=d[i-1][j];
        }
    }
}

int main()
{
    cin >> n >> k;
    v.push_back(-1); // 0번째 칸 안씀
    w.push_back(-1); // 0번째 칸 안씀
    d.assign(n+1,vector<int>(k+1,0));
    for (int i=0; i<n; i++) {
        int weight, value;
        cin >> weight >> value;
        v.push_back(value);
        w.push_back(weight);
    }


    solve();

    cout << d[n][k] << "\n";
}