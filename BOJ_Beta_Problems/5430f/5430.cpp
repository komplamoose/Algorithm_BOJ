// 5430, Gold 5, AC
// https://www.acmicpc.net/problem/5430
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n)
{
    for (int i=0; i<n; i++){
        int nums;
        string func, arrs;
        cin >> func >> nums >> arrs;
        arrs.erase(remove(arrs.begin(), arrs.end(), '['),arrs.end()); // 양 옆 대괄호 삭제
        arrs.erase(remove(arrs.begin(), arrs.end(), ']'),arrs.end());

        string delim = ",";
        deque<int> dq;

        int pos = 0;
        while((pos=arrs.find(delim))!=string::npos){
            dq.push_back(stoi(arrs.substr(0,pos)));
            arrs.erase(0,pos+delim.length());
        } // 문자열 파싱 후 정수로 변환해서 deque에 삽입 완료

        int trg=0;
        for (int j=0; j<func.length();j++){
            if (func[j]=='R'){
                reverse(dq.begin(),dq.end());
            }else if (func[j]=='D'){
                if (dq.size()==0){
                    trg = 1;
                }else{
                    dq.pop_front();
                }
            }
        }
        if (trg==1)
            cout << "error\n";
        else{
            cout << "[";
            for (int j=0;j<nums;j++){
                cout << dq.front();
                if (j!=nums-1){
                    cout << ",";
                }
                dq.pop_front();
            }
            cout << "]\n";
        }
    }
}

int main(void)
{
    int n;

    cin >> n;

    return 0;
}