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

int n, l, r;
int ret, sum;
int a[51][51];
bool visited[51][51];
vector<pair<int, int>> naras;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		int sub = abs(a[ny][nx] - a[y][x]);
		if (sub >= l && sub <= r)
		{
			visited[ny][nx] = true;
			naras.push_back({ ny,nx });
			sum += a[ny][nx];
			dfs(ny, nx);
		}
	}
}

int main()
{
	FAST_IO;

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		bool flag = false;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j])
				{
					continue;
				}

				naras.clear();
				naras.push_back({ i,j });
				visited[i][j] = true;
				sum = a[i][j];

				dfs(i, j);

				if (naras.size() > 1)
				{
					for (auto& nara : naras)
					{
						a[nara.first][nara.second] = sum / naras.size();
						flag = true;
					}
				}
			}
		}

		if (!flag)
		{
			break;
		}

		ret++;
	}
	
	cout << ret;
}
