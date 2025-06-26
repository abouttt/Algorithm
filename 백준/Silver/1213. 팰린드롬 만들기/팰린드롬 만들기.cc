#include <iostream>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	string s;
	cin >> s;

	int cnt[26]{};
	for (char c : s)
	{
		cnt[c - 'A']++;
	}

	bool hasOdd = false;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0)
		{
			continue;
		}

		if (cnt[i] % 2 == 1)
		{
			if (hasOdd)
			{
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}

			hasOdd = true;
		}
	}

	string ret;
	for (int i = 25; i >= 0; i--)
	{
		while (cnt[i])
		{
			if (cnt[i] % 2 == 0)
			{
				ret.insert(ret.begin(), i + 'A');
				ret.insert(ret.end(), i + 'A');
				cnt[i] -= 2;
			}
			else
			{
				int mid = ret.size() / 2;
				ret.insert(ret.begin() + mid, i + 'A');
				cnt[i]--;
			}
		}
	}

	cout << ret;
}
