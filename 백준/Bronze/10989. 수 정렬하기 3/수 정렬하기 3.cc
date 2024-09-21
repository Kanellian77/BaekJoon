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

int sorting[10010];

int main()
{
	int n;
	scanf("%d", &n);
	
	int buf;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buf);
		sorting[buf]++;
	}

	for (int i = 0; i <= 10000; i++)
		for (int j = 0; j < sorting[i]; j++)
			printf("%d\n", i);
	
	return 0;
}