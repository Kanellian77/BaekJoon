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

vector<int> student[100010];
int inDegree[100010];
vector<int>ans;
bool visited[100010];
/// <summary>
/// 1. 위상정렬문제다
/// 2. 방향성을 가진 그래프이다. 가르켜진 노드들은 가르켜진 횟수가 각 노드 inDegree에 저장을 한다.
/// 3. 큐를 사용하여 가르켜진 횟수가 0인 노드들을 큐에 넣어준다.
/// 4. BFS마냥 굴려준다.

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	
	int buf0, buf1;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &buf0, &buf1);
		student[buf0].push_back(buf1);
		inDegree[buf1]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> node;

	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0)
		{
			node.push(i);
			break;
		}
	
	int cur, obj;
	
	while (!node.empty())
	{
		cur = node.top();
		node.pop();

		ans.push_back(cur);
		visited[cur] = true;
		

		for (int i = 0; i < student[cur].size(); i++)
		{
			obj = student[cur][i];
			inDegree[obj]--;
			if (inDegree[obj] == 0)
				node.push(obj);
		}

		if (node.empty() && ans.size() != n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (inDegree[i] == 0 && !visited[i])
				{
					node.push(i);
					break;
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");

}