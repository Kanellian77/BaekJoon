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

priority_queue<int, vector<int>, greater<>> card;

int main()
{
	int n;
	int buf, buf1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buf);
		card.push(buf);
	}
	
	int ans = 0;
	
	while (card.size() > 1)
	{
		buf = card.top();
		card.pop();
		buf1 = card.top();
		card.pop();

		ans += buf + buf1;
		card.push(buf + buf1);
	}
		
	
	printf("%d", ans);
}

