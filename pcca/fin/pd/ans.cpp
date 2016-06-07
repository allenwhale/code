#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
typedef long long ll;
int N, K;
ll W;
ll s[MAXN];
vector<ll> vc[MAXN];
ll dp[MAXN];
ll Calc(int x, int sub=0){
    if(dp[x] != -1) return dp[x];
    dp[x] = 0;
    for(int i=0;i<(int)vc[x].size();i++){
        dp[x] = max(dp[x], Calc(vc[x][i], sub));
    }
    int real = ((s[x] - sub) > 0) ? (s[x] - sub) : 0;
    dp[x] = dp[x] + real;
    return dp[x];
}
int Check(int m){
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for(int i=0;i<N;i++)
        res += Calc(i, m) <= W;
    return res;
}
int Solve(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        vc[i].clear();
    ll mx = 0;
    for(int i=0;i<N;i++){
        scanf("%lld", &s[i]);
        mx = max(mx, s[i]);
    }
    for(int i=0;i<N;i++){
        int num;
        scanf("%d", &num);
        while(num--){
            int prev;
            scanf("%d", &prev);
            vc[i].push_back(prev);
        }
    }
    scanf("%d%lld", &K, &W);
    int l = 0, r = mx, ans = -1;
    while(l <= r){
        int mid = (l + r)  >> 1;
        int c = Check(mid);
        if(c >= K){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        printf("%d\n", Solve());
    return 0;
}
