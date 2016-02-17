#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int cas = 0;
int N, Q;
int w[1000], m[1000];
ll b[1000];
ll dp[1000];
bool Solve(){
    scanf("%d%d", &N, &Q);
    if(N == 0)return false;
    for(int i=0;i<N;i++){
        scanf("%d%d", &w[i], &m[i]);
    }
    for(int i=0;i<N;i++){
        b[i] = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int j=0;j<N;j++){
            int mm = m[i];
            if(i == j)mm--;

            for(int l=0;l<mm;l++){
                for(int k=Q;k>=w[j];k--){
                    dp[k] += dp[k-w[j]];
                }
            }
        }
        for(int j=0;j<=Q;j++){
            if(j < Q && j+w[i] >= Q)
                b[i] += dp[j];
        }
    }
    printf("Case %d: ", ++cas);
    for(int i=0;i<N;i++)
        printf("%llu ", b[i]);
    printf("\n");
    return true;
}
int main(){
    while(Solve());
    return 0;
}

