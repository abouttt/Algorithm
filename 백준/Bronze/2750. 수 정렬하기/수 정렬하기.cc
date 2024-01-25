#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (auto i : v)
	{
		cout << i << '\n';
	}
}
