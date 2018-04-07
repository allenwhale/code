#include <bits/stdc++.h>
using namespace std;
double dp[500][500];
int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0 ; i <= K ; i++)
        for(int j = 0 ; j <= N ; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i = 0 ; i < K ; i++){
        for(int j = 0 ; j < N ; j++){
            dp[i + 1][j + 1] += dp[i][j] * 0.5;
            dp[i + 1][j] += dp[i][j] * 0.5;
        }
        dp[i + 1][N] += dp[i][N] * 0.5;
        dp[i + 1][N - 1] += dp[i][N] * 0.5;
    }
    double ans = 0;
    for(int i = 0 ; i <= N ; i++){
        ans += dp[K][i] * i;
    }
    printf("%.10f\n", ans);
    return 0;
}

