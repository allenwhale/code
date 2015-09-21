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
struct E
{
    int a,b;
    db c;
    E(){}
    E(int _a,int _b,db _c)
    {
        a=_a,b=_b,c=_c;
    }
}e[5010],e2[5010];
vector<E>vc[1010];
int N,M;
int f[1010];
db dis[1010];
bool vis[1010];
int cnt[1010];
void fill(db x)
{
    for(int i=0;i<M;i++)
    {
        e2[i].c=e[i].c*x-(db)f[e[i].b];
    }
}
bool BFS(double r)
{
    fill(dis,dis+N+1,1e9);
    dis[1]=0.0;
    queue<int>q;
    q.push(1);
    MS(cnt,0);
    MS(vis,false);
    //cnt[1]=1;
    vis[1]=true;
    while(!q.empty())
    {
         
        int tmp=q.front();
        //printf(" %d\n",tmp);
        q.pop();
        vis[tmp]=false;
        foreach(it,vc[tmp])
        {
            double c=it->c*r-(db)f[it->b];
            if(dis[it->b]>dis[tmp]+c)
            {
                dis[it->b]=dis[tmp]+c;
                if(vis[it->b]==false)
                {
                    q.push(it->b);
                    vis[it->b]=true;
                    cnt[it->b]++;
                    if(cnt[it->b]>=N)return true;
                }
            }
        }
    }
    return false;
}
 
int main()
{
    N=getint();M=getint();
    for(int i=1;i<=N;i++)
    {
        f[i]=getint();
    }
    for(int i=0;i<M;i++)
    {
        e[i].a=getint();
        e[i].b=getint();
        scanf("%lf",&e[i].c);
        if(e[i].a==e[i].b)continue;
        vc[e[i].a].PB(E(e[i].a,e[i].b,e[i].c));
    }
    db l=0.0,r=100000.0;
    db mid;
    int ccc=50;
    while(ccc--)
    {
        mid=(l+r)/2.0;
         
        if(BFS(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    if(fabs(l)<=1e-5)printf("0\n");
    else printf("%.2lf\n",l);
    return 0;
}
