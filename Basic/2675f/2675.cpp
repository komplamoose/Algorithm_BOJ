// 2675, 문자열 반복
// 테스트케이스 갯수를 입력받고, 숫자와 문자열을 입력받은 뒤, 문자열의 각 문자를 숫자만큼 프린트힌다. 3 ABC => AAABBBCCC
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int m;
        string s;
        cin >> m >> s;
        for (int j=0; j < s.size() ; j++){
            for (int k=0; k<m; k++) {
                cout << s[j];
            }
        }
        cout << "\n";
    }
}
