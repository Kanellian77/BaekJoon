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

#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

int number[26];

int main()
{
	int n; 
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		char buf[10];
		scanf("%s", buf);
		for (int i = strlen(buf); i >=0 ; i--)
		{
			number[buf[i] - 'A'] += pow(10, strlen(buf)-i-1);
		}
	}

	sort(number, number + 26, greater<>());

	int buf = 9;
	int ans = 0;
	for (int i = 0; i < 10 ; i++)
	{
		ans += number[i] * (buf--);
	}

	printf("%d", ans);
	
	

	return 0;
}

