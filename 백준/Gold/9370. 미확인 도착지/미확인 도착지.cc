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

vector<pair<int, int>> graph[2100];
vector<int>object;
// 점의갯수, 도로의갯수, 목적지 후보의수;
int n, m, t;

vector<int> dijkstra(int defstart)
{
	priority_queue<int, vector<int>, greater<int>> bfs;
	bfs.push(defstart);
	
	vector<int> visited;
	for (int i = 0; i <= n; i++)
	{
		if (i == defstart)
		{
			visited.push_back(0);
			continue;
		}
		visited.push_back(infinity);
	}

	int start;
	int startw;

	while (!bfs.empty())
	{
		start = bfs.top();
		startw = visited[start];
		bfs.pop();

		int graphcnt = graph[start].size();
		int target, targetw;
		
		for (int i = 0; i < graphcnt; i++)
		{
			target = graph[start][i].first;
			targetw = graph[start][i].second;
			if (visited[target] > startw + targetw) 
			{
				visited[target] = startw + targetw;
				bfs.push(target);
			}
		}
	}

	return visited;
}
int main()
{
	int T;
	int s;
	// 경유지
	int g, h;
	int buf0, buf1, buf2;
	int objectbuf;
	vector<int>ans;
	scanf("%d", &T);

	while (T--)
	{
		ans.clear();
		object.clear();
		for (int i = 0; i <= 2100; i++)
			graph[i].clear();
		
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &buf0, &buf1, &buf2);
			graph[buf0].push_back({ buf1, buf2 });
			graph[buf1].push_back({ buf0, buf2 });
		}

		for (int i = 0; i < t; i++)
		{
			scanf("%d", &objectbuf);
			object.push_back(objectbuf);
		}

		vector<int> visited = dijkstra(s);
		vector <int> gstartvisited = dijkstra(g);
		vector <int> hstartvisited = dijkstra(h);

		for (int i = 0; i < t; i++)
		{
			//s-g-h-object
			int sgho = visited[g] + gstartvisited[h] + hstartvisited[object[i]];
			//s-h-g-object
			int shgo = visited[h] + hstartvisited[g] + gstartvisited[object[i]];
			

			if (visited[object[i]] == min(sgho, shgo))
				ans.push_back(object[i]);
		}

		sort(ans.begin(), ans.end());
		
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		
		printf("\n");
	}


	return 0;
}