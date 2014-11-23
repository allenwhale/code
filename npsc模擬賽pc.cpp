#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
bool mp[1010][1010];
int chp[1010];
int N;
void init()
{
	memset(chp,-1,sizeof(chp));
	memset(mp,false,sizeof(mp));
}
bool BFS(int s)
{
	if(chp[s]==1)return true;
	else if(chp[s]==0)return false;
	queue<int>q;
	bool vis[1010];
	int vn=0;
	memset(vis,false,sizeof(vis));
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		vn++;
		//printf(" %d\n",t);
		for(int i=0;i<N;i++)
		{
			if(i==t||vis[i])continue;
			if(mp[t][i])
			{
				if(chp[i]==1)return true;
				vis[i]=true;
				q.push(i);
			}
			else 
			{
				if(chp[i]==0)return false;
			}
		}
	}
	if(vn==N)return true;
	else return false;
}
int main()
{
	while(~scanf("%d%*c",&N)&&N)
	{
		//getchar();
		init();
		for(int i=0;i<N;i++)
		{
			char tmp[1010];
			gets(tmp);
			for(int j=i+1;j<N;j++)
			{
				if(tmp[j-i-1]=='1')
				{
					mp[i][j]=true;
				}
				else
				{
					mp[j][i]=true;
				}
			}
		}
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(BFS(i))
			{
				chp[i]=1;
				ans++;
			}
			else chp[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}

