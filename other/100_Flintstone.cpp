#include <stdio.h>
#include <stdlib.h> 
#include <algorithm>
using namespace std;
#define min(a,b) (a<b?a:b)
int p[100010];
int Find(int x)
{
	return (x==p[x])?x:p[x]=Find(p[x]);
}
int R,N;
int Union(int a,int b)
{
	p[Find(a)]=Find(b);
}

struct Bomb
{
	int x,y,c,num;	 
}b[100010];
bool cmpx(Bomb a,Bomb b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
bool cmpy(Bomb a,Bomb b)
{
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}
int mn[100010];
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		p[i]=i;
		mn[i]=999999;
	}
	return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		
		scanf("%d %d",&N,&R);
		init(N);
		for(int j=0;j<N;j++)
		{
			scanf("%d %d %d",&b[j].x,&b[j].y,&b[j].c);
			b[j].num=j;
		}
		sort(b,b+N,cmpy);
		for(int j=0;j<N-1;j++)
		{
			if(b[j].y==b[j+1].y)
			{
				//printf("  %d %d\n",b[j].x,b[j+1].x);
				if(abs(b[j].x-b[j+1].x)<=R)
				{
					Union(b[j].num,b[j+1].num);
				}
			}
		}
		sort(b,b+N,cmpx);
		for(int j=0;j<N-1;j++)
		{
			if(b[j].x==b[j+1].x)
			{
				//printf("  %d %d\n",b[j].y,b[j+1].y);
				if(abs(b[j].y-b[j+1].y)<=R)
				{
					
					Union(b[j].num,b[j+1].num);
				}
			}
		}
		for(int j=0;j<N;j++)
		{
			//printf(" %d %d\n",Find(j),b[j].c);
			int ff=Find(b[j].num);
			mn[ff]=min(mn[ff],b[j].c);
		}
		int ans=0;
		for(int j=0;j<N;j++)
		{
			//printf(" %d %d\n",mn[j],p[j]);
			if(mn[j]!=999999)
			{
				ans+=mn[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

