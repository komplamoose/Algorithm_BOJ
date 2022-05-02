// 절댓값 힙
// 절댓값이 작은 값을 뽑는다.
// 절댓값이 같으면 더 작은 값을 뽑는다.
#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        if (abs(a) > abs(b))
            return true;
        else if (abs(a)==abs(b)){
            if (a>b) return true;
            else return false;
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int, vector<int>, compare> PQ;

    int tc;
    cin >> tc;

    for (int i=0; i<tc; i++) {
        int input;
        cin >> input;

        if (input==0){
            if (PQ.empty()){
                cout << 0 << "\n";
            }else{
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }else{
            PQ.push(input);
        }
    }
}