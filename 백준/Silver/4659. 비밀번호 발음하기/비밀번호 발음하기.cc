#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	while (true)
	{
		string s;
		cin >> s;
		if (s == "end")
		{
			return 0;
		}

		bool flag = true;
		char prevChar = '.';
		int moumCnt = 0;
		int jaumCnt = 0;
		bool hasMoum = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				moumCnt++;
				jaumCnt = 0;
				hasMoum = true;
			}
			else
			{
				jaumCnt++;
				moumCnt = 0;
			}

			if (moumCnt >= 3 || jaumCnt >= 3)
			{
				flag = false;
				break;
			}

			if (prevChar == s[i])
			{
				if (s[i] == 'e' || s[i] == 'o')
				{
					continue;
				}

				flag = false;
				break;
			}
			else
			{
				prevChar = s[i];
			}
		}

		if (flag && hasMoum)
		{
			cout << "<" << s << ">" << " is acceptable." << '\n';
		}
		else
		{
			cout << "<" << s << ">" << " is not acceptable." << '\n';
		}
	}
}
