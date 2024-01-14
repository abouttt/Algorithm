#include <iostream>
#include <algorithm>
#include <string>
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

int main()
{
	FAST_IO;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> visited(n, vector<int>(m));
	vector<vector<int>> v(n, vector<int>(m));

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			{
				continue;
			}

			if (v[ny][nx] == 0)
			{
				continue;
			}

			if (visited[ny][nx])
			{
				continue;
			}

			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	cout << visited[n - 1][m - 1];
}
