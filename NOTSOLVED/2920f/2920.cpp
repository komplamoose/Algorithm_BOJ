// 2920, 음계
// 1부터 8까지의 입력중에 받은 수열이 오름차순인지 내림차순인지, 둘 다 아닌지 출력하라
#include <iostream>

using namespace std;

int x[2];


int main()
{
    int check = 1;
    cin >> x[0];
    if (x[0]==1){
        for (int i=1 ; i<8;i++) {
            std::cin >> x[i];
            if (x[i]!=x[i-1]+1){
                check=0;
                break;
            }
        }
        if (check==1) cout << "ascending\n";
        else cout << "mixed\n";
    }else if (x[0]==8){
        for (int i=1 ; i<8;i++) {
            std::cin >> x[i];
            if (x[i]!=x[i-1]-1){
                check=0;
                break;
            }
        }
        if (check==1) cout << "descending\n";
        else cout << "mixed\n";
    }else{
        cout << "mixed\n";
    }
}