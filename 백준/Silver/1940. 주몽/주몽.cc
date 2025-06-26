#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

inline void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int& i : v)
	{
		cin >> i;
	}

	int ret = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] + v[j] == m)
			{
				ret++;
				break;
			}
		}
	}

	cout << ret;
}
