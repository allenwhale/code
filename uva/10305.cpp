#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
int main()
{
	int st,nd;
	int m,n,i;
	while(~scanf("%d %d",&n,&m))
	{
		if(n==m&&m==0)break;
		int num[110]={0};
		bool vis[110];
		memset(vis,true,sizeof(vis));
		deque<int>DQ[110];
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&st,&nd);		
			num[nd]++;
			DQ[st].push_back(nd);
		}
		int ans[110];
		for(i=0;i<n;i++)
		{
			int j;
			int now;
			for(j=1;j<=n;j++)
			{
				if(vis[j]&&num[j]==0)
				{
					now=j;
				}
			}
			vis[now]=false;
			ans[i]=now;
			int size=DQ[now].size();
			for(j=0;j<size;j++)
			{
				num[DQ[now][j]]--;	
			}
		}
		printf("%d",ans[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
    return 0;
}
