#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[100010], h[100010];
void Solve(){
    int N;
    scanf("%d", &N);
    vector<ll> ans;
    ans.push_back(0);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &l[i]);
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &h[i]);
    }
    vector<pair<ll, ll> > stk;
    stk.push_back({INT_MAX, -1});
    ll sum = 0;
    ll wall = 0;
    for(int i = 0 ; i < N ; i++){
        while(stk.size() && stk.back().first < h[i]){
            sum -= stk.back().first * (stk.back().second - stk[stk.size() - 2].second - 1);
            wall += stk.back().first;
            stk.pop_back();
        }
        stk.push_back({h[i], l[i]});
        sum += stk.back().first * (stk.back().second - stk[stk.size() - 2].second - 1);
        ans.push_back(sum - wall);
    }
    //for(int x : ans)
        //printf(" %d\n", x);
    int Q;
    scanf("%d", &Q);
    while(Q--){
        ll k;
        scanf("%lld", &k);
        printf("%d\n", int(lower_bound(ans.begin(), ans.end(), k) - ans.begin() - 1));
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
}
