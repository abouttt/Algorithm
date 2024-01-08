#include <iostream>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (!isalpha(s[i]))
		{
			continue;
		}

		int na = s[i] + 13;
		int border = isupper(s[i]) ? 90 : 122;
		if (na > border)
		{
			na -= 26;
		}

		s[i] = na;
	}

	cout << s;
}
