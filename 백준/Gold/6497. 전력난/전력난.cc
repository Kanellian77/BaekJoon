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

// 입력은 여러 개의 테스트 케이스로 구분되어 있다.
// 각 테스트 케이스의 첫째 줄에는 집의 수 m과 길의 수 n이 주어진다. (1 ≤ m ≤ 200000, m - 1 ≤ n ≤ 200000)
// 이어서 n개의 줄에 각 길에 대한 정보 x, y, z가 주어지는데, 이는 x번 집과 y번 집 사이에 양방향 도로가 있으며 그 거리가 z미터라는 뜻이다. (0 ≤ x, y < m, x ≠ y)
// 도시는 항상 연결 그래프의 형태이고(즉, 어떤 두 집을 골라도 서로 왕래할 수 있는 경로가 있다), 도시상의 모든 길의 거리 합은 231미터보다 작다.
// 입력의 끝에서는 첫 줄에 0이 2개 주어진다.


// solved idea
// 전체도시에서 사용되는 모든 전력값을 더한 후 이동 최소값(최소신장트리)을 빼주면 절약하는 에너지가 나온다.
// 최소신장트리로 하는 이유는 제일 적은 비용으로 모든 노드를 갈수있는 방법이기 때문이다.
vector<pair<ll, ll>> graph[200010];
bool visited[200010];

int main()
{
	while (true)
	{
		ll m, n;
		ll buf0, buf1, buf2;
		ll maxi = 0;
		// 그래프 초기화;
		for (int i = 0; i < 200010; i++)
		{
			graph[i].clear();
			visited[i] = false;
		}

		scanf("%lld %lld", &m, &n);

		// 0 0 입력받으면 테스트케이스 종료
		if (m == 0 && n == 0)
			break;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%lld %lld %lld", &buf0, &buf1, &buf2);
			graph[buf0].push_back({ buf1, buf2 });
			graph[buf1].push_back({ buf0, buf2 });
			maxi += buf2;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prim;
		prim.push({ 0, 0 });

		ll ans = 0;

		while (!prim.empty())
		{
			ll curnode = prim.top().second;
			ll curdist = prim.top().first;
			prim.pop();

			if (visited[curnode])
				continue;

			visited[curnode] = true;
			ans += curdist;

			for (int i = 0; i < graph[curnode].size(); i++)
			{
				ll nextnode = graph[curnode][i].first;
				ll nextdist = graph[curnode][i].second;
				if (!visited[nextnode])
				{
					prim.push({ nextdist, nextnode });
				}
			}
		}

		printf("%lld\n", maxi-ans);
	}
	
	



}