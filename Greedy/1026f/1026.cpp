// 1026, Silver 4, 보물
// https://www.acmicpc.net/problem/1026
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;

void solve(int n)
{
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	
	sort(a.begin(),a.end());

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		b.push_back(input);
	}

	sort(b.begin(),b.end());
	
	int sum=0;
	for (int i=0 ; i<n;i++){
		sum += a[i]*b[n-i-1];
	}

	cout << sum << "\n";
}

int main()
{
	int n;
	cin >> n;

	solve(n);

	return 0;
}