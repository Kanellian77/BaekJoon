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

vector<int> graph[510];
vector<int> lastrank(510);
vector<int> ans;
vector<int> inDegree(510);
/// <summary>


int main()
{
	int tcase;
	scanf("%d", &tcase);

	while (tcase--)
	{
		// 그래프 초기화
		for (int i = 0; i < 510; i++)
		{
			graph[i].clear();
			lastrank[i] = 0;
			inDegree[i] = 0;
		}
		ans.clear();
		
		// 팀의 수
		int n;
		scanf("%d", &n);

		
		// 작년 랭크
		for (int i = 1; i <= n; i++)
			scanf("%d", &lastrank[i]);
		
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) 
			{
				graph[lastrank[i]].push_back(lastrank[j]);
				inDegree[lastrank[j]]++;
			}
		
		// 변동의 갯수
		int m;
		
		int buf0, buf1;

		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &buf0, &buf1);
			
			auto iter1 = find(graph[buf1].begin(), graph[buf1].end(), buf0);
			auto iter2 = find(graph[buf0].begin(), graph[buf0].end(), buf1);
			if (iter1 != graph[buf1].end())
			{
				//새로운 연결을 넣어준다.
				graph[buf1].erase(iter1);
				inDegree[buf0]--;
				//새로운 연결을 넣어준다.
				graph[buf0].push_back(buf1);
				inDegree[buf1]++;
			}
			else
			{
				//새로운 연결을 넣어준다.
				graph[buf0].erase(iter2);
				inDegree[buf1]--;
				//새로운 연결을 넣어준다.
				graph[buf1].push_back(buf0);
				inDegree[buf0]++;
			}
			
			
		}


		queue<int> node;
		for (int i = 1; i <= n; i++)
		{
			if (inDegree[lastrank[i]] == 0)
				node.push(lastrank[i]);
		}

		if (node.size() >= 2)
		{
			printf("?\n");
			continue;
		}
		if (node.size() == 0)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		int cur, obj;

		while (!node.empty())
		{
			cur = node.front();
			node.pop();
			if (!node.empty())
			{
				printf("?\n");
				break;
			}

			ans.push_back(cur);
			for (int i = 0; i < graph[cur].size(); i++)
			{
				obj = graph[cur][i];
				inDegree[obj]--;
				if (inDegree[obj] == 0)
					node.push(obj);
			}
		}

		if (!node.empty())
			continue;
		
		if (ans.size() == n)
		{
			for (int i = 0; i < ans.size(); i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
}