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

int n, m, cheese, cnt, ret;
int a[101][101];
bool visited[101][101];

int main()
{
	FAST_IO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];

			if (a[i][j] == 1)
			{
				cheese++;
			}
		}
	}

	ret = cheese;

	while (cheese)
	{
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		visited[0][0] = true;

		while (!q.empty())
		{
			auto p = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = p.first + dy[i];
				int nx = p.second + dx[i];

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
					a[ny][nx] = 0;
					cheese--;
				}
				else
				{
					q.push({ ny,nx });
				}

				visited[ny][nx] = true;
			}
		}

		cnt++;
		if (cheese != 0)
		{
			ret = cheese;
		}
		memset(visited, false, sizeof(visited));
	}

	cout << cnt << '\n' << ret;
}
