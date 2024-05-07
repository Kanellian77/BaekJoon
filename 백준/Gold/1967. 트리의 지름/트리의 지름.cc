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

vector<pair<int, int>>tree[10010];

pair<int, int> dfs(int start, int before)
{
	pair<int, int> node = { start, 0 };

	for (int i = 0; i < tree[start].size(); i++)
	{
		int cur = tree[start][i].first;
		int dist = tree[start][i].second;
		pair<int, int> buf;

		if (cur != before)
		{
			buf = dfs(cur, start);
			if (node.second < buf.second + dist)
			{
				node.first = buf.first;
				node.second = buf.second + dist;
			}
		}
	}

	return node;

}

int main()
{
	int n;
	int buf0, buf1, buf2;
	
	scanf("%d", &n);

	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d %d", &buf0, &buf1, &buf2);
		tree[buf0].push_back({ buf1, buf2 });
		tree[buf1].push_back({ buf0, buf2 });
	}

	int y = dfs(1, 0).first;

	
	int ans = dfs(y, 0).second;

	printf("%d", ans);
	
	return 0;
}
