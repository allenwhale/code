#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>DQ[10010];
int s1[10010],s2[10010];
int num=0;
int dis[10010],low[10010];
int t=0;
bool vis[10010];
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void DFS(int x,int px)
{
	dis[x]=low[x]=++t;
	int i;
	int size=DQ[x].size();
	for(i=0;i<size;i++)
	{
		int tmp=DQ[x][i];
		if(tmp==px)continue;
		if(dis[tmp])low[x]=min(low[x],dis[tmp]);
		else 
		{
			DFS(tmp,x);
			low[x]=min(low[x],low[tmp]);
		}
	}
}
void allDFS(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!dis[i])DFS(i,i);
	}
}
bool find(int f,int t)
{
	int i;
	for(i=0;i<num;i++)
	{
		if((s1[i]==t&&s2[i]==f)||(s1[i]==f&&s2[i]==t))return true;
	}
	return false;
}
void bridge(int x,int px)
{
	vis[x]=true;
	int i;
	int size=DQ[x].size();
	for(i=0;i<size;i++)
	{
		int tmp=DQ[x][i];
		if(tmp==px||vis[tmp])continue;
		if(dis[x]<low[tmp])
		{
			if(x<tmp)s1[num]=x,s2[num]=tmp,num++;
			else s2[num]=x,s1[num]=tmp,num++;
		}
		bridge(tmp,x);
	}
}
void allbri(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!vis[i])bridge(i,i);
	}
}
void ss()
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(s1[i]>s1[j])
			{
				swap(&s1[i],&s1[j]);
				swap(&s2[i],&s2[j]);
			}
			else if(s1[i]==s1[j]&&s2[i]>s2[j])
			{
				swap(&s2[i],&s2[j]);
			}
		}
	}
}
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		DQ[i].clear();
	}
	num=0;
	t=0;
	memset(dis,0,sizeof(dis));
	memset(vis,false,sizeof(vis));
	memset(low,0,sizeof(low));
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
}
void all(int N)
{
	allDFS(N);
	allbri(N);
	ss();
}
int main()
{
	int N,i,j;
	int tt=0;
	while(~scanf("%d",&N))
	{
		init(N);
		for(i=0;i<N;i++)
		{
			int f;
			scanf("%d",&f);
			char s[30];
			scanf("%s",s);
			int n;
			sscanf(s,"(%d)",&n);
			for(j=1;j<=n;j++)
			{
				int t;
				scanf("%d",&t);
				DQ[f].push_back(t);
			}
		}
		all(N);
		//if(tt>0)printf("\n");
		//tt++;
		printf("%d critical links\n",num);
		for(i=0;i<num;i++)
		{
			printf("%d - %d\n",s1[i],s2[i]);
		}
		printf("\n");
	}
    return 0;
}
