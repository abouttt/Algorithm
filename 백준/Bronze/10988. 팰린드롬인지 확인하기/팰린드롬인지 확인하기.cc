#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	string s;
	cin >> s;
	string rs(s);
	reverse(s.begin(), s.end());
	int result = s == rs;
	cout << result;
}
