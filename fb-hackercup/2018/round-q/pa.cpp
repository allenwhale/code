#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char attrs[100][100];

void Solve(){
    ll N, K, V;
    scanf("%lld%lld%lld", &N, &K, &V);
    for(int i = 0 ; i < N ; i++){
        scanf("%s", attrs[i]);
    }
    int now = (K * (V - 1)) % N;
    vector<int> ans;
    for(int i = 0 ; i < K ; i++, now = (now + 1) % N)
        ans.push_back(now);
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < K ; i++)
        printf(" %s", attrs[ans[i]]);
    puts("");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d:", i);
        Solve();
    }
    return 0;
}
