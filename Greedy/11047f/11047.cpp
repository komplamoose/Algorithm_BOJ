// 동전 0, 배수관계를 가진 동전들을 이용해 특정 값을 이루는 최소 동전 갯수를 출력하라
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> PQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int sum=0;
    int cnt=0;

    for (int i=0, input; i<n; i++){
        cin >> input;
        PQ.push(input);
    }

    while(sum!=k){
        int capacity = k - sum;
        if (PQ.top() > capacity){
            PQ.pop();
            continue;
        }else{
            sum+=PQ.top();
            cnt++;
        }
    }

    cout << cnt << "\n";
}