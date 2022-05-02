// Z, 분할정복
// 배열을 4분할 한 뒤, 좌측 상단 -> 우측 상단 -> 좌측 하단 -> 우측 하단으로 순회하며
// 넘어갈때마다 그 분할된 배열의 좌상단에서 탐색시작한다. 
// 탐색은 2x2여야 한다.
#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;

unsigned long long int cnt=0;
int x, y;
int answer;
int where;

void solve(int n, int size,int startX, int startY)
{
    if (n<=1){
        if (startX==r && startY==c){
            cout << cnt << "\n";
            exit(0);
        }
        else cnt++;
        startY++;
        if (startX==r && startY==c){
            cout << cnt << "\n";
            exit(0);
        }
        else cnt++;
        startX++; startY--;
        if (startX==r && startY==c){
            cout<< cnt << "\n";
            exit(0);
        }
        else cnt++;
        startY++;
        if (startX==r && startY==c){
            cout << cnt << "\n";
            exit(0);
        }
        else cnt++;
    }else if (n>1) {
        solve(n-1,size/2,startX,startY);
        solve(n-1,size/2,startX,startY+size/2);
        solve(n-1,size/2,startX+size/2,startY);
        solve(n-1,size/2,startX+size/2, startY+size/2);
    }
}

int main()
{
    cin >> n >> r >> c;
    if (r<pow(2,n)/2 && c <pow(2,n)/2) {
        solve(n-1,pow(2,n)/2,0,0);
    }else if (r<pow(2,n)/2 && c >= pow(2,n)/2) {
        cnt+=pow(2,n-1)*pow(2,n-1);
        solve(n-1,pow(2,n)/2,0,pow(2,n)/2);
    }else if (r>=pow(2,n)/2 && c<pow(2,n)/2){
        cnt+=pow(2,n-1)*pow(2,n-1)*2;
        solve(n-1,pow(2,n)/2,pow(2,n)/2,0);
    }else{
        cnt+=pow(2,n-1)*pow(2,n-1)*3;
        solve(n-1,pow(2,n)/2,pow(2,n)/2,pow(2,n)/2);
    }
}