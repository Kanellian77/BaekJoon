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

vector<pair<int,int>> graph[10010];
bool visited[10010];

// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10, 000)와 간선의 개수 E(1 ≤ E ≤ 100, 000)가 주어진다.
// 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
// 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.C는 음수일 수도 있으며, 절댓값이 1, 000, 000을 넘지 않는다.
// 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다.
// (int 범위라는 뜻)최소 스패닝 트리의 가중치가 - 2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.


int main()
{
	int v, e;

	scanf("%d %d", &v, &e);
	
	int buf0, buf1, buf2;

	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		graph[buf0].push_back({ buf1, buf2 });
		graph[buf1].push_back({ buf0, buf2 });
	}

	int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prim;
	prim.push({ 0,1 });

	while (!prim.empty())
	{
		int startn = prim.top().second;
		int startd = prim.top().first;
		
		prim.pop();

		if (visited[startn]) continue;
		
		visited[startn] = true;
		ans += startd;

		for (int i = 0; i < graph[startn].size(); i++)
		{
			int nextn = graph[startn][i].first;
			int nextd = graph[startn][i].second;
			prim.push({ nextd, nextn });
		}

	}

	printf("%d\n", ans);

}