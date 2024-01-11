#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <numeric>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

int main()
{
	FAST_IO;

	int n, m;
	cin >> n >> m;

	map<int, string> dogamStr;
	map<string, int> dogamInt;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		dogamStr[i + 1] = s;
		dogamInt[s] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s;

		if (isalpha(s[0]))
		{
			cout << dogamInt[s] << '\n';
		}
		else
		{
			cout << dogamStr[atoi(s.c_str())] << '\n';
		}
	}
}
