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

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int n;
int a[101][101];
bool visited[101][101];

void dfs(int y, int x, int h)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
		{
			continue;
		}

		if (a[ny][nx] <= h)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		dfs(ny, nx, h);
	}
}

int main()
{
	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int h = 0;
	int ret = 0;
	while (h <= 100)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] <= h)
				{
					continue;
				}

				if (visited[i][j])
				{
					continue;
				}

				dfs(i, j, h);
				cnt++;
			}
		}

		ret = max(ret, cnt);
		memset(visited, 0, sizeof(visited));
		h++;
	}

	cout << ret;
}
