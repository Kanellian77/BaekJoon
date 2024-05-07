#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;


int main()
{
	int testcase;
	int tcnt = 0;
	scanf("%d", &testcase);
	
	while (tcnt < testcase)
	{
		int dot, line;
		scanf("%d %d", &dot, &line);
		
		vector<int> edge[20010];
		bool visited[20010];
		int buf0, buf1;

		for (int i = 0; i < line; i++)
		{
			scanf("%d %d", &buf0, &buf1);
			edge[buf0].push_back(buf1);
			edge[buf1].push_back(buf0);
		}

		for (int i = 1; i <= dot; i++)
		{
			sort(edge[i].begin(), edge[i].end());
			visited[i] = false;
		}

		set<int> red;
		set<int> blue;
		queue<pair<int, bool>>bfs;
		bool isBinary = true;
		bool isRed = true;

		for (int start = 1; start <= dot; start++)
		{
			if (visited[start])
				continue;

			
			visited[start] = true;
			bfs.push({ start, isRed });
			if (isRed)
				red.insert(start);
			else
				blue.insert(start);

			while (!bfs.empty())
			{
				start = bfs.front().first;
				isRed = bfs.front().second;
				bfs.pop();

				for (int i = 0; i < edge[start].size(); i++)
				{
					if (!visited[edge[start][i]])
					{
						visited[edge[start][i]] = true;
						bfs.push({ edge[start][i], !isRed });
					}

					if (isRed)
					{
						if (red.find(edge[start][i]) != red.end())
						{
							isBinary = false;
							break;
						}
						blue.insert(edge[start][i]);
					}
					else
					{
						if (blue.find(edge[start][i]) != blue.end())
						{
							isBinary = false;
							break;
						}
						red.insert(edge[start][i]);
					}

				}
				if (!isBinary)
					break;
			}
			if (!isBinary)
				break;
		}
	
		printf("%s\n", isBinary ? "YES" : "NO");
		tcnt++;
	}

	return 0;
}