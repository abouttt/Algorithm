#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
using ll = long long;

inline void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();

	int n, m;
	cin >> n >> m;

	string s;
	map<string, int> si;
	map<int, string> is;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		si.emplace(s, i);
		is.emplace(i, s);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s;

		if (isdigit(s[0]))
		{
			cout << is[stoi(s)];
		}
		else
		{
			cout << si[s];
		}

		cout << '\n';
	}
}
