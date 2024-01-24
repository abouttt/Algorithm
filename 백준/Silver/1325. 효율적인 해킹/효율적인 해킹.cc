#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <numeric>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
typedef long long ll;

int n, m;
vector<int> ret;
vector<vector<int>> v;
bool visited[10001];

int dfs(int here)
{
	int ret = 1;
	visited[here] = true;

	for (int there : v[here])
	{
		if (visited[there])
		{
			continue;
		}

		ret += dfs(there);
	}

	return ret;
}

int main()
{
	FAST_IO;

	cin >> n >> m;

	ret = vector<int>(n + 1);
	v = vector<vector<int>>(n + 1, vector<int>());

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		v[b].push_back(a);
	}

	int maxx = -2147000000;

	for (int i = 1; i < v.size(); i++)
	{
		memset(visited, false, sizeof(visited));

		ret[i] = dfs(i);
		maxx = max(ret[i], maxx);
	}

	for (int i = 1; i < ret.size(); i++)
	{
		if (ret[i] == maxx)
		{
			cout << i << ' ';
		}
	}
}
