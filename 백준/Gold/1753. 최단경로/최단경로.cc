#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

// 각 번호의 최단거리 값들
int ans[20010];
// 그래프
vector<pair<int, int>> graph[20010];

int main()
{
	int v, e;
	int start;
	int buf0, buf1, buf2;
	scanf("%d %d", &v, &e);
	scanf("%d", &start);


	for (int i = 1; i <= v; i++)
	{
		//가중치 최대값
		ans[i] = (10 * v) + 1;
	}

	// 간선잇기
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		graph[buf0].push_back({ buf1, buf2 });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
	
	ans[start] = 0;
	bfs.push({ ans[start], start });
	int connectdot;
	int connectdotw;

	while (!bfs.empty())
	{
		start = bfs.top().second;
		bfs.pop();
		for (int i = 0; i < graph[start].size(); i++)
		{
			connectdot = graph[start][i].first;// 연결된 점
			connectdotw = graph[start][i].second;// 연결된 점의 가중치
			
			if (ans[connectdot] > ans[start] + connectdotw)
			{
				ans[connectdot] = ans[start] + connectdotw;
				bfs.push({ ans[connectdot], connectdot });
			}
		}
	}
	
	for (int i = 1; i <= v; i++)
	{
		if ((10 * v) + 1 == ans[i])
		{
			printf("INF\n");
			continue;
		}
		printf("%d\n", ans[i]);
		
	}



}

