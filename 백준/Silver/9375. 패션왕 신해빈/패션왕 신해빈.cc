#include <iostream>
#include <map>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		string name, kind;
		map<string, int> clothes;

		for (int i = 0; i < n; i++)
		{
			cin >> name >> kind;
			clothes[kind]++;
		}

		int ret = 1;
		for (auto& ele : clothes)
		{
			ret *= (ele.second + 1);
		}

		cout << ret - 1 << '\n';
	}
}
