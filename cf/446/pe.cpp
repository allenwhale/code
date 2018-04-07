#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> edge;
vector<edge> edges;
vector<PII> s_edges[500010];
vector<PII> query[500010];
int last[500010];
bool ans[500010];
struct dis{
    int f[500010];
    void init(){
        for(int i = 0 ; i < 500010 ; i++)
            f[i] = i;
    }
    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void merge(int a, int b){
        f[find(a)] = find(b);
    }
};
int main(){
    memset(last, -1, sizeof(last));
    memset(ans, true, sizeof(ans));
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0 ; i < M ; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({{a, b}, c});
        s_edges[c].push_back({a, b});
    }
    int Q;
    scanf("%d", &Q);
    for(int i = 0 ; i < Q ; i++){
        int k;
        scanf("%d", &k);
        while(k--){
            int x;
            scanf("%d", &x);
            x--;
            query[edges[x].second].push_back({x, i});
        }
    }
    dis d[2];
    d[0].init(); d[1].init();
    for(int i = 1 ; i <= 500000 ; i++){
        for(auto &e : query[i]){
            int u = edges[e.first].first.first, v = edges[e.first].first.second, idx = e.second;
            int x = d[0].find(u), y = d[0].find(v);
            if(last[x] != idx) d[1].f[x] = x;
            if(last[y] != idx) d[1].f[y] = y;
            last[x] = last[y] = idx;
            if(d[1].find(x) == d[1].find(y)){
                ans[idx] = false;
            }
            d[1].merge(x, y);
        }
        for(auto &e : s_edges[i]){
            if(d[0].find(e.first) != d[0].find(e.second)){
                d[0].merge(e.first, e.second);
            }
        }
    }
    for(int i = 0 ; i < Q ; i++)
        printf("%s\n", ans[i] ? "YES" : "NO");
    return 0;
}
