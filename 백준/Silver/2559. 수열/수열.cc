#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += a[i];
	}

	int ret = sum;
	for (int i = k; i < n; i++)
	{
		sum -= a[i - k];
		sum += a[i];
		ret = max(ret, sum);
	}

	cout << ret;
}
