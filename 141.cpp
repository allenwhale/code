#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
using namespace std;

int n;
int map[55][55];
char save[4][2555];
int x, y;
char c;
set<string> adj;
inline void sav()
{
	memset(save, 0 , sizeof(save));
	int t;
	t = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			save[0][t ++] = map[i][j] + '0';
		}
	save[0][t] = '\0';
	t = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			save[1][t ++] = map[j][n + 1 - i] + '0';
		}
	save[1][t] = '\0';
	t = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			save[2][t ++] = map[n + 1 - i][n + 1 - j] + '0';
		}
	save[2][t] = '\0';
	t = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			save[3][t ++] = map[n + 1 - j][i] + '0';
		}
	save[3][t] = '\0';
}
int main()
{
	while (~scanf("%d", &n) && n)
	{
		int judge = 0;
		int bu = 0;
		memset(map, 0 , sizeof(map));
		adj.clear();
		for(int i=0;i<2*n;i++)
		{
			scanf("%d %d %c",&x,&y,&c);
			if(c=='+')
				map[x][y]=1;
			if(c=='-')
				map[x][y]=0;
			sav();
			for(int j=0;j<4;j++)
			{
				if(adj.find(save[j])!=adj.end())
				{
					judge=1;
					break;
				}
			}
			for(int j=0;j<4;j++)
				adj.insert(save[j]);
			if(judge)
			{
				if(bu==0)
					bu=i+1;
			}
		}
		if (judge)
		{
			if (bu%2)
				printf("Player 2 wins on move %d\n",bu);
			else
				printf("Player 1 wins on move %d\n",bu);
		}
		else
			printf("Draw\n");
	}
	return 0;
}

