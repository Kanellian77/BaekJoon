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
int dr[3] = { -1, 0, 1 };
int dc[3] = { 1, 1, 1 };

bool dfs(int row, int col)
{
	//첫번째 col기준으로 depth를 정한다
	if (col == c - 1)
		return true;
	
	gmap[row][col] = 1;
	for (int i = 0; i < 3; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr >= 0 && nr < r && !gmap[nr][nc])
			if (dfs(nr, nc))
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