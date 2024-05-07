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

#define infinity 10000000

vector<pair<int, int>> graph[510];
ll ans[510];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int buf0, buf1, buf2;

	bool cycle = false;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		graph[buf0].push_back({ buf1, buf2 });
	}

	
	for (int i = 0; i <= n ; i++)
		ans[i] = infinity;
	
	ans[1] = 0;
	for (int a = 1; a <= n; a++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				int node = graph[i][j].first;
				int pass = graph[i][j].second;
				if (ans[i]!= infinity && ans[node] > pass + ans[i])
				{
					ans[node] = pass + ans[i];
					if (a == n)
					{
						cycle = true;
						break;
					}
				}
			}
		}
	}
	

	if (cycle)
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		printf("%lld\n", (ans[i] == infinity) ? -1 : ans[i]);
	}
	return 0;
}