#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 666;; i++)
	{
		string s = to_string(i);
		if (s.find("666") != s.npos)
		{
			cnt++;
			if (n == cnt)
			{
				cout << i;
				break;
			}
		}
	}
}
