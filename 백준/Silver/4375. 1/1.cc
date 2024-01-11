#include <iostream>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	while (cin >> n)
	{
		int ret = 1;
		int cnt = 1;
		while (true)
		{
			if (cnt % n == 0)
			{
				cout << ret << '\n';
				break;
			}
			else
			{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
}
