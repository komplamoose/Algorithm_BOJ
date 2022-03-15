// 1026, Silver 4, 보물
// https://www.acmicpc.net/problem/1026
#include <iostream>
#include <vector>

vector<int> a;
vector<int> b;

void solve(int n)
{
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		b.push_back(input);
	}

	// a에서 가장 작은 값을 찾고, b에서 가장 큰 값을 찾아 매칭시킨다. 
}

int main()
{
	int n;
	cin >> n;

	solve(n);

	return 0;
}