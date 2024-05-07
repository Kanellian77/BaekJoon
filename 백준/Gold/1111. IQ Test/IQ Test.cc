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

int main()
{
	int n;
	int arr[52] = {0};
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	

	if (n == 1)
	{
		printf("A\n");
	}
	else if (n == 2)
	{
		if (arr[0] == arr[1])
			printf("%d\n", arr[1]);
		else
			printf("A\n");
	}
	else
	{
		int a = arr[1] - arr[0] != 0 ? (arr[2] - arr[1]) / (arr[1] - arr[0]) : 0;

		int b = arr[1] - (a * arr[0]);
		bool checker = true;
		
		for (int i = 2; i < n; i++)
		{
			if (arr[i] != a * arr[i - 1] + b)
			{
				checker = false;
				break;
			}
		}

		if (!checker)
		{
			printf("B\n");
		}
		else
		{
			printf("%d", arr[n - 1] * a + b);
		}
	}
	
	
	return 0;
}

