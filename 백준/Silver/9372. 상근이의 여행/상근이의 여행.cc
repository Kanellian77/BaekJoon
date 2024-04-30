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

//상근이의 여행
//1. 사이클을 제외 해야한다. 최소신장트리문제
//첫 번째 줄에는 테스트 케이스의 수 T(T ≤ 100)가 주어지고,
//각 테스트 케이스마다 다음과 같은 정보가 주어진다.
//첫 번째 줄에는 국가의 수 N(2 ≤ N ≤ 1 000)과 비행기의 종류 M(1 ≤ M ≤ 10 000) 가 주어진다.
//이후 M개의 줄에 a와 b 쌍들이 입력된다.a와 b를 왕복하는 비행기가 있다는 것을 의미한다. (1 ≤ a, b ≤ n; a ≠ b)
//주어지는 비행 스케줄은 항상 연결 그래프를 이룬다.

int visited[1010];

void visitedinit()
{
	for (int i = 0; i <= 1010; i++)
		visited[i] = false;
	
}

int main()
{
	int t;
	int n, m;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &m);

		// 경로저장(그래프 만듬)
		vector<int> graph[1010];
		visitedinit();

		int buf0, buf1;
		
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &buf0, &buf1);
			graph[buf0].push_back(buf1);
			graph[buf1].push_back(buf0);
		}

		queue<int> bfs;
		
		// 시작점이 어디던간에 최소값을 구해야함
		// 모든가중치가 1임으로 한번씩만들른다 가정
		int ans = 0;
		bfs.push(1);
		visited[1] = true;

		while (!bfs.empty())
		{
			int cur = bfs.front();
			bfs.pop();

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i];
				if (!visited[next])
				{
					bfs.push(next);
					visited[next] = true;
					ans++;
				}
			}
		}

		printf("%d\n", ans);

	}
}