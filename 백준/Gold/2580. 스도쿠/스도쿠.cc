#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int Mdepth;
vector<pair<int, int>> zeroPoint;
int pann[50][50];//row col

bool dfs(int depth)
{
	bool ishere = false;
	if (depth == Mdepth)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d ", pann[i][j]);
			printf("\n");
		}
		return true;
	}

	int i = zeroPoint[depth].first;
	int j = zeroPoint[depth].second;
	
	if (pann[i][j] == 0)
		for (int c = 1; c <= 9; c++)
		{
			ishere = false;
			for (int a = 0; a < 9; a++)
				if (pann[a][j] == c || pann[i][a] == c)// 가로세로검사
				{
					ishere = true;
					break;
				}
					
			int ansi = i / 3;
			int ansj = j / 3;
			for (int a = 0; a < 3; a++)
				for (int b = 0; b < 3; b++)
					if (pann[ansi * 3 + a][ansj * 3 + b] == c)
						ishere = true;

			if (!ishere)
			{
				pann[i][j] = c;
				if (dfs(depth + 1))
					return true;
				pann[i][j] = 0;
			}
		}

	return false;
	
}

int main(void)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &pann[i][j]);
			if (pann[i][j] == 0)
			{
				Mdepth++;
				zeroPoint.push_back({ i,j });
			}
		}
	dfs(0);
	return 0;
}