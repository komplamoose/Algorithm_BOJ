// 11720, 숫자의 합
// 문자열 쭉 입력받아서 덧셈처럼 계산하라
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    int sum=0;
    for (int i=0; i<n;i++) {
        sum+=s[i]-48;
    }
    cout << sum << "\n";
}