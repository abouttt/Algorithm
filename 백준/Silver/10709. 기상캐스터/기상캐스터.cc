#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <numeric>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
typedef long long ll;

int main()
{
	FAST_IO;

	int h, w;
	cin >> h >> w;

	while (h--)
	{
		string s;
		cin >> s;

		vector<int> v(w, -1);

		for (int i = 0; i < s.size(); i++)
		{
			bool flag = false;
			int cnt = -1;
			for (int j = i; j >= 0; j--)
			{
				cnt++;

				if (s[j] == 'c')
				{
					flag = true;
					break;
				}
			}

			if (flag)
			{
				v[i] = cnt;
			}
		}

		for (int i : v)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}
