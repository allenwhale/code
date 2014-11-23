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
#define HASH 30007
#define STATE 100010
int N,M,D,mod=7777777;
struct HASHMAP
{
	int head[HASH],sta[STATE],next[STATE],sz;
	inline void init()
	{
		MS(head,-1);sz=0;
	}
	inline int getsta(int idx)const
	{
		return this->sta[idx];
	}
	inline int push(int st)
	{
		int t=st%HASH;
		for(int p=head[t];~p;p=next[p])
		{
			if(st==sta[p])
				return p;
		}
		sta[sz]=st;
		next[sz]=head[t];
		head[t]=sz++;
		return sz-1;
	}
}hs;
struct MAT
{
	int _d[128][128];
	MAT()
	{
		MS(_d,0);
	}
	inline void copy(const MAT a)
	{
		memcpy(this->_d,a._d,sizeof(a._d));
	}
	
	
}mat;
MAT mul(MAT a,MAT b)
{
	MAT res;
	for(int i=0;i<D;i++)
	{
		for(int j=0;j<D;j++)
		{
			ll tmp=0ll;
			for(int k=0;k<D;k++)
			{
				tmp+=((ll)a._d[i][k]*b._d[k][j]);
				if(tmp>=mod)tmp%=mod;
			}
			res._d[i][j]=tmp;
		}
	}
	return res;
}
inline MAT POW(const MAT a,int k)
{
	MAT res=MAT();
	for(int i=0;i<D;i++)res._d[i][i]=1;
	MAT tmp=a;
	while(k)
	{
		if(k&1)res=mul(res,tmp);
		tmp=mul(tmp,tmp);
		k>>=1;
	}
	return res;
}
int encode(int code[])
{
	int ans=0;
	int hash[30];
	MS(hash,-1);
	int cnt=1;
	hash[0]=0;
	for(int i=0;i<N;i++)
	{
		if(hash[code[i]]==-1)hash[code[i]]=cnt++;
		ans=(ans<<2)|hash[code[i]];
	}
	return ans;
}
void decode(int code[],int st)
{
	for(int i=N-1;i>=0;i--)
		code[i]=st&3,st>>=2;
}
int check(int sta1,int sta2)
{
	int code[10];
	decode(code,sta1);
	int flag=0,k;
	int cnt=N;
	//printf("%d %d\n",sta1,sta2);
	for(int i=0;i<N;i++)
	{
		//printf(" %d\n",i);
		if(flag==0)
		{
			if(code[i]&&sta2&(1<<i))continue;
			if(!code[i]&&!(sta2&(1<<i)))
			{
				//puts("d1");
				return -1;
			}
			if(code[i])flag=code[i];
			else flag=-1;
			k=i;
		}
		else
		{
			if(code[i]&&sta2&(1<<i))
			{
				//puts("d2");
				return -1;
			}
			if(!code[i]&&!(sta2&(1<<i)))continue;
			if(code[i])
			{
				if(flag==code[i]&&(sta2!=0||i!=N-1))
				{
					//puts("d3");
					return -1;
				}
				if(flag>0)
				{
					for(int j=0;j<N;j++)
						if(code[j]==code[i]&&i!=j)code[j]=code[k];
					code[i]=code[k]=0;
				}
				else
				{
					code[k]=code[i];code[i]=0;
				}
			}
			else
			{
				if(flag>0)
				{
					code[i]=code[k],code[k]=0;
				}
				else
				{
					code[i]=code[k]=cnt++;
				}
			}
			flag=0;
		}
	}
	if(flag!=0)return -1;
	else return encode(code);
}
void initmat()
{
	hs.init();
	mat=MAT();
	hs.push(0);
	int code[10];
	code[0]=code[N-1]=1;
	hs.push(encode(code));
	for(int i=1;i<hs.sz;i++)
	{
		int sta=hs.getsta(i);
		for(int j=0;j<(1<<N);j++)
		{
			int nsta;
			if((nsta=check(sta,j))!=-1)
			{
				//printf("turn %d %d\n",sta,nsta);
				mat._d[i][hs.push(nsta)]=1;
			}
		}
	}
	D=hs.sz;
}
void solve()
{
	MAT ans;

	ans=POW(mat,M);
	if(ans._d[1][0]==0)puts("Impossible");
	else printf("%d\n",ans._d[1][0]%mod);
}
int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		initmat();
		solve();
	}
	return 0;
}

