#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll R, B, C;
ll M[1010], S[1010], P[1010];

bool check(ll t){
    ll total = 0;
    vector<int> each;
    for(int i = 0 ; i < C ; i++){
        each.push_back(min(M[i], max(0ll, t - P[i]) / S[i]));
    }
    sort(each.begin(), each.end());
    for(int i = C - R ; i < C ; i++)
        total += each[i];
    return total >= B;
}

void Solve(){
    scanf("%lld%lld%lld", &R, &B, &C);
    ll mn = 0, mx = LLONG_MAX >> 1;
    for(int i = 0 ; i < C ; i++){
        scanf("%lld%lld%lld", &M[i], &S[i], &P[i]);
    }
    ll ans = 0;
    while(mn <= mx){
        ll mid = (mn + mx) >> 1;
        if(check(mid)){
            ans = mid;
            mx = mid - 1;
        }else{
            mn = mid + 1;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
