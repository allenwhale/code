#include <stdio.h>
#include <string.h>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
typedef long long ll;
ll dp[2][1594323];
/*
00 NULL
10 (
01 )
*/
//set<int>vc[2];
char mp[15][15];
int N,M,ex,ey,tot=0;
int mx=0;
int tc=0,th=0,tMS=0;
struct HASH
{
	int sz,num[996500];
	bool vis[1594333];
	inline void init()
	{
		MS(vis,false);
		sz=0;
	}
	inline void insert(int x)
	{
		if(vis[x]==false)
		{
			vis[x]=true;
			num[sz++]=x;
		}
	}
}vc[2];
inline int encode(int s)
{
	int res=0;
	for(int k=M;k>=0;k--)
	{
		res*=3;
		res+=(s>>(2*k))&3;
	}
	return res;
}
inline int decode(int s)
{
	int res=0;
	for(int i=0;i<=M;i++)
	{
		res|=((s%3)<<(2*i));
		s/=3;
	}
	return res;
}
inline void read()
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%s",mp[i]+1);
	}
}
inline void find()
{
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(mp[i][j]=='.')ex=i,ey=j,tot++;
} 
inline int change(int sta,int k,int c)
{
	return (sta&(2147483647^((1<<(2*(k+1)))-1)))|((sta&((1<<(2*k))-1))|(c<<(2*k)));
}
void DP()
{
	ll ans=0ll;
	MS(dp,0ll);
	int flag=0;
	dp[flag][0]=1ll;
	vc[flag].insert(0);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++,flag^=1)
		{
			vc[flag^1].init();
			MS(dp[flag^1],0ll);
			if(j==M)
			{
				for(int e=0;e<vc[flag].sz;e++)
				{
					int sta=decode(vc[flag].num[e]);
					sta=encode(sta<<2);
					vc[flag^1].insert(sta);
					dp[flag^1][sta]=dp[flag][vc[flag].num[e]];
				}
				continue;
			}
			for(int e=0;e<vc[flag].sz;e++)
			{
				int psta=decode(vc[flag].num[e]);
				int up=(psta&(3<<(2*(j+1))))>>(2*(j+1)),left=(psta&(3<<(2*j)))>>(2*j);
				if(mp[i][j+1]=='.')
				{
					if(up==0&&left==0)
					{
						if(j==M-1)continue;
						int sta=change(change(psta,j,2),j+1,1);
						sta=encode(sta);
						dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						vc[flag^1].insert(sta);
					}
					else if(up==1&&left==1)
					{
						int sta=change(change(psta,j,0),j+1,0);
						for(int k=j,p=1;k>=0;k--)
						{
							int tmp=(1<<(2*k));
							if(sta&tmp)p++;
							if(sta&(tmp<<1))
							{
								p--;
								if(p==0)
								{
									sta=change(sta,k,1);
									break;
								}
							}
						}
						sta=encode(sta);
						dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						vc[flag^1].insert(sta);
					}
					else if(up==2&&left==2)
					{
						if(j+1>M)continue;
						int sta=change(change(psta,j,0),j+1,0);
						for(int k=j+1,p=1;k<=M+1;k++)
						{
							int tmp=(1<<(2*k));
							if(sta&(tmp<<1))p++;
							if(sta&tmp)
							{
								p--;
								if(p==0)
								{
									sta=change(sta,k,2);
									break;
								} 
							}
						}
						sta=encode(sta);
						vc[flag^1].insert(sta);
						dp[flag^1][sta]+=dp[flag][vc[flag].num[e]]; 
					}
					else if(left==1&&up==2)
					{
						int sta=change(change(psta,j,0),j+1,0);
						sta=encode(sta);
						vc[flag^1].insert(sta);
						dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
					}
					else if(left==2&&up==1)
					{
						if(i==ex&&j+1==ey)
						{
							int sta=change(change(psta,j,0),j+1,0);
							if(sta)continue;
							sta=encode(sta);
							vc[flag^1].insert(sta);
							ans+=dp[flag][vc[flag].num[e]]; 
						}	
					}
					else if(left!=0&&up==0)
					{
						if(j+2<=M)
						{
							int sta=change(change(psta,j,0),j+1,left);
							sta=encode(sta);
							vc[flag^1].insert(sta);
							dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						}	
						if(i<N)
						{
							int sta=encode(psta);
							vc[flag^1].insert(sta);
							dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						}
					}
					else if(left==0&&up!=0)
					{
						if(j+2<=M)
						{
							int sta=encode(psta);
							vc[flag^1].insert(sta);
							dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						}
						if(i<N)
						{
							int sta=change(change(psta,j,up),j+1,0);
							sta=encode(sta);
							vc[flag^1].insert(sta);
							dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
						}
					}
				}
				else
				{
					if(left==0&&up==0)
					{
						int sta=encode(psta);
						vc[flag^1].insert(sta);
						dp[flag^1][sta]+=dp[flag][vc[flag].num[e]];
					}
				} 
			}
		}
	}
	printf("%I64d\n",ans);
}
int main()
{
	read();
	find();
	DP();
	return 0;
}
