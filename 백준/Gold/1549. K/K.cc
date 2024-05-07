#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

ll superadd[4000] = {0};

int main()
{
	int n;
	scanf("%d", &n);
	
	ll buf;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &buf);
		superadd[i] = superadd[i - 1] + buf;
	}

	pair<ll, ll> minimum = { 9223372036854775807, 0 };
	ll ik;
	ll jk;

	for (int k = 1; k <= n / 2; k++)
	{	
		for (int j = k; j <= n; j++)
		{
			for (int i = j + k; i <= n; i++)
			{
				ik = superadd[j] - superadd[j - k];
				jk = superadd[i] - superadd[i - k];
				if (minimum.first >= abs(ik - jk))
				{
					minimum.first = abs(ik - jk);
					minimum.second = k;
				}
			}
		}
	}
	printf("%lld\n%lld\n", minimum.second, minimum.first);
	
	return 0;
}

