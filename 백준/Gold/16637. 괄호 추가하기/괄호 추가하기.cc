#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ret = -2147000000;
string s;
vector<int> nums;
vector<char> opers;

int calc(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

void solve(int here, int sum)
{
	if (here == nums.size() - 1)
	{
		ret = max(ret, sum);
		return;
	}

	solve(here + 1, calc(sum, nums[here + 1], opers[here]));

	if (here + 2 <= nums.size() - 1)
	{
		int tmp = calc(nums[here + 1], nums[here + 2], opers[here + 1]);
		solve(here + 2, calc(sum, tmp, opers[here]));
	}
}

int main()
{
	FAST_IO;

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			nums.push_back(s[i] - '0');
		}
		else
		{
			opers.push_back(s[i]);
		}
	}

	solve(0, nums[0]);

	cout << ret;
}
