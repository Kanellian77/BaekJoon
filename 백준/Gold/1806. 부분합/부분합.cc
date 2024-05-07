#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <string.h>

#define infinity 10000000
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

int main()
{
	int n, s;
	int arrsum[100010] = {0};
	int arr[100010];
	scanf("%d %d", &n, &s);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		arrsum[i] = arrsum[i - 1] + arr[i];
	}
	
	int start = 1;
	int end = 1;
	int minimum = n + 1;
	int ansstart = -1;
	int ansend = n;

	while(start <= end)
	{
		if (end > n || start > n)
			break;

		if (arrsum[end] - arrsum[start - 1] >= s)
		{
			if (minimum > end - start + 1)
			{
				minimum = end - start + 1;
				ansstart = start;
				ansend = end;
			}
			start++;
		}
		else
		{
			end++;
		}
	}

	int ans;
	if ((ansstart == -1 && ansend == n) || ansstart > ansend)
		ans = 0;
	else
		ans = ansend - ansstart+1;

	printf("%d", ans);
	return 0;


}
