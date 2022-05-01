/*
// 아파트 임대, 5616
밀러-라빈 소수판별법
소수는 페르마의 소정리를 만족한다.
페르마의 소정리)
소수 p가 있고, p의 배수가 아닌 수 a가 존재할 때, 아래 수식을 만족한다.
a^(p-1)%p=1
숫자 p에 대해서 위 수식을 만족하지 않으면, 그 수는 소수가 아니라 합성수다.
a는 ll의 경우 2, 7, 61만 검사하면 된다.

페르마의 보조정리)
2^(p-1)%p 값이 p-1이 아닌 경우, p-1이 짝수인데 temp가 1이거나 temp가 p-1이면 소수다. 둘 다 아니면 합성수다.
p-1이 홀수면 k를 2분의 1해서 한번 더 검사한다. 
-
빠른 거듭제곱 연산
x^y 구조에서 y가 홀수라면, x를 밖으로 빼버린다. 이후 y는 이등분하고, x는 제곱해준다. y가 0이 아닐때까지 반복한다.

아파트 임대 계산)
아파트의 크기는 A=2xy+x+y 이다. (A는 아파트의 총 면적)
이때, A에 2를 곱하고 1을 더해주면, 2A+1 = 4xy+2x+2y+1, 즉 (2x+1)(2y+1) 구조가 성립한다.
아파트 면적이 존재할 수 없는 경우는, 2A+1이 합성수인지 아닌지 체크하면 되므로, 2A+1이 소수이면 존재할 수 없다.

테스트케이스는 100000개 정도지만, 면적은 2의 32승-1의 크기로 매우 크다. 밀러-라빈 판별법을 사용한다.
*/
#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long int ull;
ull checker[3] = {2, 7, 61};

ull fast_pow(ull x, ull y, ull mod){ // 어짜피 최종 p mod 값을 구할거니까. 계속 mod 해줘도 된다.
    ull temp = 1;
    while(y) {
        if (y%2) { // y is odd
            temp = (x * temp)%mod;
        }
        y = y/2;
        x = (x*x)%mod;
    }

    return temp;
}

bool miller_Rabin(ull p, ull check){
    if (check%p==0) return true; // 체크하려는 수가 check와 같을 경우
    ull k = p-1;
    while(1){
        ull temp = fast_pow(check,k,p);
        if (temp==p-1) return true;
        if (k%2==1) return (temp==1 || temp == p-1);
        k /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    int counter=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        ull size;
        cin >> size;
        for (int j=0; j<3; j++) {
            if (!miller_Rabin(2*size+1,checker[j])){
                counter++;
                break;
            }
        }
    }

    cout << n - counter << "\n";
}