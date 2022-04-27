// 11050, 
#include <iostream>
#include <vector>

using namespace std;

int v[200000];
int a[2];
int m;

void bin(int n, int k)
{
    for (int i=0 ; i<=n ; i++){
        for (int j=0; j <=min(i,k); j++){
            if (j==0 || j == i){
                v[j]=1;
                a[0]=v[j];
            }
            else{
                a[1]=a[0];
                a[0]=v[j];
                v[j]= a[1]+v[j];
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    bin(n,k);


    cout << v[k] << "\n";
    return 0;
}