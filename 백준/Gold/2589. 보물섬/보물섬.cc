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

int n, m, ret = -2147000000;
vector<pair<int, int>> ground;
char a[51][51];
int visited[51][51];

int main()
{
	FAST_IO;

	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
			if (a[i][j] == 'L')
			{
				ground.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < ground.size(); i++)
	{
		queue<pair<int, int>> q;
		q.push(ground[i]);
		visited[ground[i].first][ground[i].second] = 1;

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

				if (a[ny][nx] == 'W')
				{
					continue;
				}

				if (visited[ny][nx])
				{
					continue;
				}

				q.push({ ny,nx });
				visited[ny][nx] = visited[p.first][p.second] + 1;
				ret = max(ret, visited[ny][nx]);
			}
		}

		memset(visited, 0, sizeof(visited));
	}

	cout << ret - 1;
}
