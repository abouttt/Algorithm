#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	string s;
	stack<char> stk;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (stk.empty())
			{
				stk.push(s[j]);
			}
			else
			{
				if (stk.top() == s[j])
				{
					stk.pop();
				}
				else
				{
					stk.push(s[j]);
				}
			}
		}

		if (stk.empty())
		{
			ret++;
		}
		else
		{
			stack<char>().swap(stk);
		}
	}

	cout << ret;
}
