#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	int cnt[26] = {};
	string ret;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cnt[s[0] - 97]++;
		if (cnt[s[0] - 97] == 5)
		{
			ret += s[0];
		}
	}

	if (ret.size() > 0)
	{
		sort(ret.begin(), ret.end());
		cout << ret;
	}
	else
	{
		cout << "PREDAJA";
	}
}
