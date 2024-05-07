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
	
	
	int n;

	scanf("%d", &n);

	int m;
	scanf("%d", &m);
	
	
	
	graphinit();
	
	int buf;
	

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &buf);
			if (buf == 1)
			{
				change(i, j);
			}
		}

	int a[1010];

	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	
	if (m == 1)
	{
		printf("YES");
		return 0;
	}
	
	bool ans = true;
	
	for (int i = 1; i < m; i++)
		if (findparent(a[i - 1]) != findparent(a[i]))
			ans = false;
	
	if (ans)
	{
		printf("YES");
		return 0;
	}
	printf("NO");
	
	return 0;
}
