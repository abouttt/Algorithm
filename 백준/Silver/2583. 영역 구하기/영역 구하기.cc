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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n, m, k, cnt, ret;
int a[101][101];
bool visited[101][101];

void dfs(int y, int x)
{
	cnt++;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		{
			continue;
		}

		if (a[ny][nx] == 1)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		dfs(ny, nx);
	}
}

int main()
{
	FAST_IO;

	cin >> n >> m >> k;

	int tx, ty, bx, by;
	for (int i = 0; i < k; i++)
	{
		cin >> bx >> by >> tx >> ty;

		for (int y = by; y < ty; y++)
		{
			for (int x = bx; x < tx; x++)
			{
				a[y][x] = 1;
			}
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				continue;
			}

			if (visited[i][j])
			{
				continue;
			}

			dfs(i, j);
			pq.push(cnt);

			ret++;
			cnt = 0;
		}
	}

	cout << ret << '\n';
	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}
}
