#include <iostream>
#include <vector>

using namespace std;

inline void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int& n : v)
	{
		cin >> n;
	}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += v[i];
	}

	int ret = sum;
	for (int i = k; i < v.size(); i++)
	{
		sum -= v[i - k];
		sum += v[i];
		ret = std::max(sum, ret);
	}

	cout << ret;
}
