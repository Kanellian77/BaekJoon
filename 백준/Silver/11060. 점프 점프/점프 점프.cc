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

#define infinity 125000000;
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

int arr[1010];
int dp[1010];

int main()
{
	int n;
	
	scanf("%d", &n);
	
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = 1001;
	}
	dp[1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= i + arr[i]; j++)
		{
			int a = dp[i] + 1;
			if (dp[j] > a)
				dp[j] = a;
		}
	}
	printf("%d", dp[n] == 1001 ? -1 : dp[n]);
	
	return 0;
}