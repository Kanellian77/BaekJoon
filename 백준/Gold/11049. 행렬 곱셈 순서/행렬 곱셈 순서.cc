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

int dp[510][510];
vector<pair<int, int>>arr;



int depth(int start, int end)
{
	if(start == end) return 0;
	
	if (dp[start][end] != 0) return dp[start][end];

	int quotient = infinity;

	for (int i = start; i < end; i++)
	{
		quotient = min(quotient, depth(start, i) + depth(i + 1, end) + arr[start].first * arr[i].second * arr[end].second);
	}
	
	dp[start][end] = quotient;
	return quotient;
}

int main()
{
	int n;
	scanf("%d", &n);
	int buf0, buf1;
	// 앞에 것을 기준으로
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &buf0, &buf1);
		arr.push_back({ buf0, buf1 });
	}
	memset(dp, 0, sizeof(dp));
	printf("%d", depth(0, n - 1));
	
	return 0;
}