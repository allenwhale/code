#include <bits/stdc++.h>
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
pI e[3000010],res[3000010];
int in[1000010];
bool ok[1000010];
int col[1000010];
int N,M,K;
int top=0;
int ans=INF;
vector<int>k,ansk;
int tokill=0;
void dfs(int x,int num)
{
	if(num>tokill||num>=ans)return;
	if(x==top)
	{
		if(num<ans)
		{
			ans=num;
			ansk=k;
		}
		return ;
	}
	pI tmp=res[x];
	if(!ok[tmp.FF]||!ok[tmp.SS])
		dfs(x+1,num);
	else
	{
		ok[tmp.FF]=false;
		k.PB(tmp.FF);
		dfs(x+1,num+1);
		ok[tmp.FF]=true;
		k.PPB();
		
		ok[tmp.SS]=false;
		k.PB(tmp.SS);
		dfs(x+1,num+1);
		ok[tmp.SS]=true;
		k.PPB();
	}
}
int main()
{
	scanf("%d %d %d",&N,&K,&M);
	tokill=N-K;
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>b)swap(a,b);
		e[i]=MP(a,b);
	}
	sort(e,e+M);	
	int sz=unique(e,e+M)-e;
	MS(in,0);
	for(int i=0;i<sz;i++)
	{
		in[e[i].FF]++;
		in[e[i].SS]++;
	}
	MS(ok,true);
	int kill=0;
	for(int i=1;i<=N;i++)
	{
		if(in[i]>tokill)kill++,ok[i]=false;
	}
	if(kill>tokill)
	{
		puts("NIE");
		return 0;
	}
	tokill-=kill;
	for(int i=0;i<sz;i++)
	{
		if(!ok[e[i].FF]||!ok[e[i].SS]);
		else res[top++]=e[i];
		if(top>tokill*tokill)
		{
			puts("NIE");
			return 0;
		}
	}
	dfs(0,0);
	if(ans>tokill)
	{
		puts("NIE");
		return 0;
	}
	foreach(it,ansk)
	{
		ok[*it]=false;
	}
	printf("%d\n",N-ans-kill);
	for(int i=1,cnt=0;i<=N;i++)
		if(ok[i])printf("%d%c",i,cnt==N-ans-1?'\n':' ');
	return 0;
}

