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

int main()
{
	FAST_IO;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int two = 0;
		int five = 0;

		for (int i = 2; i <= n; i *= 2)
		{
			two += n / i;
		}

		for (int i = 5; i <= n; i *= 5)
		{
			five += n / i;
		}

		cout << min(two, five) << '\n';
	}
}
