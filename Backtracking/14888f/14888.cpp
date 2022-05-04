// 연산자 끼워넣기 
// 연산자 끼워넣기로 나올 수 있는 최대, 최소값을 출력하라
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int ope[4]; // + . - , * , / 순서

int n;

long long int MAX=-10000000001;
long long int MIN=10000000001;

void solve(int k, long long int sum)
{
    if (k==n-1) {
        if (sum>MAX) MAX=sum;
        if (sum<MIN) MIN=sum;
        return;
    } else{
        for (int i=0; i<4; i++){
            if (ope[i]<=0) continue;
            switch(i){
                case 0: // +
                    ope[i]--;
                    solve(k+1, sum+a[k+1]);
                    ope[i]++;
                    break;
                case 1: // -
                    ope[i]--;
                    solve(k+1, sum-a[k+1]);
                    ope[i]++;
                    break;
                case 2: // *
                    ope[i]--;
                    solve(k+1, sum*a[k+1]);
                    ope[i]++;
                    break;
                case 3:
                    ope[i]--;
                    solve(k+1, sum/a[k+1]);
                    ope[i]++;
                    break;
            }
        }
    }
}


int main()
{
    cin >> n;

    for (int i=0, input; i<n; i++) {
        cin >> input;
        a.push_back(input);
    }

    for (int i=0 ; i<4; i++) {
        cin >> ope[i];
    }

    solve(0, a[0]);

    cout << MAX << "\n" << MIN;
}