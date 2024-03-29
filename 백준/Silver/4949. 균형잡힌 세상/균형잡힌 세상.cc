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

	while (true)
	{
		string s;
		getline(cin, s);

		if (s == ".")
		{
			break;
		}

		stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			if (!(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']'))
			{
				continue;
			}

			if (s[i] == '(' || s[i] == '[')
			{
				stk.push(s[i]);
			}
			else if (s[i] == ')' && !stk.empty() && stk.top() == '(')
			{
				stk.pop();
			}
			else if (s[i] == ']' && !stk.empty() && stk.top() == '[')
			{
				stk.pop();
			}
			else
			{
				if (stk.empty())
				{
					stk.push('.');
				}
				break;
			}
		}

		if (stk.empty())
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
}
