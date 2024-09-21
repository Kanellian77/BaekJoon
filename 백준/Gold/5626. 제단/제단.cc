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

int dp[10010][5001];
int arr[10010];

int main()
{
	int n;
int s = 1000000007;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	

	if (arr[0] > 0 || arr[n-1] >0)
	{
		printf("0");
		return 0;
	}
	
	dp[0][0] = 1;

	for (int col = 1; col < n; col++)
	{
		if (arr[col] < 0)
		{
			dp[col][0] = (dp[col - 1][0] + dp[col - 1][1]) % s;
			for (int h = 1; h < 5000; h++)
				dp[col][h] = ((dp[col - 1][h - 1] + dp[col - 1][h]) % s + dp[col - 1][h + 1]) % s;
			
		}
		else
		{
			if (arr[col] == 0)
				dp[col][arr[col]] = (dp[col - 1][arr[col]] + dp[col - 1][arr[col] + 1]) % s;
			else
				dp[col][arr[col]] = ((dp[col - 1][arr[col] - 1] + dp[col - 1][arr[col]]) % s + dp[col - 1][arr[col] + 1]) % s;
			
		}
	}
	
	printf("%d", dp[n-1][0]);
	
	return 0;
}