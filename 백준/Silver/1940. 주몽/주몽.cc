#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == m)
            {
                ret++;
                break;
            }
        }
    }

    cout << ret;
}

