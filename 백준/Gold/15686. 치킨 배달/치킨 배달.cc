#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, ret = 2147000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> tmp;

void combi(int start, vector<pair<int, int>>& v)
{
	if (v.size() == m)
	{
		int sum = 0;
		for (auto& h : home)
		{
			int minn = 2147000000;
			for (auto& c : v)
			{
				int d = abs(h.first - c.first) + abs(h.second - c.second);
				minn = min(minn, d);
			}
			sum += minn;
		}
		ret = min(ret, sum);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++)
	{
		v.push_back(chicken[i]);
		combi(i, v);
		v.pop_back();
	}
}

int main()
{
	FAST_IO;

	cin >> n >> m;

	int d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d;
			if (d == 1)
			{
				home.push_back({ i,j });
			}
			else if (d == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	combi(-1, tmp);

	cout << ret;
}
