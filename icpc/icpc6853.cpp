#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
int w[110][60], c[110][110];
int dp[110][60];
int S,C;
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
        for(int i=0;i<S;i++)
            for(int j=0;j<C;j++)
                dp[i][j]=-INF;
        for(int i=0;i<S;i++)
            dp[i][0]=w[i][0];
        for(int j=1;j<C;j++){
            for(int i=0;i<S;i++){
                for(int k=0;k<S;k++){
                    dp[i][j]=max(dp[i][j], dp[k][j-1]+w[i][j]-c[k][i]);
                }
            }
        }
        int ans=-INF;
        for(int i=0;i<S;i++)
            ans=max(ans, dp[i][C-1]);
        printf("%d\n",ans);
    }
    return 0;
}
