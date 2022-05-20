#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int answer, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        int index=0;

        for (int j=1; j<i; j++) {
            if (arr[i]>arr[j]) {
                index = max(index, dp[j]);
            }
        }
        dp[i]=index+1;
        answer = max(answer, dp[i]);
    }

    cout << answer;
}