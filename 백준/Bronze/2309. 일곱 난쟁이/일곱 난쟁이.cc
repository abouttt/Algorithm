#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	vector<int> v(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	do
	{
		if (accumulate(v.begin(), v.begin() + 7, 0) == 100)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << v[i] << '\n';
			}
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
}
