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
pair<int, int> graph[200010];
int graphrank[200010];
map<string, int> numchanger;



int findparent(int a)
{
	if (graph[a].first == a) return a;
	return graph[a].first = findparent(graph[a].first);
}

void change(int a, int b)
{
	int parenta = findparent(a);
	int parentb = findparent(b);

	if (parenta == parentb) return;

	if (graphrank[parenta] >= graphrank[parentb])
	{
		graph[parentb].first = parenta;
		graph[parenta].second += graph[parentb].second;
	}
	else
	{
		graph[parenta].first = parentb;
		graph[parentb].second += graph[parenta].second;
	}

	if (graphrank[parenta] == graphrank[parentb])
		graphrank[parenta] += 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, m;
	cin >> t;

	while (t--)
	{
		cin >> m;
		string p[2];
		numchanger.clear();
		for (int i = 0; i <= 200000; i++)
		{
			graph[i].first = i;
			graph[i].second = 1;
			graphrank[i] = 0;
		}
		

		for (int i = 0; i < m; i++)
		{
			cin >> p[0] >> p[1];
			for (int j = 0; j < 2; j++)
			{
				if (numchanger.find(p[j]) == numchanger.end());
				{
					numchanger.insert({ p[j], numchanger.size()});
				}
			}

			change(numchanger.find(p[0])->second, numchanger.find(p[1])->second);
			cout << graph[findparent(numchanger.find(p[0])->second)].second << '\n';
			
		}
	}
	
	return 0;
}
