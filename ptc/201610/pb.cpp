#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;

bool ok(int m, ll k){
    ll now = 1, sum = 0;
    for(int i = 0 ; i < (int)vec.size() ; i++){
        if(vec[i] > k)return false;
        if( vec[i] + sum > k ){
            now++;
            sum = vec[i];
        } else {
            sum += vec[i];
        }
    }
    return now <= m && sum <= k;
}

void Solve(){
    vec.clear();
    int n, m;
    ll tmp;
    ll step = 0;
    scanf("%d%d", &n, &m);
    ll mn = LLONG_MAX;
    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &tmp);
        vec.push_back(tmp);
        step += tmp;
        mn = min(mn, tmp);
    }
    ll ans = 0, l = mn, r = step;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(ok(m, mid)){
            ans = mid, r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}

