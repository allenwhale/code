#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> PII;
ll ans[64];
PII vote[64];
ll dp[64];

int main(){
    int n, m, t = 1;
    while(scanf("%d%d", &n, &m),n||m){
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d", &vote[i].f, &vote[i].s);
        }
        memset(ans, 0, sizeof(ans));
        for(int i = 0 ; i < n ; i++){
            vote[i].s--;
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for(int r = 0 ; r < n ; r++){
                for(int j = 0 ; j < vote[r].s ; j++){
                    for(int k = m ; k >= vote[r].f ; k--)
                        dp[k] += dp[k-vote[r].f];

