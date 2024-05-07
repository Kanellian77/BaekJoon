#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <stack>

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

// b배열에서 a와 작거나 같은 숫자의 갯수
ll GetNum(ll n, ll a)
{
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += min(n, a / i);
	}
	return cnt;
}


int main()
{
	ll n, k;
	scanf("%lld", &n);
	scanf("%lld", &k);


	ll start = 1;
	ll end = n * n;
	ll ans = 0;
	bool check = false;
	while (1)
	{
		//(15=14=13=12)
		ll mid = (start + end) / 2;
		
		ll cur = GetNum(n, mid);
		ll curmin = GetNum(n, mid - 1);

		if (cur < k)
		{
			if (cur > curmin && curmin< k && k <= cur)
			{
				ans = mid;
				check = true;
				break;
			}
			else
			{
				start = mid+1;
			}
		}
		else if(cur > k)
		{
			if (cur > curmin && curmin < k && k <= cur)
			{
				ans = mid;
				check = true;
				break;
			}
			else
			{
				end = mid-1;
			}
		}
		else
		{
			ans = mid;
			break;
		}
	}

	if (!check)
	{
		while (true)
		{
			ll num1 = GetNum(n, ans);
			ll num2 = GetNum(n, ans - 1);
			if (num1 == num2)
				ans--;
			else
				break;
			
		}
	}
	
	printf("%lld", ans);
	
	
	return 0;
}