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

int main()
{
	int x, y;
	int w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int xmin, ymin;
	// w/2보다 큰지 아닌지 확인
	xmin = (x > w / 2) ? w - x : x;
	ymin = (y > h / 2) ? h - y : y;
	int ans = min(xmin, ymin);
	printf("%d", ans);

	return 0;
}