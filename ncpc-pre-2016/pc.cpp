#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009ll
#define MAX 131072
typedef long long ll;

ll dp[MAX][2];

int main(){
    dp[1][0] = 2;
    dp[1][1] = 2;
    for(int i = 2 ; i < MAX ; i++){
        dp[i][0] = dp[i-1][0] * 2 % MOD;
        dp[i][1] = dp[i-1][1] + 1 + (dp[i-1][0] - dp[i-1][1] + MOD) % MOD * 2;
        dp[i][1] %= MOD;
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", dp[a][b] - 1);
    }
    return 0;
}
