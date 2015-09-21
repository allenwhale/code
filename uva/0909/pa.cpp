#include <bits/stdc++.h>
using namespace std;
int r[1010];
vector<int>vc[1010];
int dp[1010][2];
int dfs(int x,int d){
    if(dp[x][d]!=-1)return dp[x][d];
    if(d==0){
        dp[x][d]=0;
        for(auto v:vc[x]){
            dp[x][d]+=max(dfs(v,0),dfs(v,1));
        }
    }else{
        dp[x][d]=r[x];
        for(auto v:vc[x])
            dp[x][d]+=dfs(v,0);
    }
    return dp[x][d];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d %d",&N,&r[1]);
        for(int i=1;i<=N;i++)
            vc[i].clear();
        memset(dp,-1,sizeof(dp));
        for(int i=2;i<=N;i++){
            int s;
            scanf("%d %d",&s,&r[i]);
            vc[s].push_back(i);
        }
        printf("%d\n", max(dfs(1,1),dfs(1,0)));
    }
    return 0;
}
