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
int weight[10010];
vector<int> ans;
/// <summary>
/// 1. 최대 독립집합의 가중치가 커져야함
/// 2. 이 문제는 최댓값을 구하는문제다.
/// 3. 선택 노드 다음에는 무조건 비선택 노드여야 한다.
/// 4. 비선택노드 다음에는 선택노드or 비선택 노드가 와도 된다.
/// 
/// ans 
/// 1. 이 문제는 결론적으로 비선택 노드의 수를 최소값으로 하는 트리를 구하는 문제다.
/// 2. 그러면 비선택 노드의 수를 최소값으로하며 선택 노드들의 가중치값이 가장 많은것을 구하는 문제기도하다.

void dfs(int cur)
{
	visited[cur] = true;
	dp[cur][0] = 0;
	dp[cur][1] = weight[cur];

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[graph[cur][i]])	continue;
		
		dfs(next);

		dp[cur][0] += max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];

	}
}

void dfs1(int cur, int stat)
{
	visited[cur] = true;
	if (stat == 1)
		ans.push_back(cur);

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[graph[cur][i]])	continue;

		if (stat == 1)
		{
			dfs1(next, 0);
		}
		else
		{
			if (dp[next][0] > dp[next][1])
				dfs1(next, 0);
			else
				dfs1(next, 1);
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d ", &weight[i]);
	
	int bufx, bufy;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		graph[bufx].push_back(bufy);
		graph[bufy].push_back(bufx);
	}
	
	dfs(1);
	
	printf("%d\n", max(dp[1][0], dp[1][1]));

	for (int i = 0; i < 10010; i++)
		visited[i] = false;
	
	if (dp[1][0] > dp[1][1])
	{
		dfs1(1, 0);
	}
	else
	{
		dfs1(1, 1);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
}