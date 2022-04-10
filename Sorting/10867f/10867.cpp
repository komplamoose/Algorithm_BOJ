// 10867, silver 5, 중복 빼고 정렬하기
// https://www.acmicpc.net/problem/10867
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void solve(int n)
{  
    for (int i=0 ; i<n ; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());

    v.erase(unique(v.begin(), v.end()),v.end()); // unique로 중복된 값을 밀어버린 후, 중복된 값이 있는 벡터의 공간의 시작 주소를 반환한다. 그 공간부터 벡터의 끝까지 지우면 중복이 다 사라진다. 


    for (int i=0; i<v.size() ; i++){
        cout << v[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    solve(n);
}