#include <iostream>
#include <queue>

using namespace std;

int arr[1000];
queue<int> maxQ;

void solve(int n)
{
    queue<int> s;
    queue<int> test;
    for (int i = 0 ; i<n ;i++){
        cin >> arr[i];
    }

    for (int i=0 ; i<n;i++){
        s=queue<int>();
        for (int j = i ; j < n ; j++){
            if (s.empty()){
                s.push(arr[j]);
            }
            else{
                if (s.back()<arr[j])
                    s.push(arr[j]);
                else{
                    test = queue<int>(s);
                    // while(test.back()>arr[j]){
                    //     test.pop();
                    // }
                    // for (int k = j ; k < n ; k++){
                    //     if (test.empty())
                    //         test.push(arr[k]);
                    //     else{
                    //         if (test.back() < arr[k])
                    //             test.push(arr[k]);
                    //     }
                    // }
                }
            }
        }
        // if (s.size()<test.size()){
        //     swap(s,test);
        //     test = queue<int>();
        // }
        if (maxQ.size()<s.size()){
            swap(maxQ,s);
        }
    }

    cout << maxQ.size() << "\n";
    while(!maxQ.empty()){
        cout << maxQ.front() << " ";
        maxQ.pop();
    }
}

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    solve(n);
}