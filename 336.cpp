#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<int,int> mp_1;
int last[1000];
int sn_1=0,sn_2=0;
bool tf[500][500],vis[500];
void init_1()
{
	sn_1=1;
	mp_1.clear();
	memset(tf,false,sizeof(tf));
	
}
void init_2()
{
	memset(vis,false,sizeof(vis));	
}
int find_1(int s)
{
	if(mp_1.count(s)==0)
	{
		mp_1[s]=sn_1;
		sn_1++;
	}	
	return mp_1[s];
}
int main()
{
	int num=0;
	int n;
	int ta,tb,a,b,start;
	int i,j;
	int ttl;
	int u;
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		init_1();
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			ta=find_1(a);
			tb=find_1(b);
			tf[ta][tb]=true;
			tf[tb][ta]=true;	
		}
		while(1)
		{
			int p_1,p_2,nodes=1;
			int st;
			init_2();
			scanf("%d %d",&start,&ttl);
			if(start==ttl&&ttl==0)break;
			queue<int> Q;
			Q.push(find_1(start));
			vis[find_1(start)]=true;
			p_2=1;
			p_1=0;
			last[p_1]=0;
			while(last[p_1]<ttl && !Q.empty())
			{
				u=Q.front();
				Q.pop();
				for(j=0;j<sn_1;j++)
				{
					if(tf[u][j]==true&&vis[j]==false)
					{
						Q.push(j);
						nodes++;
						vis[j]=true;
						last[p_2]=last[p_1]+1;
						p_2++;	
					}
				}
				p_1++;	
			}
			num++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",num,sn_1-nodes-1,start,ttl);
		}
	}
    return 0;
}
