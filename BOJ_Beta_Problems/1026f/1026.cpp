// 1026, Silver 4, ����
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

	// a���� ���� ���� ���� ã��, b���� ���� ū ���� ã�� ��Ī��Ų��. 
}

int main()
{
	int n;
	cin >> n;

	solve(n);

	return 0;
}