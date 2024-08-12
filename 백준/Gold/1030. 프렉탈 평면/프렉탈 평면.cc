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
/// <summary>

int s, n, k;

int find(int precolor, int x, int y)
{
	int rx = x % n;
	int ry = y % n;

	if (precolor == 1)
		return 1;
	
	if (((n - k) / 2 <= rx && (n - k) / 2 + k > rx) &&
		((n - k) / 2 <= ry && (n - k) / 2 + k > ry))
		return 1;

	return 0;
}

int colordetect(int t, int x, int y)
{
	int rx = x/n;
	int ry = y/n;

	if (t != 1)
	{
		return find(colordetect(t-1, rx, ry), x, y);
	}
	else
	{
		return find(0, x, y);
	}

}


int main()
{
	
	int r1, r2, c1, c2;
	scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
	
	if (s == 0)
	{
		printf("0");
		return 0;
	}

	for (int y = r1; y <= r2; y++)
	{
		for (int x = c1; x <= c2; x++)
			printf("%d", find(colordetect(s, x, y), x, y));
		
		printf("\n");
	}

	return 0;
}