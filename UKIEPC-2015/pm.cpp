#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int M, N;
ll T[1010];
ll X[1010];
int main(){
    scanf("%d%d", &M, &N);
    for(int i=0;i<M;i++)
        scanf("%I64d", &T[i]);
    for(int i=0;i<N;i++)
        scanf("%I64d", &X[i]);
    set<ll> ans;
    for(int i=0;i<N-M+1;i++){
        // sa/sb
        ll sa = X[i + 1] - X[i], sb = T[1] - T[0];
        ll tmp = __gcd(sa, sb);
        sa /= tmp, sb /= tmp;
        bool tf = true;
        //printf("i %d\n", i);
        for(int j=0;j<M-1;j++){
            ll tsa = X[i + j + 1] - X[i + j], tsb = T[j + 1] - T[j];
            tmp = __gcd(tsa, tsb);
            tsa /= tmp, tsb /= tmp;
            //printf("  %lld %lld\n", tsa, tsb);
            if(sa != tsa || sb != tsb){
                tf = false;
                break;
            }
        }
        if(tf){
            ans.insert(X[i + 1] - X[i]);
        }
    }
    printf("%d\n", (int)ans.size());
    for(ll x : ans){
        printf("%I64d ", x);
    }
    puts("");
}
