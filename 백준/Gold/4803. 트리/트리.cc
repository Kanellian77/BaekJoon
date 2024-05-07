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

bool visited[510];
vector<int>graph[510];

bool dfs(int cur, int preview)
{
	visited[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		if (graph[cur][i] == preview)
			continue;

		if (visited[graph[cur][i]])
			return false;
		else
			if (!dfs(graph[cur][i], cur))
				return false;
		
	}

	return true;
}

int main()
{
	int n, m;
	int cnt = 1;
	int ans;
	while (1)
	{
		ans = 0;
		for (int i = 0; i <= 500; i++)
		{
			graph[i].clear();
			visited[i] = false;
		}
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		int buf0, buf1;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &buf0, &buf1);
			graph[buf0].push_back(buf1);
			graph[buf1].push_back(buf0);
		}
		
		for (int i = 1; i <= n; i++)
			if (dfs(i, 0))
				ans++;
			
		printf("Case %d: ", cnt);
		if (ans == 0)
		{
			printf("No trees.\n");
		}
		else if (ans == 1)
		{
			printf("There is one tree.\n");
		}
		else
		{
			printf("A forest of %d trees.\n", ans);
		}
		cnt++;
	}
	return 0;
}
