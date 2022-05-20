/*
가장 긴 증가하는 부분수열 => 이분탐색

L[i] = 길이 i인 증가하는 부분수열을 만들 수 있는 마지막 원소들 중, 가장 작은 값
L의 사이즈 == LIS의 길이

1. L이 비어있거나, L의 마지막 원소보다 비교하려는 원소값(here)이 더 클 경우
=> L의 맨 뒤에 here을 추가한다.
=> 지금까지 만들 수 있는 가장 큰 부분수열의 마지막 원소보다 here이 더 크니까,
=> here을 붙히면 L의 사이즈가 하나 더 늘어나고, LIS의 길이가 늘어나게 된다.

2. L이 비어있지 않거나, L의 마지막 원소보다 here이 작거나 같을 경우
=> L에서 here의 lower_bound를 찾아, 거기에 here을 넣는다.

왜 lower_bound 값을 업데이트할까? 
lower_bound보다 왼쪽에 위치한 원소들은, here보다 값이 더 작은데, 
거기에 넣으면 길이 i인 LIS의 "최소값"이라는 L의 조건을 무시하므로 넣으면 안된다.
Lower_bound의 오른쪽 값 또한, 오른쪽 값을 마지막으로 하는 LIS는,
그 이전 원소로 HERE 이상의 값을 가질 수 밖에 없게 된다. 그러므로 HERE을 넣을 수 없다
*/
#include <iostream>
#include <algorithm>

using namespace std;

int L[1000001], len, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        int here;
        cin >> here;
        auto pos = lower_bound(L+1, L+len+1, here);
        *pos=here;
        if (pos==L+len+1) { // here보다 더 크거나 같은 값이 List에 없다면
            len++;
        }
    }

    cout << len << endl;
}