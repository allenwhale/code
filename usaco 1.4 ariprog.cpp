/*
ID: allenwh1
PROG: ariprog
LANG: C++
*/
#include <string.h>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
int flag[250*250*2+10];
int a[250*250*2];
struct ans
{
	int a,b;
	ans(int ta,int tb)
	{
		a=ta,b=tb;
	}
	bool operator<(const ans &n)const
	{
		if(b>n.b)return true;
		else if(b==n.b)
		{
			if(a>n.a)return true;
			return false;
		}
		return false;
	}
};
int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	int n,m,size=0;
	memset(flag,false,sizeof(flag));
	priority_queue<ans>pq;
	scanf("%d %d",&n,&m);
	int maxnum=m*m*2;
	for(int i=0;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			flag[i*i+j*j]=true;
		}
	}
	for(int i=0;i<=maxnum;i++)
	{
		if(flag[i])a[size++]=i;
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			int d=a[j]-a[i];;
			if(a[i]+(n-1)*d>maxnum)break;
			bool tf=true;
			for(int k=1;k<n-1&&tf;k++)
			{
				tf=flag[a[j]+k*d];
			}
			if(tf)pq.push(ans(a[i],d));
		}
	}
	if(pq.size()==0)printf("NONE\n");
	while(!pq.empty())
	{
		ans tmp=pq.top();
		pq.pop();
		printf("%d %d\n",tmp.a,tmp.b);
	}
    return 0;
}
