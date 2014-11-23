#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <map>
#include <string.h>
using namespace std;
deque<int>DQ[1000];
queue<int>Q;
map<int,int>mp;
int sn;
bool vis[1000];
int find(int n)
{
	if(mp.count(n)==0)
	{
		mp[n]=sn;
		sn++;
	}
	return mp[n];
}
void init()
{
	sn=0;
	while(!Q.empty())
	{
		Q.pop();
	}
	mp.clear();
	memset(vis,false,sizeof(vis));
	int i;
	for(i=0;i<1000;i++)
	{
		DQ[i].clear();
	}
}
void BFS()
{
	int i;
	int size=DQ[0].size();
	vis[0]=true;
	for(i=0;i<size;i++)
	{
		Q.push(DQ[0][i]);
		vis[DQ[0][i]]=true;
	}
	while(!Q.empty())
	{
		int t=Q.front();
		Q.pop();
		size=DQ[t].size();
		for(i=0;i<size;i++)
		{
			if(!vis[DQ[t][i]])
			{
				vis[DQ[t][i]]=true;;
				Q.push(DQ[t][i]);
			}
		}
	}
}
int main()
{
	int num=0,i;
	while(1)
	{
		num++;
		init();
		int fr,to;
		bool tf=true;
		int r=0;
		bool tt=false;
		while(scanf("%d %d",&fr,&to))
		{
			if(fr<0&&to<0)
			{
				//printf("ddd");
				tf=false;
				break;
			}
			else if(fr==0&&to==0)break;
			tt=true;
			int f=find(fr),t=find(to);
			DQ[f].push_back(t);
			DQ[t].push_back(f);
			r++;
		}
		if(!tf)break;
		if(!tt)
		{
			printf("Case %d is a tree.\n",num);
			continue;
		}
		
		//printf("n%d r%d\n",sn,r);
		BFS();
		int tree=sn-r;
		bool tree1;
		if(tree==1)tree1=true;
		else tree1=false;
		bool tree2=true;
		for(i=0;i<sn;i++)
		{
			if(!vis[i])
			{
				//printf("%d\n",i);
				tree2=false;
				break;
			}
		}
		if(tree1&&tree2)
		{
			printf("Case %d is a tree.\n",num);
		}
		else
		{
			printf("Case %d is not a tree.\n",num);
		}
	}
    return 0;
}
