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

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

bool dp[3000][3000];

int main()
{
	
	char arr[3000];
	int cdp[3000] = { 0 };
	scanf("%s", arr);
	int n = strlen(arr);

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 0; j < n - i + 1; j++) 
		{
			if (i == 1)
				dp[j][j] = true;
			
			else if (i == 2)
			{
				if (arr[j] == arr[j + i - 1])
					dp[j][j + i - 1] = true;
				
				else
					dp[j][j + i - 1] = false;
			}
			else
			{
				if (arr[j] == arr[j + i - 1])
					dp[j][j + i - 1] = dp[j + 1][j + i - 2];
				else
					dp[j][j + i - 1] = false;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (dp[0][i])
		{
			cdp[i] = 1;
			continue;
		}
		
		int minimum = cdp[i - 1] + 1;
		
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j][i])
			{
				if (minimum > cdp[j - 1] + 1)
				{
					minimum = cdp[j - 1] + 1;
				}
			}
		}
		
		cdp[i] = minimum;
		
	}

	printf("%d", cdp[n - 1]);
	

	return 0;
}

