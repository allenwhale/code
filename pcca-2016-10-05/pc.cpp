#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
ll F[100010];
ll A, B, M, N;
unordered_map<ll, int> mp;
ll f(int x){
    if(x == 1) return F[1];
    return F[x] = (A * F[x-1] + B) % M + 2;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        mp.clear();
        scanf("%lld%lld%lld%lld%lld", &N, &M, &A, &B, &F[1]);
        mp[F[1]] = 1;
        int start = INT_MAX, end = INT_MAX;
        for(ll i=2;i<=N;i++){
            F[i] = (A * F[i - 1] + B) % M + 2;
            if(mp.find(F[i]) != mp.end()){
                start = mp[F[i]], end = i;
                break;
            }else{
                mp[F[i]] = i;
            }
        }
        ll len = end - start;
        //printf("%d %d %d\n", start, end, len);
        ll ans = 0;
        for(auto item: mp){
            ll pos = item.s;
            //printf("pos %d\n", pos);
            if(pos < start){
                ans ^= (item.f - 2);
                //printf("1   %lld\n", item.f);
            }else{
                ll k = (N - pos) / len  + 1;
                //printf("%d %lld\n", k, item.f);
                if(k & 1){
                    //printf("2   %lld\n", item.f);
                    ans ^= (item.f - 2);
                }
            }
        }
        if(ans)printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
