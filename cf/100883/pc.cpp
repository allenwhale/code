#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct coin{
    ll v, total;
    coin(ll _v=0, ll _t=0): v(_v), total(_t){}
    bool operator < (const coin &n) const {
        if(total == n.total)
            return v < n.v;
        return total < n.total; 
    }
};
int cnt[1000010];
void Solve(){
    memset(cnt, 0, sizeof(cnt));
    int C, M;
    scanf("%d%d", &C, &M);
    ll sum = 0;
    for(int i=0;i<C;i++){
        int c;
        scanf("%d", &c);
        sum += (ll)c;
        cnt[c]++;
    }
    if(sum < M){
        puts("Impossible");
        return;
    }
    priority_queue<coin> pq;
    for(int i=1;i<=1000000;i++){
        if(cnt[i]){
            pq.push(coin(i, cnt[i] * i));
        }
    }
    ll now = 0;
    vector<int> ans;
    while(now < M){
        coin c = pq.top();
        pq.pop();
        now += c.total;
        ans.push_back(c.v);
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<(int)ans.size();i++)
        printf("%d ", ans[i]);
    puts("");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}
