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

	int cnt[26] = {};
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << ' ';
	}
}
