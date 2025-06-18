#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	string s;
	cin >> s;

	string rs = s;
	reverse(rs.begin(), rs.end());

	cout << (s == rs);
}
