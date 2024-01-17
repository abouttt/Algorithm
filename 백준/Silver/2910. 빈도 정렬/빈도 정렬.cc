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

vector<int> v;
map<int, int> cnt;
map<int, int> order;

bool cmp(int a, int b)
{
	if (cnt[a] > cnt[b])
	{
		return true;
	}
	else if (cnt[a] == cnt[b] && order[a] < order[b])
	{
		return true;
	}

	return false;
}

int main()
{
	FAST_IO;

	int n, c;
	cin >> n >> c;

	v = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		cnt[v[i]]++;
		if (order.find(v[i]) == order.end())
		{
			order[v[i]] = i;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i : v)
	{
		cout << i << ' ';
	}
}
