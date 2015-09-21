#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
bool tf[3000][3000],vis[3000];
char name[3000][5];
int last[3000];
int sn;
map<string,int>mp;
int find(char s[])
{
	if(mp.count(s)==0)
	{
		mp[s]=sn;
		strcpy(name[sn],s);
		sn++;
	}
	return mp[s];
}
void init()
{	
	sn=1;
	mp.clear();
	memset(tf,false,sizeof(tf));
	memset(vis,false,sizeof(vis));
	memset(last,0,sizeof(last));	
}
void ptans(int now)
{
	if(last[now]==0)
	{
		return;
	}
	ptans(last[now]);
	printf("%s %s\n",name[last[now]],name[now]);
}
int main()
{	
	int n,tt=0;
	char a[5],b[5];
	int i;
	int anum,bnum;
	int start,end;
	while(~scanf("%d",&n))
	{
		if(tt!=0)printf("\n");
		tt++;
		init();
		for(i=1;i<=n;i++)
		{
			scanf("%s %s",a,b);
			anum=find(a);
			bnum=find(b);
			tf[anum][bnum]=true;
			tf[bnum][anum]=true;
		}
		scanf("%s %s",a,b);
		//printf("%s %s",a,b);
		//printf("123");
		start=find(a);
		end=find(b);
		bool ans=false;
		vis[start]=true;
		queue<int> q;
		q.push(start);
		int u;
		while(!q.empty())
		{
			
			//printf("while");
			u=q.front();
			q.pop();
			if(u==end)
			{
				//printf("ok");
				ans=true;
				break;
			}
			for(i=1;i<sn;i++)
			{
				if(tf[u][i]==true && vis[i]==false)
				{
					vis[i]=true;
					last[i]=u;
					q.push(i);
					
				}			
			}
		}
		if(ans)
		{
			ptans(end);
		}
		else 
		{
			printf("No route\n");
		}
	}
    return 0;
}
