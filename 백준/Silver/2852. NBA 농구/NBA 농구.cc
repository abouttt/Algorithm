#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
using ll = long long;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
	FAST_IO;

	int n;
	scanf("%d", &n);

	int scoreA = 0, scoreB = 0;
	int timeA = 0, timeB = 0;
	int cur = 0;

	for (int i = 0; i < n; i++)
	{
		int team;
		scanf("%d", &team);

		int min, sec;
		scanf("%2d:%2d", &min, &sec);

		if (scoreA > scoreB)
		{
			timeA += min * 60 + sec - cur;
		}
		else if (scoreA < scoreB)
		{
			timeB += min * 60 + sec - cur;
		}

		if (team == 1)
		{
			scoreA++;
		}
		else
		{
			scoreB++;
		}

		cur = min * 60 + sec;
	}

	if (scoreA > scoreB)
	{
		timeA += 2880 - cur;
	}
	else if (scoreA < scoreB)
	{
		timeB += 2880 - cur;
	}

	printf("%02d:%02d\n", timeA / 60, timeA % 60);
	printf("%02d:%02d\n", timeB / 60, timeB % 60);
}
