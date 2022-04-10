// 1652, Bronze 1, 누울 자리를 찾아라
// https://www.acmicpc.net/problem/1652
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char place[101][101];

void solve(int n)
{
    for (int i=0 ; i<n ; i++){
        for (int j=0; j<n; j++){
            char input;
            cin >> input;
            place[i][j]=input;
        }
    }
    // 가로 체크
    int horizon=0;
    for (int i=0 ; i<n ; i++){
        int cnt=0;
        for (int j=0; j<n; j++){
            if (place[i][j]=='X'){
                if (cnt>=2){
                    horizon++;
                    cnt=0;
                }else{
                    cnt=0;
                }
            }else{
                cnt++;
            }
        }
        if (cnt>=2){
            horizon++;
            cnt=0;
        }
    }
    // 세로 체크
    int vertical=0;
    for (int i=0 ; i<n ; i++){
        int cnt=0;
        for (int j=0; j<n; j++){
            if (place[j][i]=='X'){
                if (cnt>=2){
                    vertical++;
                    cnt=0;
                }else{
                    cnt=0;
                }
            }else{
                cnt++;
            }
        }
        if (cnt>=2){
            vertical++;
            cnt=0;
        }
    }

    cout << horizon << " " << vertical << endl;
    // for (int i=0; i<n ; i++){
    //     for (int j=0; j<n ; j++){
    //         cout << place[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int main()
{
    int n;
    cin >> n;

    solve(n);
}