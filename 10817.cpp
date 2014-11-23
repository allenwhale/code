#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int S,M,N;
vector<int>vc[110];
int P[111];
int dp[(1<<8)+10][(1<<8)+10];
void add(int &s1,int &s2,int k)
{
	if((s1&(1<<k))==0)s1|=(1<<k);
	else s2|=(1<<k);
}
int main()
{
	while(~scanf("%d %d %d%*c",&S,&M,&N)&&S)
	{
		int s1,s2;
		s1=s2=0;
		int ans=0;
		for(int i=0;i<M;i++)
		{
			char tmp[1000];
			gets(tmp);
			char *ptr=strtok(tmp," ");
			int c;
			sscanf(ptr,"%d",&c);ans+=c;
			ptr=strtok(NULL," ");
			while(ptr!=NULL)
			{
				int idx;
				sscanf(ptr,"%d",&idx);idx--;
				add(s1,s2,idx);
				ptr=strtok(NULL," ");
			}
		}
		for(int i=0;i<N;i++)
		{
			vc[i].clear();
			char tmp[1000];
			gets(tmp);
			char *ptr=strtok(tmp," ");
			int c;
			sscanf(ptr,"%d",&c);
			P[i]=c;
			ptr=strtok(NULL," ");
			while(ptr!=NULL)
			{
				int idx;
				sscanf(ptr,"%d",&idx);idx--;
				vc[i].push_back(idx);
				ptr=strtok(NULL," ");
			}
		}
		MS(dp,0x3f);
		dp[s1][s2]=0;
		for(int i=0;i<N;i++)
		{
			for(int j=(1<<S)-1;j>=s1;j--)
			{
				for(int k=(1<<S)-1;k>=s2;k--)
				{
					int ts1=j,ts2=k;
					foreach(it,vc[i])add(ts1,ts2,*it);
					dp[ts1][ts2]=min(dp[ts1][ts2],dp[j][k]+P[i]);
				}
			}
		}
		printf("%d\n",ans+dp[(1<<S)-1][(1<<S)-1]);
	}
	return 0;
}
