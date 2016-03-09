#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define MAXN 500000
#define HASH_A 137ll
#define HASH_M 68720001023ll 
char s[2][MAXN+10];
ll rolling[2][MAXN*2+10];
ll pow_mod(ll a, ll n, ll m){
    if(n == 0)return 1ll;
    ll res = pow_mod(a, n>>1, m);
    res = res * res;
    if(res >= m) res %= m;
    if(n & 1){
        res = res * a;
        if(res >= m) res %= m;
    }
    return res;
}
ll get_hash(int idx, int l, int r, ll diff){
    ll res = rolling[idx][r] - (rolling[idx][l-1] * diff) % HASH_M;
    if(res < 0) res += HASH_M;
    return res;
}

unordered_map<long long, int> cnt[2];
//map<ll, int> cnt[2];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cnt[0].clear(), cnt[1].clear();
        int N;
        scanf("%d", &N);
        scanf("%s%s", s[0] + 1, s[1] + 1);
        int len = strlen(s[0] + 1);
        ll diff = pow_mod(HASH_A, N, HASH_M);
        for(int i=0;i<2;i++){
            for(int j=1;j<=len+N+1;j++){
                rolling[i][j] = (rolling[i][j-1] * HASH_A + (ll)(s[i][(j-1)%len+1] - 'a')) % HASH_M;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=1;j<=len;j++){
                ll hash_val = get_hash(i, j, j + N - 1, diff);
                cnt[i][hash_val] = cnt[i][hash_val] + 1;
            }
        }
        ll ans = 0;
        for(auto item: cnt[0]){
            ans += item.second * cnt[1][item.first];
        }
        printf("%lld\n", (long long)ans);
    }
}
