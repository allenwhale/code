#include <stdio.h>
#include <string.h>
#include <queue>
int N,M;
struct Edge
{
	int a,b,c;
	Edge(int _a,int _b,int _c)
	{
		a=_a,b=_b,c=_c;
	}
	Edge(){}
}e[300];
int d[200];
int cnt[110];
int en=0;
void init()
{
	en=0;
	memset(d,0x3f,sizeof(d));
}
void add(int f,int t,int w)
{
	e[en++]=Edge(f,t,w);
}
bool BF(bool tf)
{
	for(int i=0;i<=N+1;i++)
	{
		for(int j=0;j<en;j++)
		{
			int f=e[j].a,t=e[j].b,w=e[j].c;
			if(d[t]>d[f]+w)
			{
				if(tf)return false;
				d[t]=d[f]+w;
			}
		}
	}
	return true;
}
bool neg1()
{
	BF(false);
	return BF(true);
}

int main()
{
	while(~scanf("%d",&N)&&N)
	{
		init();
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int f,l,k;
			char o[5];
			scanf("%d %d %s %d",&f,&l,o,&k);
			if(o[0]=='g')
			{
				add(f-1,f+l,-(k+1));
			}
			else
			{
				add(f+l,f-1,k-1);
			}
		}
		for(int i=0;i<=N;i++)
		{
			add(N+1,i,0);
		}
		BF(false);
		if(!BF(true))
		{
			puts("successful conspiracy");
		}
		else
		{
			puts("lamentable kingdom");
		}
	}
	return 0;
}
