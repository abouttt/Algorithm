#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll a, b, c;

ll solve(ll n, ll e)
{
	if (e == 1)
	{
		return n % c;
	}

	ll ret = solve(n, e / 2);
	ret = (ret * ret) % c;
	if (e % 2)
	{
		ret = (ret * n) % c;
	}

	return ret;
}

int main()
{
	FAST_IO;

	cin >> a >> b >> c;
	cout << solve(a, b);
}
