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

int main()
{
	int cur = 0;
	string input;
	cin >> input;
	int len = input.length();
	while (cur< len)
	{
		if (input[cur] == '0')
		{
			// 01 체크
			if (cur + 1 < len && input[cur + 1] == '1')
			{
				cur += 2;
			}
			else
			{
				printf("NOISE\n");
				return 0;
			}
		}
		else
		{
			// 100 체크
			int zcnt = 0;
			while (cur < len && input[++cur] == '0') zcnt++;
			if (zcnt < 2 || cur == len)
			{
				printf("NOISE\n");
				return 0;
			}
			else
			{
				cur++;
				if (input[cur] == '1')
				{
					while (true)
					{
						if (cur >= len)
						{
							printf("NOISE\n");
							return 0;
						}
						if (input[cur] == '0')
							break;

						if (cur + 2 < len && input.substr(cur, 3) == "100")
							break;

						cur++;
					}
				}
			}
		}
	}

	printf("SUBMARINE\n");

	return 0;
}