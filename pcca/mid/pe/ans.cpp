#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define MAXN 500000
#define HASH_A 137ll
#define HASH_M 68720001023ll 
#define _HASH_A 29
#define _HASH_M 101
struct pair_hash {
    inline ll operator() (const pair<ll, ll> & v) const {
        return v.first ^ v.second;
    }
};

char s[2][(MAXN<<1)+10];
ll rolling[2][2][(MAXN<<1)+10];
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
pair<ll, ll> get_hash(int idx, int l, int r, ll diff, ll _diff){
    ll res = rolling[idx][0][r] - (rolling[idx][0][l-1] * diff) % HASH_M;
    ll _res = rolling[idx][1][r] - (rolling[idx][1][l-1] * _diff) % _HASH_M;
    if(res < 0) res += HASH_M;
    if(_res < 0) _res += _HASH_M;
    return {res, _res};
}
unordered_map<pair<ll, ll>, ll, pair_hash> cnt;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cnt.clear();
        int N;
        scanf("%d%s%s", &N, s[0] + 1, s[1] + 1);
        int len = strlen(s[0] + 1);
        ll diff = pow_mod(HASH_A, N, HASH_M);
        ll _diff = pow_mod(_HASH_A, N, _HASH_M);
        for(int i=0;i<2;i++)
            for(int j=1;j<=N;j++)
                s[i][j+len] = s[i][j];
        for(int i=0;i<2;i++){
            for(int j=1;j<=len+N+1;j++){
                rolling[i][0][j] = (rolling[i][0][j-1] * HASH_A + (ll)(s[i][j] - 'a')) % HASH_M;
                rolling[i][1][j] = (rolling[i][1][j-1] * _HASH_A + (ll)(s[i][j] - 'a')) % _HASH_M;
            }
        }
        for(int j=1;j<=len;j++)
            cnt[get_hash(0, j, j + N - 1, diff, _diff)] += 1;
        ll ans = 0;
        for(int j=1;j<=len;j++)
            ans += cnt[get_hash(1, j, j + N - 1, diff, _diff)];
        printf("%lld\n", (long long)ans);
    }
}
