// 8958, OX 퀴즈
#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i=0 ; i < n ; i++) {
        int score=0;
        int sum=0;
        string s;
        cin >> s;
        for (int j=0; j < s.length(); j++) {
            if (s[j]=='X') score=0;
            else score++;
            sum+=score;
        }
        cout << sum << "\n";
        sum=0;
        score=0;
    }
}