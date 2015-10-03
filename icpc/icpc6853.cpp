#include <bits/stdc++.h>
using namespace std;
int w[110][60], c[110][110];
int dp[110][60];
int S,C;
int DP(int x,int n){
    if(dp[x][n]!=-1)return dp[x][n];
    dp[x][n]=-10000000;
    for(int i=0;i<S;i++){
        dp[x][n]=max(dp[x][n],DP(i,n-1)+w[x][C-n-1]-c[i][x]);
    }
    return dp[x][n];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&S,&C);
        for(int i=0;i<S;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&w[i][j]);
        for(int i=0;i<S;i++)
            for(int j=0;j<S;j++)
                scanf("%d",&c[i][j]);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<S;i++)
            dp[i][0]=w[i][C-1];
        int ans=0;
        for(int i=0;i<S;i++)
            ans=max(ans,DP(i,C-1));
        printf("%d\n",ans);
    }
    return 0;
}
