#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
#define HASH 10007
#define STATE 40010
struct HASHMAP
{
	int head[HASH],sta[STATE],next[STATE],sz;
	ll val[STATE];
	inline void init()
	{
		MS(head,-1);sz=0;
	}
	inline int getsta(int idx)const
	{
		return this->sta[idx];
	}
	inline ll getval(int idx)const
	{
		return this->val[idx];
	}
	inline void push(int st,ll v)
	{
		int t=st%HASH;
		for(int p=head[t];~p;p=next[p])
		{
			if(st==sta[p])
			{
				val[p]+=v;
				return ;
			}
		}
		val[sz]=v;
		sta[sz]=st;
		next[sz]=head[t];
		head[t]=sz++;
	}
}hs[2];
char mp[15][15];
int N,M,NUM;
//int mx=0;
void read()
{
	NUM=0;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(mp[i][j]=='O')NUM++;
		}
	}
}
inline int change(int sta,int k,int c)
{
	return (sta&(2147483647^((1<<(2*(k+1)))-1)))|((sta&((1<<(2*k))-1))|(c<<(2*k)));
}
ll DP()
{
	hs[0].init();
	hs[1].init();
	int flag=0;
	hs[flag].push(0,1);
	int sum=0;
	ll ans=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++,flag^=1)
		{
			hs[flag^1].init();
			int sz=hs[flag].sz;
			//mx=max(mx,sz);
			//printf("%d %d %d\n",i,j,sz);
			if(j==M)
			{
				for(int k=0;k<sz;k++)
				{
					int sta=hs[flag].getsta(k);
					ll val=hs[flag].getval(k);
					//printf("insert %d %d\n",sta,val);
					hs[flag^1].push(sta<<2,val);
				}
				continue;
			}
			if(mp[i][j+1]=='X')
			{
				for(int k=0;k<sz;k++)
				{
					int sta=hs[flag].getsta(k);
					ll val=hs[flag].getval(k);
					int left=(sta>>(j<<1))&3;
					int up  =(sta>>((j+1)<<1))&3;
					if(left==0&&up==0)hs[flag^1].push(sta,val);
				}
				continue;
			}
			if(mp[i][j+1]=='O')sum++;
			for(int k=0;k<sz;k++)
			{
				int sta=hs[flag].getsta(k);
				ll val=hs[flag].getval(k);
				int left=(sta>>(j<<1))&3;
				int up  =(sta>>((j+1)<<1))&3;
				//printf("sta %d val %d left %d up %d sum %d\n",sta,val,left,up,sum);
				if(left==0&&up==0)
				{
					if(mp[i][j+1]=='*')
					{
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
						if(j!=M-1)
						{
							sta=change(change(sta,j,1),j+1,2);
							hs[flag^1].push(sta,val);
							//printf("turn %d\n",sta);
						}
					}
					else if(mp[i][j+1]=='O'&&j!=M-1)
					{
						sta=change(change(sta,j,1),j+1,2);
						hs[flag^1].push(sta,val);
					}
				}
				else if(left==1&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					for(int q=j+2,p=1;q<=M;q++)
					{
						if((sta>>(q<<1))&1)p++;
						else if((sta>>(q<<1))&2)
						{
							p--;
							if(p==0)
							{
								sta=change(sta,q,1);
								break;
							}
						}
					}
					hs[flag^1].push(sta,val);
				}
				else if(left==2&&up==2)
				{
					sta=change(change(sta,j,0),j+1,0);
					for(int q=j-1,p=1;q>=0;q--)
					{
						if((sta>>(q<<1))&2)p++;
						else if((sta>>(q<<1))&1)
						{
							p--;
							if(p==0)
							{
								sta=change(sta,q,2);
								break;
							}
						}
					}
					hs[flag^1].push(sta,val);
				}
				else if(left==2&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					hs[flag^1].push(sta,val);
				}
				else if(left==1&&up==2)
				{
					if(sum==NUM)
					{
						sta=change(change(sta,j,0),j+1,0);
						if(sta==0)
						{
							ans+=val;
							//printf("ans\n");
						}
					}
				}
				else
				{
					if(left!=0&&up==0)
					{
						if(i<N)
						{
							hs[flag^1].push(sta,val);
						}
						if(j+2<=M)
						{
							sta=change(change(sta,j,0),j+1,left);
							hs[flag^1].push(sta,val);
						}
					}
					else if(left==0&&up!=0)
					{
						if(j+2<=M)
						{
							hs[flag^1].push(sta,val);
						}
						if(i<N)
						{
							sta=change(change(sta,j,up),j+1,0);
							hs[flag^1].push(sta,val);
						}
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	int T;
	int t=1;
	
	scanf("%d",&T);
	while(T--)
	{
		read();
		//printf("NUM %d\n",NUM);
		ll ans;
		if(NUM==0)ans=0;
		else ans=DP();
		printf("Case %d: "__lld"\n",t++,ans);
		//printf("%d\n",mx);
	}
	return 0;
}

