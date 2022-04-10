// 10808, Bronze 2, 알파벳 갯수
// 단어 입력 받은 뒤, 분석해서 각각 알파벳 순서에 맞는 배열에 ++한다.
// 1) 사전에 알파벳을 딕셔너리화해서 저장해둔다. 
// 2) 그냥 소문자 알파벳 기준 -97(a) 해주면 배열 인덱스로 변환 가능
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> dict;
int arr[26]={0,};

void solve(string input)
{
    for (int i=0; i<input.size(); i++)
    {
        arr[dict[input[i]]]++;
    }

    for (int i=0; i<26; i++){
        cout<< arr[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int asc=97, i=0; asc<123; asc++, i++){
        dict[asc]=i;
    }

    string input;
    cin >> input;
    solve(input);
    return 0;
}