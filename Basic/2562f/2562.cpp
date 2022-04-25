// 2562, 최댓값
// 숫자 9개를 입력받아 최댓값을 찾고, 그 위치를 출력하라
#include <iostream>

using namespace std;

int n[10];

int main()
{
    for (int i=1; i<10; i++) {
        cin >> n[i];
    }
    int max = n[1];
    int idx = 1;
    for (int i=2; i<10; i++) {
        if (max<n[i]) {
            max = n[i];
            idx = i;
        }
    }

    cout << max << "\n" << idx << "\n";
}