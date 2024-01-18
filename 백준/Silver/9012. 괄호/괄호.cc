#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;

		stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stk.push('(');
			}
			else if (s[i] == ')')
			{
				if (stk.empty())
				{
					stk.push('.');
					break;
				}
				else
				{
					stk.pop();
				}
			}
		}

		if (stk.empty())
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}
