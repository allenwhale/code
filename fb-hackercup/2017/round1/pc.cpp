#include <bits/stdc++.h>
using namespace std;

int mp[110][110];
int s[5010];
int d[5010];
int dp[5010][3];

int Solve(){
    int N, M, K;
    memset(mp, 0x01, sizeof(mp));
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        mp[a][b] = mp[b][a] = min(mp[a][b], c);
    }
    for(int i=0;i<N;i++)
        mp[i][i] = 0;
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for(int i=1;i<=K;i++){
        scanf("%d%d", &s[i], &d[i]);
        s[i]--, d[i]--;
    }
    s[0] = d[0] = 0;
    memset(dp, 0x01, sizeof(dp));
    dp[1][0] = mp[0][s[1]];
    for(int i=2;i<=K;i++){
        dp[i][0] = dp[i - 1][0] + mp[s[i - 1]][d[i - 1]] + mp[d[i - 1]][s[i]];
        if(i > 2){
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + mp[s[i - 1]][d[i - 2]] + mp[d[i - 2]][d[i - 1]] + mp[d[i - 1]][s[i]]);
        }
        dp[i][1] = dp[i - 1][0] + mp[s[i - 1]][s[i]];
        if(i > 2){
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + mp[s[i - 1]][d[i - 2]] + mp[d[i - 2]][s[i]]);
        }
    }
    int ans = min(dp[K][0] + mp[s[K]][d[K]], dp[K][1] + mp[s[K]][d[K - 1]] + mp[d[K - 1]][d[K]]);
    if(ans < 0x01010101)
        return ans;
    return -1;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++)
        printf("Case #%d: %d\n", i, Solve());
    return 0;
}
