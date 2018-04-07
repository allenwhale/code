#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
    int a, b, c;
    bool operator < (const Edge &n) const {
        return c < n.c;
    }
};
vector<Edge> ed[100010];
vector<Edge> edges;
int p[100010];
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int a, int b){
    p[find(a)] = find(b);
}
void dfs(int x, int b, int last_c, int max_c, int now, int &ans){
    if(x == b){
        ans = now;
        return;
    } 
    for(auto &e : ed[x]){
        if(e.c != last_c && e.c < max_c){
            dfs(e.b, b, e.c, max_c, now + 1, ans);
        }
    }
}

int main(){
    int N, M, A;
    scanf("%d%d%d", &N, &M, &A);
    for(int i = 1 ; i <= N ; i++)
        p[i] = i;
    for(int i = 0 ; i < M ; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ed[a].push_back({a, b, c});
        ed[b].push_back({b, a, c});
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    int ans = -1;
    for(auto &e : edges){
        if(find(e.a) != find(e.b)){
            merge(e.a, e.b);
        }else{
            dfs(e.a, e.b, -1, e.c, 0, ans);
            ans++;
            printf("%lld\n", (ll)e.c * (ll)e.c + (ll)A * ans);
            return 0;
        }
    }
    printf("Poor girl\n");
    return 0;
}
