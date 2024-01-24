#pragma warning (disable:4996)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <string>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	vector<int> ret(n, -1);
	stack<pair<int, int>> s;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		while (!s.empty())
		{
			if (s.top().second >= tmp)
			{
				break;
			}
			else
			{
				ret[s.top().first] = tmp;
				s.pop();
			}
		}

		s.push({ i,tmp });
	}

	for (auto i : ret)
	{
		cout << i << ' ';
	}
}
