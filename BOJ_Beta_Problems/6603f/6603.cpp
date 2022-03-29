// 6603, Silver 2, Lotto
// https://www.acmicpc.net/problem/6603
// TODO: 백트래킹 좀 더 공부하고 다시 공부하자. 
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int arr[49]={0,};
int check[49]={0,};

void solve(int k)
{
	if (k==6)
	{
		for (int i=0; i<k ; i++)
		{
			cout << arr[i] <<" ";
		}
		cout << "\n";
	}else{
		for (int i=0; i<v.size();i++)
		{
			if (check[i]==0){
				if (v[i]<arr[k-1]) continue;
				arr[k]=v[i];
				check[i]=1;
				solve(k+1);
				check[i]=0;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	while (n!=0)
	{
		for (int i=0 ; i<n ; i++)
		{
			int input;
			cin >> input;
			v.push_back(input);
		}
		solve(0);
		cout << "\n";
		v.clear();
		memset(arr,0,49);
		memset(check,0,49);
		cin >> n;
	}
	
    return 0;
}
