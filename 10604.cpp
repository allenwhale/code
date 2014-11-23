#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 10
int N,M;
int dp[2000000];
int cnt[MAXN];
struct che
{
	int over,heat;
}c[MAXN][MAXN];
int _hash()
{
	int res=0;
	int tmp=0;
	for(int i=1;i<=N;i++)
	{
		if(cnt[i])tmp++;
		res=res*11+cnt[i];
	}
	if(tmp==1)return 0;
	return res;
}
int find()
{
	int k=_hash();
	int &tmp=dp[k];
	if(tmp!=-1)return tmp;
	tmp=0x3f3f3f3f;
	for(int i=1;i<=N;i++)
	{
		if(cnt[i]==0)continue;
		cnt[i]--;
		for(int j=1;j<=N;j++)
		{
			if(cnt[j]==0)continue;
			cnt[j]--;
			cnt[c[i][j].over]++;
			tmp=min(tmp,find()+c[i][j].heat);
			cnt[c[i][j].over]--;
			cnt[j]++;
		}
		cnt[i]++;
	}
	return tmp;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		dp[0]=0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				scanf("%d %d",&c[i][j].over,&c[i][j].heat);
			}
		}
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int idx;
			scanf("%d",&idx);
			cnt[idx]++;
		}
		char s[10];
		scanf("%s",s);
		printf("%d\n",find());
	}
	return 0;
}