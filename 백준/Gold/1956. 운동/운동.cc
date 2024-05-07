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


int ans[410][410];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans[i][j] = infinity;

	for (int i = 1; i <= n; i++)
		ans[i][i] = 0;


	int buf0, buf1, buf2;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		if (ans[buf0][buf1] > buf2)
			ans[buf0][buf1] = buf2;
	}

	for (int so = 1; so <= n; so++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (ans[i][j] > ans[i][so] + ans[so][j])
					ans[i][j] = ans[i][so] + ans[so][j];

	int mini = infinity;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				int buf = ans[i][j] + ans[j][i];
				if (mini > buf)
					mini = buf;
			}
		}
		
	}

	printf("%d", mini == infinity ? -1 : mini);

	return 0;
}
