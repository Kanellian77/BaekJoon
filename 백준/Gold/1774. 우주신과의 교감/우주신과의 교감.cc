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


vector<pair<int, int>> node(1010);
double dist[1010][1010];
bool visited[1010];


double calcDist(pair<int, int> a, pair<int, int> b)
{
	double result = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
	return sqrt(result);
}

void setDist(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				dist[i][j] = calcDist(node[i], node[j]);

		}

}
int main()
{
	
	int n, m;
	scanf("%d %d", &n, &m);
	int bufx, bufy;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		node[i] = { bufx, bufy };
	}

	setDist(n);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &bufx, &bufy);
		dist[bufx][bufy] = 0;
		dist[bufy][bufx] = 0;
	}
	

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> prim;
	prim.push({ 0, 1 });
	
	double ans = 0;

	while (!prim.empty())
	{
		int curnode = prim.top().second;
		double curdist = prim.top().first;
		prim.pop();

		if (visited[curnode])
			continue;

		visited[curnode] = true;
		ans += curdist;

		for (int i = 1; i <= n; i++)
		{
			if (curnode == i)
				continue;

			if (!visited[i])
				prim.push({ dist[curnode][i], i });
			
		}
	}

	printf("%.2lf\n", ans);
}
