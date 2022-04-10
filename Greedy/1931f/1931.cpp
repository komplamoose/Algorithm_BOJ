// 고민 1. 회의 시간이 짧으면 짧을수록 좋다.  
// 고민 2. 시간대는 겹치면 안된다. 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct meeting{
    int start;
    int end;
    int time;
};

vector<meeting> meets;
stack<meeting> stacks;



int compareBy(meeting a, meeting b){
    if (a.start == b.start)
        return a.time<b.time;
    return a.start <b.start;
}

int solve(int n)
{
    int s, e, t;
    for (int i = 0 ; i < n ; i++){
        meeting meet;
        cin >> s >> e;
        t = e - s;
        meet.start = s;
        meet.end = e;
        meet.time = t;
        meets.push_back(meet);
    }

    sort(meets.begin(),meets.end(),compareBy);

    for (int i = 0 ; i < n ; i++){
        if (stacks.empty())
            stacks.push(meets[i]);
        else{
            if (meets[i].start < stacks.top().end){
                int remain = stacks.top().end - meets[i].start;
                if (remain > meets[i].time){
                    stacks.pop();
                    stacks.push(meets[i]);
                }
            }else{
                stacks.push(meets[i]);
            }
        }
    }

    return stacks.size();
}

int main()
{
    int n;

    cin >> n;

    int solutions = solve(n);

    cout << solutions << endl;

    return 0;
}