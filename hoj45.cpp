#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 1
#define M 2
#define F 3
using namespace std;
#define MS(a,b) memset(a,b,sizeof(a));
#define max(a,b) ((a)>(b)?(a):(b))
int dp[2][20][20];
char s[100010];
inline int turn(char c)
{
    if(c=='B')return B;
    else if(c=='M')return M;
    else if(c=='F')return F;
    return -1;
}
inline int count(int x,int n)
{
    bool vis[10]={false};
    vis[x&((1<<2)-1)]=true;
    vis[x>>2]=true;
    vis[n]=true;
    return vis[1]+vis[2]+vis[3];
}
int main()
{
    int N;
    scanf("%d%*c",&N);
    gets(s+1);
    MS(dp,-1)
    dp[0][0][0]=0;
    int flag=1;
    for(int i=1;i<=N;i++,flag^=1)
    {
        int n=turn(s[i]);
        for(int j=0;j<16;j++)
        {
            for(int k=0;k<16;k++)
            {
                if(dp[flag^1][j][k]!=-1)
                {
                    
                    //1
                    int dj=((j&((1<<2)-1))<<2)+n;
                    dp[flag][dj][k]=max(dp[flag][dj][k],dp[flag^1][j][k]+count(j,n));
                    //2
                    int dk=((k&((1<<2)-1))<<2)+n;
                    dp[flag][j][dk]=max(dp[flag][j][dk],dp[flag^1][j][k]+count(k,n));
                    //printf("%d %d %d\n",i,dj,dk);
                }
            }
        }
        memcpy(dp[flag^1],dp[flag],sizeof(dp[flag]));
        //MS(dp[flag],-1);
    }
    int ans=-1;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            ans=max(ans,dp[flag^1][i][j]);
        }
    }
    printf("%d\n",ans);
   // while(1);
}
