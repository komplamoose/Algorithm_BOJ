// 1003, Silver 3, 피보나치 함수
// https://www.acmicpc.net/problem/1003
#include <iostream>
#include <cstring>

long long int m0[100];
long long int m1[100];
int zero, one;

int fibonacci(int n) {
    if (n == 0) {
        zero++;
        return 0;
    } else if (n == 1) {
        one++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    memset(m0,-1,sizeof(m0));
    memset(m1,-1,sizeof(m1));
    int n;
    std::cin >> n;
    m0[0]=1;
    m1[0]=0;
    m0[1]=0;
    m1[1]=1;
    
    for (int i=0; i<n; i++){
        int input;
        std::cin >> input;
        
        if (m0[input]==-1&&m1[input]==-1){
            for (int j=2; j<=input; j++){
                m0[j]=m0[j-1]+m0[j-2];
                m1[j]=m1[j-1]+m1[j-2];
            }
            std::cout << m0[input] << " " << m1[input] << "\n";
        }else{
            std::cout << m0[input] << " " << m1[input] << "\n";
        }
    }
}