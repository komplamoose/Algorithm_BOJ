// 10250, ACM 호텔
#include <iostream>

using namespace std; 

int w, h, n, x;

int main()
{
    cin >> n;

    for (int i=0; i < n ; i++) {
        cin >> w >> h >> x;
        int floor = x;
        int cnt = 1;
        while(floor > w) {
            floor=floor-w;
            cnt++;
        }
        if (cnt<10) {
            cout << floor << 0 << cnt << "\n";
        }else {
            cout << floor << cnt << "\n";
        }
    }
}