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
/// 1. 우수마을이 많을수록 인구수가 증가한다.
/// 2. 이문제는 최댓값을 구하는문제다.
/// 3. 비우수마을은 비우수마을과 우수마을이 둘다 인접할수 있다.
/// 4. 우수마을은 비우수마을과 다르게 무조건 비우수마을과 연결되어야한다.
/// 
/// ans 
/// 1. 이 문제는 결론적으로 비우수마을의 수를 최소값으로 하는 트리를 구하는 문제다.
/// 2. 그러면 비우수마을의 수를 최소값으로하며 우수마을들의 사람값이 가장 많은것을 구하는 문제기도하다.

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