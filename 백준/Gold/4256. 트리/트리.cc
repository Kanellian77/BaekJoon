#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

int n;
int nodeCnt;
int prearr[1010];
int midarr[1010];
int mididx[1010];
int bTree[1010][2];
//0 왼쪽자식 -1
//1 오른쪽자식 -1


void makeTree(int ps, int pe, int ms, int md)
{
	int root = prearr[ps];
	int mridx = mididx[root];
	int prelstart, prerstart, prelend, prerend;
	int mlstart, mrstart, mlend, mrend;

	mlstart = ms;
	mlend = mridx - 1;
	mrstart = mridx + 1;
	mrend = md;

	int leftcnt = mridx - ms;
	
	prelstart = ps + 1;
	prelend = leftcnt + ps;
	prerstart = prelend + 1;
	prerend = pe;

	if (prelstart <= prelend)
	{
		bTree[root][0] = prearr[prelstart];
		makeTree(prelstart, prelend, mlstart, mlend);
	}
	if (prerstart <= prerend)
	{
		bTree[root][1] = prearr[prerstart];
		makeTree(prerstart, prerend, mrstart, mrend);
	}
}

void postorder(int rootvalue)
{
	if (bTree[rootvalue][0] != 0)
		postorder(bTree[rootvalue][0]);
	if (bTree[rootvalue][1] != 0)
		postorder(bTree[rootvalue][1]);

	printf("%d ", rootvalue);

}

int main(void)
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &nodeCnt);
		for (int i = 0; i < nodeCnt; i++)
		{
			scanf("%d", &prearr[i]);
			bTree[i+1][0] = bTree[i+1][1] = 0;
		}
		for (int i = 0; i < nodeCnt; i++)
		{
			scanf("%d", &midarr[i]);
			mididx[midarr[i]] = i;
		}
		makeTree(0, nodeCnt - 1, 0, nodeCnt - 1);
		postorder(prearr[0]);
		printf("\n");
	}
	
	
	return 0;
}