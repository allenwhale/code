#include <bits/stdc++.h>
using namespace std;
int u[110];
double pi[110], sumpi[110];
double dp[110][110][110];
bool vis[110][110][110];
double DP(int l, int r, int w){
    if(vis[l][r][w])return dp[l][r][w];
    if(r - l + 1 < w){
        vis[l][r][w] = true;
        return dp[l][r][w] = 1e9;
    }
    if(w == 1){
        vis[l][r][w] = true;
        return dp[l][r][w] = (sumpi[r] - sumpi[l - 1]) * double(r - l + 1);
    }
    vis[l][r][w] = true;
    dp[l][r][w] = 1e9;
    for(int i = l ; i < r ; i++){
        dp[l][r][w] = min(dp[l][r][w], DP(l, i, 1) + DP(i + 1, r, w - 1) + double(i - l + 1) * (sumpi[r] - sumpi[i]));
    }
    return dp[l][r][w];
}
void Solve(){
    int N, W;
    scanf("%d%d", &N, &W);
    int sumu = 0;
    for(int i = 1 ; i <= N ; i++){
        scanf("%d", &u[i]);
        sumu += u[i];
    }
    sort(u + 1, u + N + 1);
    reverse(u + 1, u + N + 1);
    sumpi[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        pi[i] = double(u[i]) / double(sumu);
        sumpi[i] = sumpi[i - 1] + pi[i];
    }
    memset(vis, false, sizeof(vis));
    printf("%.4f\n", DP(1, N, W));
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
