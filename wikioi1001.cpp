#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct E
{
	int a,b,v;
}e[5010];
int p[510];
void init()
{
	for(int i=0;i<=500;i++)p[i]=i;
}
int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b)
{
	p[find(b)]=find(a);
}
int N,M;
bool cmp(E a,E b)
{
	return a.v>b.v;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].v);
	}
	int s,t;
	scanf("%d %d",&s,&t);
	sort(e,e+M,cmp);
	double mn_ans=1e9;
	int mx=0,mn=0;
	for(int i=0;i<M;i++)
	{
		init();
		for(int j=0;j<M;j++)
		{
			if(e[j].v<=e[i].v&&find(e[j].a)!=find(e[j].b))
			{
				U(e[j].a,e[j].b);
			}
			if(find(s)==find(t))
			{
				if((double)e[i].v/(double)e[j].v<mn_ans)
				{
					mn_ans=(double)e[i].v/(double)e[j].v;
					mn=e[j].v,mx=e[i].v;
				}
			}
		}
	}
	if(fabs(mn_ans-1e9)<1e-8)puts("IMPOSSIBLE");
	else if(mx%mn==0)printf("%d\n",mx/mn);
	else printf("%d/%d\n",mx/__gcd(mx,mn),mn/__gcd(mx,mn));
	return 0;
}
