#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Peo
{
	int p,m,num;
	Peo(){}
	bool operator <(const Peo &n)const
	{
		if(n.p==p)
		{
			return n.m<m;
		}
		return n.p>p;
	}	
}s[100010];
int btree[2000010];
int maxv;
int ans[100010];
void init()
{
	maxv=0;
	memset(btree,0,sizeof(btree));
	memset(s,0,sizeof(s));
}
void add(int v)
{
	while(v<=maxv)
	{
		btree[v]++;
		v+=v&(-v);
	}
}
int sum(int x)
{
	int tans=0;
	while(x>0)
	{
		tans+=btree[x];
		x-=x&(-x);
		//if(x==0)break;
	}
	return tans;
}
int main()
{
	int t;
	int T=0;
	scanf("%d",&t);
	while(t--)
	{
		int N;
		scanf("%d",&N);
		init();
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&s[i].p,&s[i].m);
			s[i].m+=1000010;
			s[i].num=i;
			maxv=max(maxv,s[i].m);
		}
		//printf("%d\n",maxv);
		sort(s,s+N);
		printf("Case #%d:\n",++T);
		for(int i=0;i<N;i++)
		{
			add(s[i].m);
			ans[s[i].num]=sum(s[i].m-1);
		}
		for(int i=0;i<N;i++)
		{
			printf("%d\n",ans[i]);
		}
		if(t!=0)puts("");
	}
	return 0;
}

