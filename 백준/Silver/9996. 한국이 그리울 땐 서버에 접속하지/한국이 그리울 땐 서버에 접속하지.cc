#include <iostream>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	cin >> n;

	string s;
	cin >> s;

	int star = s.find('*');
	auto p = make_pair(s.substr(0, star), s.substr(star + 1, s.size()));

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s.size() < p.first.size() + p.second.size())
		{
			cout << "NE" << endl;
			continue;
		}

		if (p.first == s.substr(0, p.first.size()) &&
			p.second == s.substr(s.size() - p.second.size(), s.size()))
		{
			cout << "DA" << endl;
		}
		else
		{
			cout << "NE" << endl;
		}
	}
}
