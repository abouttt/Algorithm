#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	FastIO();

	string s;
	cin >> s;

	vector<int> v(26, 0);
	for (char c : s)
	{
		v[c - 'a']++;
	}

	for (int i : v)
	{
		cout << i << ' ';
	}
}
