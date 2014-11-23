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
int N;
int s[2000010],s2[2000010];
vector<int>ptr[2000010];
struct OBJ
{
	int l,r;
}obj[2000010];
bool cmp1(OBJ a,OBJ b)
{
	return a.l>b.l;
}
bool cmp2(OBJ a,OBJ b)
{
	return a.r>b.r;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&s2[i]);
		ptr[s2[i]].PB(i);
	}
	int top=0;
	for(int i=0;i<N;i++)
	{
		if(s2[i]==s[i])
		{
			//obj[i].l=obj[i].r=0;
			continue;
		}
		if(SIZE(ptr[s[i]])==1)
		{
			obj[top].l=(i-ptr[s[i]][0]+N)%N;
			obj[top++].r=(ptr[s[i]][0]-i+N)%N;
			continue;
		}
		int l=0,r=SIZE(ptr[s[i]]),sz=r;
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(ptr[s[i]][mid]>i)r=mid;
			else l=mid;
		}
		if(l==0&&ptr[s[i]][0]>i)
		{
			obj[top].l=(i-ptr[s[i]][sz-1]+N)%N;
			obj[top++].r=(ptr[s[i]][0]-i+N)%N;	
		}
		else if(ptr[s[i]][sz-1]<i)
		{
			obj[top].l=(i-ptr[s[i]][sz-1]+N)%N;
			obj[top++].r=(ptr[s[i]][0]-i+N)%N;	
		}
		else
		{
			obj[top].l=(i-ptr[s[i]][l]+N)%N;
			obj[top++].r=(ptr[s[i]][l+1]-i+N)%N;	
		}
		
	}
	//for(int i=0;i<N;i++)
	//	printf(" %d %d\n",obj[i].l,obj[i].r);
	sort(obj,obj+top,cmp1);
	int turn=0;
	int ans=obj[0].l;
	for(int i=1;i<top;i++)
	{
		turn=max(turn,obj[i-1].r);
		ans=min(ans,obj[i].l+turn*2);
	}
	sort(obj,obj+top,cmp2);
	turn=0;
	ans=min(ans,obj[0].r);
	for(int i=1;i<top;i++)
	{
		turn=max(turn,obj[i-1].l);
		ans=min(ans,obj[i].r+turn*2);
	}
	printf("%d\n",ans);
	return 0;
}

