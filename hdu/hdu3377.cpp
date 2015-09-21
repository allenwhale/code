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
#define HASH 479
#define STATE 2800
struct HASHMAP
{
	int head[HASH],next[STATE],val[STATE],sta[STATE],sz;
	inline void init()
	{
		sz=0;
		MS(head,-1);
	}
	inline int getsta(int idx)
	{
		return this->sta[idx];
	}
	inline int getval(int idx)
	{
		return this->val[idx];
	}
	inline void push(int st,int v)
	{
		int t=st%HASH;
		for(int p=head[t];~p;p=next[p])
		{
			if(st==sta[p])
			{
				val[p]=max(val[p],v);
				return ;
			}
		}
		val[sz]=v;
		sta[sz]=st;
		next[sz]=head[t];
		head[t]=sz++;
	}
}hs[2];
inline int change(int sta,int k,int c)
{
	return (sta&(2147483647^((1<<(2*(k+1)))-1)))|((sta&((1<<(2*k))-1))|(c<<(2*k)));
}
int N,M,mp[10][11];
void read()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
}
int DP()
{
	int ans=-INF;
	int flag=0;
	hs[0].init();
	hs[1].init();
	hs[flag].push(1<<2,0);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++,flag^=1)
		{
			hs[flag^1].init();
			int sz=hs[flag].sz;
			//printf("%d %d %d\n",i,j,sz);
			if(j==M)
			{
				for(int k=0;k<sz;k++)
				{
					int sta=hs[flag].getsta(k);
					int val=hs[flag].getval(k);
					hs[flag^1].push(sta<<2,val);
				}
				continue;
			}
			for(int k=0;k<sz;k++)
			{
				int sta=hs[flag].getsta(k);
				int val=hs[flag].getval(k);
				int left=(sta>>(j<<1))    &3;
				int up  =(sta>>((j+1)<<1))&3;
				//printf("sta %d val %d left %d up %d\n",sta,val,left,up);
				if(left==0&&up==0)
				{
					hs[flag^1].push(sta,val);
					if(j==M-1)continue;
					
					sta=change(change(sta,j,1),j+1,2);
					hs[flag^1].push(sta,val+mp[i][j+1]);
				}
				else if(left==1&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					if(j==M-1)continue;
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
					hs[flag^1].push(sta,val+mp[i][j+1]);
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
					hs[flag^1].push(sta,val+mp[i][j+1]);
				}
				else if(left==2&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					hs[flag^1].push(sta,val+mp[i][j+1]);
				}
				else if(left==1&&up==2);
				else
				{
					if(left==0&&up!=0)
					{
						if(i==N&&j==M-1&&sta==(1<<(M<<1)))
						{
							ans=max(ans,val+mp[i][j+1]);
							continue;
						}
						if(j+2<=M)
						{
							hs[flag^1].push(sta,val+mp[i][j+1]);
						}
						if(i<N)
						{
							sta=change(change(sta,j,up),j+1,0);
							hs[flag^1].push(sta,val+mp[i][j+1]);
						}
					}
					else if(left!=0&&up==0)
					{
						if(i==N&&j==M-1&&sta==(1<<(j<<1)))
						{
							ans=max(ans,val+mp[i][j+1]);
							continue;
						}
						if(i<N)
						{
							hs[flag^1].push(sta,val+mp[i][j+1]);
						}
						if(j+2<=M)
						{
							sta=change(change(sta,j,0),j+1,left);
							hs[flag^1].push(sta,val+mp[i][j+1]);
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
	int t=1;
	while(~scanf("%d %d",&N,&M))
	{
		read();
		//puts("read");
		int ans=DP();
		//puts("DP");
		printf("Case %d: %d\n",t++,ans);
	}
	return 0;
}

