#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <bits/stdc++.h>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
int n, m;
int arr[1000010];
ll sum[1000010];
vector<ll>mcount[1010];
ll ans = 0;
int main(void)
{
	
	scanf("%d %d", &n, &m );
	mcount[0].push_back({ 0 });
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		sum[i] = (sum[i - 1] + arr[i]) % m;
		mcount[sum[i]].push_back({ i });
	}

	for (int i = 0; i <= m; i++)
	{
		if (mcount[i].size() >= 2)
			ans += (pow(mcount[i].size(), 2) - mcount[i].size()) / 2;
	}
	printf("%lld", ans);
	return 0;
}