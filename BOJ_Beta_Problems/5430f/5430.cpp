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
        deque<int> dq;
        cin >> func >> nums;
        // cin >> arrs;
        // arrs.erase(remove(arrs.begin(), arrs.end(), '['),arrs.end()); // 양 옆 대괄호 삭제
        // arrs.erase(remove(arrs.begin(), arrs.end(), ']'),arrs.end());

        // string delim = ",";
        // int pos = 0;
        // while((pos=arrs.find(delim))!=string::npos){
        //     dq.push_back(stoi(arrs.substr(0,pos)));
        //     arrs.erase(0,pos+delim.length());
        // } // 문자열 파싱 후 정수로 변환해서 벡터에 삽입 완료

    
        // if (nums!=0){
        //     dq.push_back(stoi(arrs.substr(0,pos)));
        // }
        char c;
        int t=nums;

        cin >> c;
        if (nums==0){
            cin >> c;
        }
        while(t--){
            int temp;
            cin >> temp;
            cin >> c;
            dq.push_back(temp);
        }


        int trg=0;
        int r=0;
        for (int j=0; j<func.length();j++){
            if (func[j]=='R'){
                if (r==0)
                    r=1;
                else
                    r=0;
            }else if (func[j]=='D'){
                if (dq.size()==0){
                    trg = 1;
                }else{
                    if (r==0){
                        nums--;
                        dq.pop_front();
                    }else{
                        nums--;
                        dq.pop_back();
                    }
                }
            }
        }
        if (trg==1)
            cout << "error\n";
        else{
            if (r==0){
                cout << "[";
                for (int j=0;j<nums;j++){
                    cout << dq[j];
                    if (j!=nums-1){
                        cout << ",";
                    }
                }
                cout << "]\n";
            }else{
                cout << "[";
                for (int j=nums-1;j>=0;j--){
                    cout << dq[j];
                    if (j!=0){
                        cout << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }
}

int main(void)
{
    int n;
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    cin >> n;

    solve(n);

    return 0;
}