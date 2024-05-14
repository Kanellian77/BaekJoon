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

vector<int> graph[10010];
bool visited[10010];
int dp[10010][2];
int people[10010];

/// <summary>
///

void dfs(int cur)
{
	visited[cur] = true;
	dp[cur][0] = 0;
	dp[cur][1] = people[cur];

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[graph[cur][i]])	continue;
		
		dfs(next);
		
		dp[cur][0] += max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d ", &people[i]);
	
	int bufx, bufy;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		graph[bufx].push_back(bufy);
		graph[bufy].push_back(bufx);
	}
	
	dfs(1);
	
	printf("%d", max(dp[1][0], dp[1][1]));
}