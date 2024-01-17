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

bool cmp(string& a, string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}

	return a.size() < b.size();
}

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		string tmp;
		for (int j = 0; j < s.size(); j++)
		{
			if (isdigit(s[j]))
			{
				if (tmp[0] == '0')
				{
					tmp.clear();
				}
				tmp += s[j];
			}
			else
			{
				if (!tmp.empty())
				{
					v.push_back(tmp);
					tmp.clear();
				}
			}
		}

		if (!tmp.empty())
		{
			v.push_back(tmp);
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (auto& i : v)
	{
		cout << i << '\n';
	}
}
