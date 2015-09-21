#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;
int N,mp[2][510][510],W[2],H[2],X[2],Y[2],p[2][100010];
bool vis[2][510][510];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct STA
{
    int x,y,v;
    STA(int _x,int _y,int _v)
    {
        x=_x,y=_y,v=_v;
    }
    bool operator < (const STA& n)const
    {
        return v>n.v;
    };
};
bool isin(int idx,int x,int y)
{
    return x>0&&y>0&&x<=H[idx]&&y<=W[idx];
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<2;i++)
    {
        scanf("%d %d %d %d",&W[i],&H[i],&Y[i],&X[i]);
        for(int j=1;j<=H[i];j++)
        {
            for(int k=1;k<=W[i];k++)
            {
                scanf("%d",&mp[i][j][k]);
            }
        }
    }
    memset(p,0x3f,sizeof(p));
    for(int z=0;z<2;z++)
    {
        //printf("z %d\n",z);
        priority_queue<STA>pq;
        vis[z][X[z]][Y[z]]=true;
        pq.push(STA(X[z],Y[z],mp[z][X[z]][Y[z]]));
        p[z][0]=0;
        for(int k=1;k<=N&&!pq.empty();k++)
        {
            STA tmp=pq.top();pq.pop();
            //printf("%d %d %d\n",tmp.x,tmp.y,tmp.v);
            p[z][k]=max(tmp.v,p[z][k-1]);
            for(int i=0;i<4;i++)
            {
                int tx=tmp.x+dx[i],ty=tmp.y+dy[i];
                if(isin(z,tx,ty)&&vis[z][tx][ty]==false)
                {
                    vis[z][tx][ty]=true;
                    pq.push(STA(tx,ty,mp[z][tx][ty]));
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=N;i++)
    {
        //printf("  %d %d\n",p[0][i],p[1][N-i]);
        ans=min(p[0][i]+p[1][N-i],ans);
    }
    printf("%d\n",ans);
    //while(1);
}
