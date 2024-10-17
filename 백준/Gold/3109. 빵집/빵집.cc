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

#define infinity 125000000;
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

int r, c;
int gmap[10010][510];

bool dfs(int row, int col)
{
	gmap[row][col] = 1;
	//첫번째 col기준으로 depth를 정한다
	if (col == c - 1)
		return true;

	// 1우선순위 오른쪽 위로 이동
	if (row - 1 >= 0 && gmap[row - 1][col + 1] != 1)
	{
		if (dfs(row - 1, col + 1))
			return true;
	}
	if (gmap[row][col + 1] != 1)
	{
		if (dfs(row, col + 1))
			return true;
	}
	if (row + 1 < r && gmap[row + 1][col + 1] != 1)
	{
		if (dfs(row + 1, col + 1))
			return true;
	}
	
	return false;
}
int main()
{
	int answer = 0;
	char buf;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			scanf(" %c", &buf);
			if (buf == '.')
			{
				gmap[i][j] = 0;
			}
			else
			{
				gmap[i][j] = 1;
			}
		}

	for (int i = 0; i < r; i++)
		if (dfs(i, 0))
			answer++;


	printf("%d", answer);
	return 0;
}