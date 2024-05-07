#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
ll gong[200010];

int main()
{
	int n, c;
	ll start = 1;
	ll end = 0;
	ll ans = 0;

	scanf("%d %d", &n, &c);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &gong[i]);
		end = max(end, gong[i]);
	}
	
	sort(gong, gong + n);
	
	
	
	int idx = 0;
	int obj = 0;
	int dist = 0;
	
	
	while (start <= end)
	{
		idx = 0;
		obj = 0;
		int mid = (start + end) / 2;
		
		for (int i = 1; i < n; i++)
		{
			dist = gong[i] - gong[idx];
			if (dist >= mid)
			{
				obj++;
				idx = i;
			}
		}
		obj++;
		
		
		if (obj < c)
		{
			end = mid - 1;
		}
		else
		{
			ans = mid;
			start = mid + 1;
		}
		
	}
	printf("%lld", ans);
	return 0;
}