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

vector<int> graph[1000100];
bool visited[1000100];
int dp[1000100][2];

/// <summary>
/// 얼리어답터의 갯수를 찾는문제 아이디어자체는 연결수가 많은 개체들을 찾아서 감염시키고 
/// 그 다음에 나머지를 찾는문제
/// 탐색을 하면서 진행해야할꺼같음
/// 규칙이 하나있는데 얼리어답터 근처 인접은 무조건 얼리어답터가 아니기 때문에 얼리어답터를 배치할때
/// 연결수가 많은 아이들로 해야 효율이좋음
/// [1]아임얼리/[0]아임노멀

void dfs(int cur)
{
	visited[cur] = true;
	dp[cur][0] = 0;
	dp[cur][1] = 1;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (visited[graph[cur][i]])	continue;
		
		dfs(next);
		
		dp[cur][0] += dp[next][1];
		dp[cur][1] += min(dp[next][0], dp[next][1]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int bufx, bufy;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		graph[bufx].push_back(bufy);
		graph[bufy].push_back(bufx);
	}
	
	dfs(1);
	
	printf("%d", min(dp[1][0], dp[1][1]));
}