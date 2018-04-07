#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
ll L[1000010];
valarray<ll> ed[1000010], sum[1000010];
valarray<ll> dfs(int x){
    if(x > N) return valarray<ll>();
    auto v1 = dfs(x * 2), v2 = dfs(x * 2 + 1);
    v1 += L[x * 2 - 1];
    v2 += L[x * 2 + 1 - 1];
    ed[x].resize(v1.size() + v2.size() + 1);
    ed[x][0] = 0;
    merge(begin(v1), end(v1), begin(v2), end(v2), begin(ed[x]) + 1);
    sum[x] = ed[x];
    for(int i = 1 ; i < (int)ed[x].size() ; i++)
        sum[x][i] += sum[x][i - 1];
    return ed[x];
}
ll query(int x, int h, int p = 0){
    if(x == 0)return 0;
    if(h <= 0) return 0;
    if(p == 0){
        int pos = lower_bound(begin(ed[x]), end(ed[x]), h) - begin(ed[x]);
        return -sum[x][pos - 1] + (ll)pos * h + query(x / 2, h - L[x - 1], x);
    }else{
        ll res = h;
        if(x * 2 != p && x * 2 <= N && L[x * 2 - 1] < h){
            int pos = lower_bound(begin(ed[x * 2]), end(ed[x * 2]), h - L[x * 2 - 1]) - begin(ed[x * 2]);
            res += -sum[x * 2][pos - 1] + (ll)pos * (h - L[x * 2 - 1]);
        }else if(x * 2 + 1 != p && x * 2 + 1 <= N && L[x * 2 + 1 - 1] < h){
            int pos = lower_bound(begin(ed[x * 2 + 1]), end(ed[x * 2 + 1]), h - L[x * 2 + 1 - 1]) - begin(ed[x * 2 + 1]);
            res += -sum[x * 2 + 1][pos - 1] + (ll)pos * (h - L[x * 2 + 1 - 1]);
        }
        res += query(x / 2, h - L[x - 1], x);
        return res;
    }
}
int main(){
    scanf("%d%d", &N, &M);
    for(int i = 1 ; i < N ; i++)
        scanf("%lld", &L[i]);
    dfs(1);
    while(M--){
        int A;
        ll H;
        scanf("%d%lld", &A, &H);
        printf("%lld\n", query(A, H, 0));
    }
    return 0;
}
