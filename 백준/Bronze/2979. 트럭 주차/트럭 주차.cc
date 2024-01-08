#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int pay[3] = {};
	for (int i = 0; i < 3; i++)
	{
		cin >> pay[i];
	}

	int cnt[100] = {};
	int minn = 99;
	int maxx = 0;
	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;
		minn = min(minn, start);
		maxx = max(maxx, end);
		for (int j = start; j < end; j++)
		{
			cnt[j]++;
		}
	}

	int total = 0;
	for (int i = minn; i < maxx; i++)
	{
		total += cnt[i] * pay[cnt[i] - 1];
	}

	cout << total;
}
