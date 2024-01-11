#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int a[26]{};
	string s;
	cin >> s;

	for (auto c : s)
	{
		a[c - 'A']++;
	}

	bool hasOdd = false;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] == 0)
		{
			continue;
		}

		if (a[i] % 2 == 1)
		{
			if (hasOdd)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}

			hasOdd = true;
		}
	}

	string ret;
	for (int i = 25; i >= 0; i--)
	{
		while (a[i])
		{
			if (a[i] % 2 == 0)
			{
				ret.insert(ret.begin(), i + 'A');
				ret.insert(ret.end(), i + 'A');
				a[i] -= 2;
			}
			else
			{
				int mid = ret.size() / 2;
				ret.insert(ret.begin() + mid, i + 'A');
				a[i]--;
			}
		}
	}

	cout << ret;
}
