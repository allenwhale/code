#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <complex>
#include <functional>
#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>tset;
inline int getint()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	int x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
inline ll getll()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	ll x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
#include "interactive/120.h"
int MIN;
/*
const int pn=5;
int pa[pn]={2,5,4,3,1};
int t=0;
int Med3(int x,int y,int z){
	t++;
	x--,y--,z--;
	int a[3]={pa[x],pa[y],pa[z]};
	sort(a,a+3);
	return(pa[x]==a[1]?x:pa[y]==a[1]?y:z)+1;
}
int GetN()
{
	return pn;
}

void Answer(int x)
{
	printf("%d %d\n",x,t);
}*/
bool cmp(int aa,int bb)
{
	if(aa==MIN)return true;
	if(bb==MIN)return false;
	int k=Med3(MIN,aa,bb);
	return aa==k;
}
int a[1500],*la;
int main()
{
	int n=GetN();
	la=a+n;
	for(int *it=a;it!=la;it++)
	{
		*it=(it-a+1);
	}
	while(2<la-a){
		int k=Med3(a[0],a[1],a[2]);
		for(int i=0;i<3;i++)if(k==a[i]){
			a[i]=*--la;break;
		}
	}
	MIN=a[0];
	la=a+n;
	for(int *it=a;it!=la;it++)
	{
		*it=(it-a+1);
	}
	//random_shuffle(a,la);
	nth_element(a,a+n/2,la,cmp);
	Answer(a[n/2]);
	return 0;
}


