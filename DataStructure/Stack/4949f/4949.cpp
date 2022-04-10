// Silver 4, 균형잡힌 세상
// 스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string Line;
	getline(cin, Line);
	while (Line != ".")
	{
		stack<char> S;
		for (char& c : Line)
		{
			if (c == '(' || c == '[')
				S.push(c);
			else if (c == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					S.push('x');
					break;
				}
				else
					S.pop();
			}
			else if (c == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					S.push('x');
					break;
				}
				else
					S.pop();
			}
		}
		cout << (S.empty() ? "yes\n" : "no\n");

		getline(cin, Line);
	}
}