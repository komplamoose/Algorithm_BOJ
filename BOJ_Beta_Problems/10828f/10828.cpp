#include <iostream>
#include <string>

using namespace std;

int stack[10000];
int top=-1;

void solve(int n)
{
    for (int i=0 ; i<n; i++){
        string order;
        cin >> order;

        if (order.compare("push")==0){ //If, order is "Push"
            int input;
            cin >> input;
            stack[++top]=input;
        }else if (order.compare("pop")==0){
            if (top<0)
                cout << -1 <<"\n";
            else
                cout << stack[top--] <<"\n";
        }else if (order.compare("top")==0){
            if (top<0)
                cout << -1 <<"\n";
            else
                cout << stack[top] << "\n";
        }else if (order.compare("size")==0){
            cout << top+1 << "\n";
        }else if (order.compare("empty")==0){
            if (top<0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
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
