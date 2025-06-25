#include <iostream>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	string s;
	getline(cin, s);

	for (char& c : s)
	{
		if (!isalpha(c))
		{
			continue;
		}

		int na = c + 13;
		int border = isupper(c) ? 'Z' : 'z';
		if(na > border)
		{
			na -= 26;
		}

		c = na;
	}

	cout << s;
}
