#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		map<string, int> clothes;
		string name, kind;
		for (int i = 0; i < n; i++)
		{
			cin >> name >> kind;
			clothes[kind]++;
		}

		int ret = 1;
		for (auto& ele : clothes)
		{
			ret *= ele.second + 1;
		}

		cout << ret - 1 << '\n';
	}
}
