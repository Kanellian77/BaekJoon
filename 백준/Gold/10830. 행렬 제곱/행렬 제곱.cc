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

int n;
vector<vector<int>> inito;

vector<vector<int>> multi(vector<vector<int>>a, vector<vector<int>>b)
{
	vector<vector<int>> obj(n, vector<int>(n, 0));
	for (int N = 0; N < n; N++)
		for (int M = 0; M < n; M++)
			for (int K = 0; K < n; K++)
				obj[N][M] += (a[N][K] * b[K][M]) % 1000;
	
	return obj;
}

vector<vector<int>> dp(ll obj)
{
	if (obj == 1) return inito;
	

	vector<vector<int>> arr = dp(obj / 2);

	if (obj % 2 != 1)
	{
		return multi(arr, arr);
	}
	else
	{
		return multi(multi(arr, arr), inito);
	}
	
}
int main()
{
	ll m;
	scanf("%d %lld", &n, &m);
	inito.assign(n, {});
	for (int i = 0; i < n; i++)
	{
		inito[i].assign(n, 0);
		for (int j = 0; j < n; j++)
			scanf("%d", &inito[i][j]);
	
	}

	vector<vector<int>> answer = dp(m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", answer[i][j] % 1000);
		}
		printf("\n");
	}

	return 0;
}