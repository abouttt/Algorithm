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

int n, ret = 2147000000;
int a[3];
int dp[64][64][64];

int solve(int s, int c, int v)
{
	if (s == 0 && c == 0 && v == 0)
	{
		return 0;
	}

	if (dp[s][c][v] != 0)
	{
		return dp[s][c][v];
	}

	dp[s][c][v] = 1000000000;
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 9), max(0, c - 3), max(0, v - 1)) + 1);
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 9), max(0, c - 1), max(0, v - 3)) + 1);
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 3), max(0, c - 9), max(0, v - 1)) + 1);
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 3), max(0, c - 1), max(0, v - 9)) + 1);
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 1), max(0, c - 9), max(0, v - 3)) + 1);
	dp[s][c][v] = min(dp[s][c][v], solve(max(0, s - 1), max(0, c - 3), max(0, v - 9)) + 1);
	return dp[s][c][v];
}

int main()
{
	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << solve(a[0], a[1], a[2]);
}
