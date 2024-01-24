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

int n, root, erase;
vector<vector<int>> v;

int dfs(int here)
{
	int ret = 0;
	int child = 0;

	for (int there : v[here])
	{
		if (there == erase)
		{
			continue;
		}

		ret += dfs(there);
		child++;
	}

	if (child == 0)
	{
		return 1;
	}

	return ret;
}

int main()
{
	FAST_IO;

	cin >> n;

	v = vector<vector<int>>(n);

	for (int i = 0; i < n; i++)
	{
		int node;
		cin >> node;

		if (node == -1)
		{
			root = i;
			continue;
		}

		v[node].push_back(i);
	}

	cin >> erase;

	if (root == erase)
	{
		cout << 0;
		exit(0);
	}

	cout << dfs(root);
}
