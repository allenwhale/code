#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll,ll> PI;
typedef pair<PI,int> PII;
vector<PI> island;
vector<PII> gap;
set<PI> bridge;
vector<int>ans;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    ans=vector<int>(N);
    for(int i=0;i<N;i++){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        island.push_back({l,r}); 
    }
    sort(island.begin(),island.end());
    for(int i=1;i<(int)island.size();i++){
        gap.push_back({{island[i].f-island[i-1].s,island[i].s-island[i-1].f},i});
    }
    sort(gap.begin(), gap.end(), [](const PII &a, const PII &b){
        if(a.f.s==b.f.s)
            return a.f.f<b.f.f;
        return a.f.s<b.f.s;
    });
    for(int i=0;i<M;i++){
        ll b;
        scanf("%lld", &b);
        bridge.insert({b,i+1});
    }
    for(int i=0;i<(int)gap.size();i++){
        auto it=bridge.lower_bound({gap[i].f.f, -100000000});
        if(it==bridge.end()||it->f>gap[i].f.s){
            puts("No");
            return 0;
        }
        bridge.erase(it);
        ans[gap[i].s]=it->s;
    }
    puts("Yes");
    for(int i=1;i<N;i++)
        printf("%d%c",ans[i],i==N-1?'\n':' ');
    return 0;
}
