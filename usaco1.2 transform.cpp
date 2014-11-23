/*
ID: allenwh1
PROG: transform
LANG: C++	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
char pre[10][10],want[10][10],work[10][10];
int ans=1e9;
int N;
bool comp(int x)
{
	if(memcmp(want,work,sizeof(work))==0)ans=min(ans,x);
}
void t90()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[j][N-1-i]=pre[i][j];
		}
	}
	comp(1);
}
void t180()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[N-i-1][N-1-j]=pre[i][j];
		}
	}
	comp(2);
}
void t270()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[N-1-j][i]=pre[i][j];
		}
	}
	comp(3);
}
void rl()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[i][N-1-j]=pre[i][j];
		}
	}
	comp(4);
	char tmp[10][10];
	memcpy(tmp,work,sizeof(work));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[j][N-1-i]=tmp[i][j];
		}
	}
	comp(5);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[N-i-1][N-1-j]=tmp[i][j];
		}
	}
	comp(5);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			work[N-1-j][i]=tmp[i][j];
		}
	}
	comp(5);
}
void no()
{
	memcpy(work,pre,sizeof(pre));
	comp(6);	
}

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&N);
	//getchar();
	for(int i=0;i<N;i++)
	{
		scanf("%s",pre[i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%s",want[i]);
	}
	t90();
	t180();
	t270();
	rl();
	no();
	if(ans==1e9)printf("7\n");
	else printf("%d\n",ans);
	//memcpy(work,pre,sizeof(pre));
    return 0;
}
