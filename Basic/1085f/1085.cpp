// 1085, 직사각형에서 탈출
#include <iostream>

using namespace std;

int main()
{
    float x, y, w, h;
    int xdist, ydist;

    cin >> x >> y >> w >> h;

    if (x >= w/2 && y >= h/2) {
        xdist = w-x;
        ydist = h-y;
        cout << min(xdist, ydist) << "\n";
    }else if (x >= w/2 && y <= h/2) {
        xdist = w-x;
        ydist = y;
        cout << min(xdist, ydist) << "\n";
    }else if (x <= w/2 && y >= h/2) {
        xdist = x;
        ydist = h-y;
        cout << min(xdist, ydist) << "\n";
    }else {
        xdist = x;
        ydist = y;
        cout << min(xdist, ydist) << "\n";
    }
}