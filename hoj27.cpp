#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int p[4][4];
int h()
{
	int res=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(p[i][j]==0)continue;
			res+=(abs((p[i][j]-1)/3-i)+abs((p[i][j]-1)%3-j));
		}
	}
	return res;
}
bool check()
{
	/*
	for(int i=0;i<3;i++,puts(""))
		for(int j=0;j<3;j++)
			printf("%d ",p[i][j]);
	puts("");
	system("pause");
	*/
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			//printf("%d ",p[i][j]);
			if(i==2&&j==2)continue;
			if((p[i][j]-1)!=3*i+j)return false;
		}
		//puts("");
	}
	//puts("");
	//system("pause");
	return true;
}
bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<3&&y<3;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool tf=false;
void dfs(int d,int l)
{
	//printf("%d\n",d);
	if(d>20)return;
	if(check())
	{
		tf=true;
		return ;
	}
	if(d+h()>20)return;	
	int px=-1,py=-1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(p[i][j]==0)px=i,py=j;
		}
	}
	for(int i=0;i<4&&!tf;i++)
	{
		if(i==(l^1))continue;
		int tx=px+dx[i],ty=py+dy[i];
		if(isin(tx,ty))
		{
			swap(p[tx][ty],p[px][py]);
			dfs(d+1,i);
			swap(p[tx][ty],p[px][py]);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&p[i][j]);
			}
		}
		tf=false;
		dfs(0,-1);
		if(tf)puts("Easy");
		else puts("Hard");
	}
	return 0;
}

