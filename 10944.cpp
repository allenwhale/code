#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
using namespace std;
int N,M,cnt;
struct edge
{
    int to,w;
    edge(){}
    edge(int _t,int _w):to(_t),w(_w){}
};
vector<edge>vc;
char s[30][30];
int dist[20][20];
int x[20],y[20];
int dp[16][(1<<16)];
int tsp(int head,int _x,int _s)
{
    //printf("%d %d\n",_x,_s);
    int &tmp=dp[_x][_s];
    if(tmp!=-1)return tmp;
    if(_s==0)return tmp=dist[head][_x];
    tmp=INF;
    for(int i=0;i<cnt;i++)
    {
        if(_s&(1<<i)&&i!=_x)
        {
            tmp=min(tmp,dist[i][_x]+tsp(head,i,_s^(1<<i)));
        }
    }
    //printf(" %d %d %d\n",_x,_s,dp[_x][_s]);
    return tmp;
}
int main()
{
    while(~scanf("%d %d%*c",&N,&M))
    {
        for(int i=0;i<N;i++)
        {
            gets(s[i]);
        }
        cnt=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(s[i][j]=='L')
                {
                    x[cnt]=i,y[cnt++]=j;
                }
                else if(s[i][j]=='#')
                {
                    x[cnt]=i,y[cnt++]=j;
                }
            }
        }
        if(cnt==1)
        {
            puts("0");
            continue;
        }
        for(int i=0;i<cnt;i++)
        {
            dist[i][i]=INF;
            for(int j=i+1;j<cnt;j++)
            {
                int tx=abs(x[i]-x[j]),ty=abs(y[i]-y[j]);
                dist[i][j]=dist[j][i]=tx+ty-min(tx,ty);
            }
        }
        //for(int i=0;i<cnt;i++,puts(""))
            //for(int j=0;j<cnt;j++)printf("%d ",dist[i][j]);
        int ans;
        memset(dp,-1,sizeof(dp));
        ans=tsp(0,0,((1<<cnt)-1)^(1<<0));
        printf("%d\n",ans);
    }
}
