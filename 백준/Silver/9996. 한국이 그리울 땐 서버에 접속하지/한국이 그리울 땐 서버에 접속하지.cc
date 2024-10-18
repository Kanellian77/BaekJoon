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

int arr[1010];
int dp[1010];

int main()
{
	int n;
	string a, b;
	string buf;
	scanf("%d", &n);
	cin >> buf;
	a = buf.substr(0, buf.find('*'));
	b = buf.substr(buf.find('*') + 1, buf.length());

	while (n--)
	{
		string str;
		cin >> str;
		
		if ( a.length() + b.length() <= str.length() &&
			a.compare(str.substr(0, a.length())) == 0 &&
			b.compare(str.substr(str.length() - b.length(), str.length()))== 0)
		{
			printf("DA\n");
		}
		else
		{
			printf("NE\n");
		}
	}
	
	return 0;
}