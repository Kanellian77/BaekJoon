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

// 정점과 연결된 간선
int n, e;

// 그래프
vector<pair<int, int>> graph[1000];


// 방문한 점과 visited한 배열
vector<int> dijkstra(int defstart, int defstartw)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>bfs;
	int start, startw;
	int conected;
	int currentpoint, currentdist;
	int minimum = infinity;
	vector<int> visited(1000);

	for (int i = 0; i <= n; i++)
	{
		if (i == defstart)
		{
			visited[i] = defstartw;
			continue;
		}
		visited[i] = minimum;
	}

	bfs.push({ defstart, defstartw });

	while (!bfs.empty())
	{
		start = bfs.top().first;
		startw = bfs.top().second;
		bfs.pop();
		conected = graph[start].size();
		for (int i = 0; i < conected; i++)
		{
			currentpoint = graph[start][i].first;
			currentdist = graph[start][i].second;
			if (visited[currentpoint] > currentdist + startw)
			{
				bfs.push({ currentpoint, startw + currentdist });
				visited[currentpoint] = currentdist + startw;
			}
		}
	}
	return visited;
}
int main()
{
	int buf0, buf1, buf2;
	int uvline;
	int u, v;

	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		graph[buf0].push_back({ buf1, buf2 });
		graph[buf1].push_back({ buf0, buf2 });
	}
	scanf("%d %d", &u, &v);

	for (int i = 0; i < graph[u].size(); i++)
		if (graph[u][i].first == v)
			uvline = graph[u][i].second;
	

	vector<int> start = dijkstra(1, 0);
	vector<int> ustart = dijkstra(u, 0);
	vector<int> vstart = dijkstra(v, 0);
	
	int ans = min(start[u] + ustart[v] + vstart[n], start[v] + vstart[u] + ustart[n]);
	
	
	printf("%d", ans < infinity ? ans : -1);


	return 0;
}