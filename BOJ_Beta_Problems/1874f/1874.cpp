// 1874, Silver 3, 스택 수열
// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> v;
stack<int> st;
vector<char> result;

void solve()
{
    int p=0, m=0;
    for (int i=0 ; i<n;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    for (int i=1, j=0;i<=n;i++){
        st.push(i);
        result.push_back('+');
        p++;
        while (v[j]==st.top()){
            st.pop();
            result.push_back('-');
            m++;
            j++;
            if (j==n||st.empty()){
                break;
            }
        }
    }

    if (p==m){
        for (auto loop : result){
            cout << loop << "\n";
        }
    }else{
        cout << "NO\n";
    }
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    cin >> n;

    solve();

    return 0;
}