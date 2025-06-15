#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false);std::cout.tie(NULL);std::cin.tie(NULL);

int main()
{
	FAST_IO;

	vector<int> fee(3);
	for (int& i : fee)
	{
		cin >> i;
	}

	vector<int> time(101);
	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;
		for_each(time.begin() + start, time.begin() + end, [](int& x) { x++; });
	}

	int result = 0;
	for (int i : time)
	{
		if (i == 0)
		{
			continue;
		}

		result += i * fee[i - 1];
	}

	cout << result;
}

