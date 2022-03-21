// 9012, Silver 4, 괄호
// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
stack<char> st;

void solve()
{
    for (int i=0;i<n;i++)
    {
        int left=0, right=0;
        int trigger=0;
        string str;
        cin >> str;
        if (str[0]==str[str.length()-1]){
            cout << "NO\n";
            continue;
        }
        for (int j=0;j<str.length();j++){
            if (str[j]=='(') left++;
            if (str[j]==')') right++;
        }
        if (left!=right){
            cout << "NO\n";
            continue;
        }
        for (int j=0;j<str.length();j++){
            if (str[j]=='(') st.push(str[j]);
            else{
                if (st.empty()){
                    trigger=1;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        if (trigger==1||!st.empty()){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}

int main()
{
    cin >> n;

    solve();

    return 0;
}