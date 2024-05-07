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

ll n, c;
vector<ll> stuff;
vector<ll> leftanssum;
vector<ll> rightanssum;

void dfs(int depth, vector<bool> state, int object)
{
	if (depth == object)
	{
		if (object != n)
		{
			ll sum = 0;
			for (int i = 0; i < state.size(); i++)
				if (state[i])
					sum += stuff[i];
			leftanssum.push_back(sum);
		}
		else
		{
			ll sum = 0;
			for (int i = 0; i < state.size(); i++)
				if (state[i])
					sum += stuff[i+n/2];
			rightanssum.push_back(sum);
		}
		return;
	}

	vector<bool> yes = state;
	vector<bool> no = state;
	yes.push_back(true);
	no.push_back(false);
	dfs(depth + 1, yes, object);
	dfs(depth + 1, no, object);
}

int main()
{
	
	ll bufinput;
	scanf("%lld %lld", &n, &c);
	
	
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &bufinput);
		stuff.push_back(bufinput);
	}
	

	dfs(0, {}, n / 2);
	dfs(n / 2, {}, n);
	sort(leftanssum.begin(), leftanssum.end());
	sort(rightanssum.begin(), rightanssum.end());
	
	int cnt = 0;
	
	for (int i = 0; i < leftanssum.size(); i++)
	{
		int upperkey = upper_bound(rightanssum.begin(), rightanssum.end(), c - leftanssum[i]) - rightanssum.begin();
		cnt += upperkey;
	}

	printf("%d", cnt);
}
