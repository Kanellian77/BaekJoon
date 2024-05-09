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

vector<int> graph[100010];
bool visited[100010];
int dp[100010];

/// <summary>
/// 문제 힌트보고 더꼬인문제 처음에는 그래프를 받아오는줄알았다
/// 힌트를 보면 더꼬임 단순하게 dfs로 root부터 탐색하면 나오는문제
/// 이 문제를 다이나믹이라고 보기에는 좀 힘든거같다.

int dfs(int root)
{
	if (visited[root])
		return dp[root];

	visited[root] = true;
	for (int i = 0; i < graph[root].size(); i++)
	{
		if (visited[graph[root][i]]) 
			continue;
		dp[root] = dp[root] + dfs(graph[root][i]);
	}
	return dp[root];
}

int main()
{
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);

	int bufx, bufy;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		graph[bufx].push_back(bufy);
		graph[bufy].push_back(bufx);
	}
	
	for (int i = 1; i <= n; i++)
		dp[i] = 1;
	
	dfs(r);

	int bufans;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &bufans);
		printf("%d\n", dp[bufans]);
	}
}