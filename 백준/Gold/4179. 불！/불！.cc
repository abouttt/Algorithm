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

int r, c;
char a[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
queue<pair<int, int>> fq;

int main()
{
	FAST_IO;

	cin >> r >> c;

	string s;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];

			if (a[i][j] == 'J')
			{
				q.push({ i,j });
				visited[i][j] = 1;
			}
			else if (a[i][j] == 'F')
			{
				fq.push({ i,j });
			}
		}
	}

	while (!fq.empty())
	{
		q.push(fq.front());
		fq.pop();
	}

	int ret = 2147000000;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + p.first;
			int nx = dx[i] + p.second;

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			{
				if (a[p.first][p.second] == 'J')
				{
					ret = std::min(ret, visited[p.first][p.second]);
				}

				continue;
			}

			if (a[ny][nx] == '#' || a[ny][nx] == 'F')
			{
				continue;
			}

			if (a[p.first][p.second] == 'J')
			{
				if (visited[ny][nx] != 0)
				{
					continue;
				}

				visited[ny][nx] = visited[p.first][p.second] + 1;
				a[ny][nx] = 'J';
			}
			else
			{
				a[ny][nx] = 'F';
			}

			q.push({ ny,nx });
		}
	}

	if (ret != 2147000000)
	{
		cout << ret;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
}
