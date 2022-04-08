// 9251, Gold 5, LCS
//https://www.acmicpc.net/problem/9251
/*
최장 공통 부분서열 문제 (LCS)
Longest Common Subsequence 

최장 공통 문자열 (Longest Common Subtring)과의 차이점
1. Substring은 연속된 부분 문자열
2. Subsequence는 연속되지 않은 부분 문자열이다. 

-
예시 : 1. ACAYKP 2. CAPCAK

우선 두 단어를 크기를 기준으로 2차원 배열을 생성한다. 
첫 번째 칸은 쓰지 않는다. (1,1부터 씀)
CAPCAK의 첫 번째 단어인 C를 이용해서 ACAYKP의 부분서열을 찾는다. 
ACAYKP의 첫번쨰인 A부터 끝인 ACAYKP까지 늘려가며, 첫 번째 단어인 C와 부분 서열인
것이 있는지 체크한다. 만약 존재한다면 그 비교하는 부분서열의 크기를 적는다.
위의 경우, C로 비교하였으므로 ACK~의 과정에서 C가 있다면 1을 넣어준다.
다음엔 CA를 기준으로 비교한다. 이떄 ACA와 비교를 한다면 테이블엔 2를 넣게 된다.
CAP의 경우, 끝인 ACAYKP의 비교에서 3을 넣을 것이다.

이때 어떻게 테이블에 숫자를 넣을까?

C와 AC를 비교하였을 때 최장 공통수열은 C로 길이 1이었다.
C와 ACA를 비교하면, 마지막 단어가 다르지만 왼쪽에서 값이 1이었으므로 그대로 1
을 유지한다.

CAP와 ACA를 비교하면 LCS 길이는 2이다. 왜 일까?
마지막 문자를 기준으로 다르면, 다른 문자열이다.
둘은 다른 문자열이지만, CA에서의 2를 그대로 물려받는다.
둘이 다른 문자열이면, 배열 테이블의 바로 위 혹은 왼쪽 중 큰 값을 넣는다.

마지막 문자를 비교하였을 때 같으면, 대각선 기준 왼쪽 위의 값에 +1을 해서 넣는다. 
-

단어 찾는 법

테이블을 생성한다. 

이후 끝에서 끝을 이용해서 거기부터 시작해서 탐색한다. 
테이블 끝 기준으로, 왼쪽이나 바로 위 테이블 값 중, 자신과 같은 값이 있는
곳을 따라간다. 같은 값이 없다면, 대각선 왼쪽 위로 따라간다. 
테이블 값이 0이 나타날 때 까지 따라간다. 

핵심 요약

문자열을 비교하여 같았을 때
현재 칸에 들어갈 값은 대각선 왼쪽 위의 값 + 1 이다.

문자열을 비교하여 달랐을 때
현재 칸에 들어갈 값은 왼쪽과 위쪽의 값 중 더 큰 값이 들어간다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DP[1001][1001]={0,};
string str_one, str_two;
vector<char> subSeq;

void solve();
void LCS();
// void findSub();

int main()
{
    cin >> str_one >> str_two;
    solve();
}



void solve()
{
    LCS();
//    findSub();
    cout << DP[str_two.length()][str_one.length()] << endl;
    // reverse(subSeq.begin(), subSeq.end()); // LCS 출력
    // for (auto loop : subSeq){
    //     cout << loop;
    // }
    // cout << endl;
}

// 가로 열 => 첫번째 스트링
// 세로 행 => 두번째 스트링

void LCS()
{
    for (int i=1; i<=str_two.length();i++){
        for (int j=1; j<=str_one.length();j++){
            if (str_two[i-1]!=str_one[j-1]){
                DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
            }else{
                DP[i][j] = DP[i-1][j-1] +1;
            }
        }
    }
}

// void findSub()
// {
//     int a=str_two.length(), b=str_one.length();
//     while(1)
//     {
//         int check = DP[a][b];
//         if (check==0) break;
//         if (check==DP[a][b-1]){
//             b=b-1;
//         }else if (check==DP[a-1][b]){
//             a=a-1;
//         }else{
//             subSeq.push_back(str_two[a-1]); // 실제 인덱스는 -1 해줘야함
//             a=a-1;
//             b=b-1;
//         }
//     };
// }