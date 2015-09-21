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
#define PF(a) push_front(a)
#define PPF() pop_front()
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
char a[100010];
ll add1[200020],add2[400020],add3[800020];
ll N,M;
#define MOD %=M
struct MAT
{
	ll d[3][3];
	MAT(){MS(d,0);}
	MAT(ll *l)
	{
		d[0][0]=l[0];
		d[0][1]=l[1];
		d[1][0]=l[2];
		d[1][1]=l[3];
	}
	MAT operator * (const MAT n)const
	{
		MAT res=MAT();
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				ll tmp=0;
				for(int k=0;k<2;k++)
				{
					tmp+=d[i][k]*n.d[k][j];
					tmp MOD;
				}
				res.d[i][j]=tmp;
			}
		}
		return res;
	}
};
MAT POW(MAT A,ll n)
{
	MAT res=MAT();
	for(int i=0;i<2;i++)res.d[i][i]=1;
	n-=3;
	while(n>0)
	{
		if(n&1)res=res*A;
		A=A*A;
		n>>=1;
	}
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s "__lld" "__lld,a,&N,&M);
		int len=strlen(a);
		int r=0;
		MS(add1,0);
		MS(add2,0);
		MS(add3,0);
		for(int i=0;i<len;i++)
		{
			add1[len+(r+=(a[i]=='0'?-1:1))]++;
		}
		//printf("r %d\n",r);
		ll a1=add1[len];
		for(int i=0;i<2*len;i++)
		{
			//printf("%d %d\n",i,add1[i]);
			add2[len+i]+=add1[i];
			add2[len+(2*len-i+r)]+=add1[i];
			a1+=((ll)add1[i]*(add1[i]-1))/2;
			a1 MOD;
			add2[len+(2*len-i+r)] MOD;
			add2[len+i] MOD;
		}
		ll a2=add2[len*2];
		for(int i=0;i<len*4;i++)
		{
			add3[len*2+i]+=add2[i];
			add3[len*2+(4*len-i)]+=add2[i];
			a2+=((ll)add2[i]*(add2[i]-1))/2;
			a2 MOD;
			add3[len*2+i] MOD;
			add3[len*2+(4*len-i)] MOD;
		}
		
		ll a3=add3[len*4];
		ll f3=0;
		for(int i=0;i<len*8;i++)
		{
			a3+=((ll)add3[i]*(add3[i]-1))/2;
			f3+=(ll)add3[i]*add3[8*len-i];
			a3 MOD;
			f3 MOD;
		}
		if(N==1)
		{
			printf(__lld"\n",a1);
			continue;
		}
		else if(N==2)
		{
			printf(__lld"\n",a2);
			continue;
		}
		else if(N==3)
		{
			printf(__lld"\n",a3);
			continue;
		}
		ll l[]={2,1,0,4};
		MAT D=MAT(l);
		D=POW(D,N);
		//printf("%d %d %d %d\n",(int)a1,a2,a3,f3);
		ll tmp=D.d[0][0]*a3+D.d[0][1]*f3;
		tmp MOD;
		printf(__lld"\n",tmp);
	}
	return 0;
}

