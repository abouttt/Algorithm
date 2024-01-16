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

int main()
{
	FAST_IO;

	int n, m, j, ret = 0;

	cin >> n >> m >> j;

	int lt = 1;
	int rt = m;

	for (int i = 0; i < j; i++)
	{
		int apple;
		cin >> apple;

		if (apple < lt)
		{
			int tmp = lt - apple;
			lt -= tmp;
			rt -= tmp;
			ret += tmp;
		}
		else if (apple > rt)
		{
			int tmp = apple - rt;
			lt += tmp;
			rt += tmp;
			ret += tmp;
		}
	}

	cout << ret;
}
