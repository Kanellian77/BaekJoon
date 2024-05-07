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
	int k, n;
	string arr;
	string correct;
	map<string, int> visited;
	
	// n,k입력
	scanf("%d %d", &n, &k);

	
	// arr입력(correct라는 정답지도 만들어줌)
	for (int i = 1; i <= n; i++)
	{
		char buf1;
		scanf(" %c", &buf1);
		arr.push_back(buf1);
		correct.push_back(i + '0');
	}
	

	// bfs를 위한 arr큐
	queue<pair<string, int>> bfs;
	int depth = 0;
	bfs.push({ arr, depth });
	string start;
	string buf;
	char temp;
	int ans = -1;
	
	while(!bfs.empty())
	{
		// bfs에 프론트 배열을 복사해옴
		start = bfs.front().first;
		depth = bfs.front().second;
		// 실행중임으로 pop해줌
		bfs.pop();
		
		if (start == correct)
		{
			ans = depth;
			break;
		}

		for (int i = 0; i <= n-k; i++)
		{
			// buf에 현재 큐의 상태 배열을 복사해옴
			buf = start;
			// buf를 바꿔줌(큐에 넣기위해)
			for (int j = 0; j < k / 2; j++)
			{
				temp = buf[i + j];
				buf[i + j] = buf[i + k - 1 - j];
				buf[i + k - 1 - j] = temp;
			}
			
			
			if (visited.find(buf) == visited.end())
			{
				bfs.push({ buf, depth + 1 });
				visited.insert({ buf, depth + 1 });
			}
		}
	}
	
	
	if (visited.find(correct) != visited.end())
	{
		ans = visited.find(correct)->second;
	}
	
	printf("%d", ans);

	return 0;
}

