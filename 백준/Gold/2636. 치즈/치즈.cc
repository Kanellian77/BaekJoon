#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int Mdepth;
int pann[100][100];//row col
bool visited[100][100];
int m, n;
int check[4][2] = {
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1}};
int lastChese = 0;

bool checkAir()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (pann[i][j] == 1)
				return false;
		
	return true;
}
void melting()
{
	int remainChese = 0;
	int chese = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{	
			if (pann[i][j] == 1)
				chese += 1;
			else if (pann[i][j] == 2)
			{
				remainChese += 1;
				pann[i][j] = 0;
			}
		}
	if (chese + remainChese == remainChese)
		lastChese = remainChese;
		
}
void visitedset()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (pann[i][j] == 1)
				visited[i][j] = true;
			else if (pann[i][j] == 0)
				visited[i][j] = false;
		}
}
bool dfs(int depth)
{

	melting();
	visitedset();
	if (checkAir())
	{
		printf("%d\n", depth);
		printf("%d", lastChese);
		return true;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (pann[i][j] == 0)
			{
				queue<pair<int, int>> Air;
				Air.push({ i,j });
				visited[i][j] = true;

				while (!Air.empty())
				{
					pair<int, int> Cur;
					Cur.first = Air.front().first;
					Cur.second = Air.front().second;
					Air.pop();
					for (int c = 0; c < 4; c++)
					{
						int row = Cur.first + check[c][0];
						int col = Cur.second + check[c][1];
						if (0 <= row && row <= m && 0 <= col && col <= n)
						{
							// 공기일때
							if (pann[row][col] == 0 && !visited[row][col])
							{
								Air.push({ row, col });
								visited[row][col] = true;
							}
							//치즈일때(얘는 외각일꺼임~)
							else if (pann[row][col] == 1)
								pann[row][col] = 2;
						}
					}
				}
				if (dfs(depth + 1))
					return true;
			}
		}
	
	return false;
	
}

int main(void)
{
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &pann[i][j]);

	dfs(0);
	return 0;
}