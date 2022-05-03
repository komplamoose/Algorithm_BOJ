// 1182, Silver 2, 부분수열의 합
// https://www.acmicpc.net/problem/1182
// 매 순간 더할지, 안더할지 이진트리 형태로 구성가능
#include <iostream>
#include <vector>

using namespace std;

int n, s;

int cnt=0;

int nums[30];

void solve(int sum, int cur)
{
    if (cur==n){
        if (sum==s) cnt++;
        return;
    }else{
        solve(sum, cur+1); // 그대로 숫자 넣지말고 유지하는 경우
        solve(sum+nums[cur], cur+1); // 다음 숫자 넣어보는 경우
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for (int i=0; i<n; i++){
        cin >> nums[i];
    }

    solve(0, 0);

    if (s==0) cnt--;
    cout << cnt << "\n";
}