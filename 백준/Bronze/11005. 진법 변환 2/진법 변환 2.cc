#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int main()
{
	FAST_IO;

	int n, b;
	cin >> n >> b;

	string ret;
	while (n != 0)
	{
		int tmp = n % b;
		if (tmp > 9)
		{
			tmp = tmp - 10 + 'A';
			ret += tmp;
		}
		else
		{
			ret += ('0' + tmp);
		}
		n /= b;
	}

	reverse(ret.begin(), ret.end());

	cout << ret << '\n';
}
