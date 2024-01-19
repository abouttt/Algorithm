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

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n, m, ret;
int a[9][9];
bool visited[9][9];
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		if (a[ny][nx] == 1)
		{
			continue;
		}

		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}

int solve()
{
	memset(visited, false, sizeof(visited));

	for (auto& p : virus)
	{
		visited[p.first][p.second] = true;
		dfs(p.first, p.second);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && !visited[i][j])
			{
				cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	FAST_IO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 0)
			{
				blank.push_back({ i,j });
			}
			else if (a[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < blank.size(); i++)
	{
		for (int j = i + 1; j < blank.size(); j++)
		{
			for (int k = j + 1; k < blank.size(); k++)
			{
				a[blank[i].first][blank[i].second] = 1;
				a[blank[j].first][blank[j].second] = 1;
				a[blank[k].first][blank[k].second] = 1;
				ret = max(ret, solve());
				a[blank[i].first][blank[i].second] = 0;
				a[blank[j].first][blank[j].second] = 0;
				a[blank[k].first][blank[k].second] = 0;
			}
		}
	}

	cout << ret;
}
