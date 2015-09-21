/*
ID: allenwh1
PROG: clocks
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define FOR(x) for(s[x][0]=0;s[x][0]<4;s[x][0]++)
int now[10];
int s[10][10]={{0},{0,1,1,0,1,1,0,0,0,0},
	{0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,1,1,0,0,0},
	{0,1,0,0,1,0,0,1,0,0},
	{0,0,1,0,1,1,1,0,1,0},
	{0,0,0,1,0,0,1,0,0,1},
	{0,0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,1,1,1},
	{0,0,0,0,0,1,1,0,1,1}};
int min=1e9;
int ans[10];
int work[10];
bool ck()
{
	for(int i=1;i<10;i++)
	{
		if(work[i]!=0)return false;
	}
	return true;
}
int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	for(int i=1;i<10;i++)
	{
		scanf("%d",&now[i]);
		now[i]=(now[i]/3)%4;
	}
	FOR(1) FOR(2) FOR(3)
	FOR(4) FOR(5) FOR(6)
	FOR(7) FOR(8) FOR(9)
	{
		for(int i=1;i<10;i++)
		{
			int add=0;
			for(int j=1;j<10;j++)
			{
				add+=s[j][0]*s[j][i];
			}
			work[i]=(add+now[i])%4;
		}
		bool tf=ck();
		if(tf)
		{
			int cnt=0;
			for(int i=1;i<10;i++)
			{
				cnt+=s[i][0];
			}
			if(min>cnt)
			{
				min=cnt;
				for(int i=1;i<10;i++)
				{
					ans[i]=s[i][0];
				}
			}
		}
	}
	//printf("%d\n",min);
	for(int i=1;i<10;i++)
	{
		while(ans[i]--)
		{
			printf("%d%c",i,--min?' ':'\n');
		}
	}
	//while(1);
    return 0;
}
