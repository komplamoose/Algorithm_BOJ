// 11279, 최대 힙
// 0 이면 가장 큰 값 출력, 비어있으면 0 출력
// 자연수면 힙에 입력
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// struct cmp {
//     bool COMPARE(int a, int b) {
//         return a > b;
//     }
// };

priority_queue<int, vector<int>> PQ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int command;
        cin >> command;
        if (command==0) {
            if (PQ.empty()) {
                cout << "0\n";
            }else {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }else{
            PQ.push(command);
        }
    }
}