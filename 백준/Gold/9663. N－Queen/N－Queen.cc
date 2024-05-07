#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int chess[15];
int n;
int result = 0;

bool checker(int counter)
{
	for (int i = 0; i < counter; i++)
		if (chess[counter] == chess[i] || abs(chess[counter] - chess[i]) == counter - i)
			return false;
	return true;
}

void dfs( int counter )
{
	if (counter == n)
	{
		result++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		chess[counter] = i;
		if (checker(counter))
			dfs(counter + 1);
	}
}


int main()
{
	scanf("%d", &n);

	dfs(0);
	printf("%d", result);
	return 0;
}
