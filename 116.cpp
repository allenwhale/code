#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N,M,mp[20][110],dp[20][110];
int main()
{
    while(~scanf("%d %d",&N,&M))
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        for(int i=M-1;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                if(i==M-1)dp[j][i]=mp[j][i];
                else dp[j][i]=mp[j][i]+min(min(dp[(j-1+N)%N][i+1],dp[j][i+1]),dp[(j+1)%N][i+1]);          
                //printf("%d %d %d\n",j,i,dp[j][i]);
            }
        }
        int ans=(int)1e9,st=-1;
        for(int i=0;i<N;i++)
        {
            //printf("%d %d\n",i,dp[0][i]);
            if(ans>dp[i][0])
            {
                ans=dp[i][0];st=i;
            }
        }
        printf("%d",st+1);
        for(int i=1;i<M;i++)
        {
            int a1=dp[st][i],a2=dp[(st+1)%N][i],a3=dp[(st-1+N)%N][i];
            pair<int,int>p[4];
            p[0]=make_pair(a1,st);
            p[1]=make_pair(a2,(st+1)%N);
            p[2]=make_pair(a3,(st-1+N)%N);
            sort(p,p+3);
            printf(" %d",p[0].second+1);
            st=p[0].second;
        }
        puts("");
        printf("%d\n",ans);
    }
}
