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

int n, m;
int graph[1000010];
int graphrank[1000010];


void graphinit()
{
	for (int i = 0; i <= 1000000; i++)
	{
		graph[i] = i;
		graphrank[i] = 0;
	}
}

int findparent(int a)
{
	if (graph[a] == a) return a;
	return graph[a] = findparent(graph[a]);
}

void change(int a, int b)
{
	int parenta = findparent(a);
	int parentb = findparent(b);

	if (parenta == parentb) return;

	if (graphrank[parenta] >= graphrank[parentb])
	{
		graph[parentb] = parenta;
	}
	else
	{
		graph[parenta] = parentb;
	}

	if (graphrank[parenta] == graphrank[parentb])
		graphrank[parenta] += 1;
}

int main()
{
	
	
	int n, m;

	scanf("%d %d", &n, &m);
	
	graphinit();
	
	int a, b;
	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (findparent(a) == findparent(b) && ans == 0)
		{
			ans = i + 1;
		}
		change(a, b);
	}
	printf("%d\n", ans);
	return 0;
}
