#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int N, M, Q;
typedef pair<int, pair<int, int>> Edge;
vector<pair<int, int>> vc[MAXN], lca_vc[MAXN];
int lca[32][MAXN], lca_len[32][MAXN], dep[MAXN];
bool inqueue[MAXN];
unordered_map<int, int> new_node;
int dist[110][MAXN];
int relabel(int x){
    if(new_node.find(x) == new_node.end())
        new_node[x] = new_node.size() - 1;
    return new_node[x];
}
int f[MAXN];
void djs_init(){
    for(int i=0;i<N;i++)
        f[i] = i;
}
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int a, int b){
    f[find(a)] = find(b);
}

void lca_init(){
    for(int i=0;i<N;i++)
        lca_vc[i].clear();
}
void lca_add(int a, int b, int c){
    //printf("add %d %d %d\n", a,b,c);
    lca_vc[a].push_back({b, c});
    lca_vc[b].push_back({a, c});
}
void lca_dfs(int x, int p, int d){
    dep[x] = d;
    for(auto e : lca_vc[x]){
        if(e.first == p) continue;
        lca_len[0][e.first] = e.second;
        lca[0][e.first] = x;
        //printf("%d %d\n", e.first, lca_len[0][e.first]);
        lca_dfs(e.first, x, d + 1);
    }
}
void lca_build(){
    lca[0][0] = 0;
    lca_len[0][0] = 0;
    lca_dfs(0, 0, 0);
    for(int i=1;i<=17;i++){
        for(int j=0;j<N;j++){
            lca_len[i][j] = lca_len[i-1][j] + lca_len[i-1][lca[i-1][j]];
            lca[i][j] = lca[i-1][lca[i-1][j]];
            //printf("%d %d %d %d \n", i, j, lca_len[i-1][j], lca[i-1][j]);
        }
    }
}
int lca_query(int x, int y){
    if(dep[x] < dep[y])swap(x, y);
    int ans = 0;
    for(int i=17;i>=0;i--){
        if(dep[lca[i][x]] >= dep[y]){
            ans += lca_len[i][x];
            x = lca[i][x];
        }
    }
    //printf("xy %d %d\n", x, y);
    for(int i=17;i>=0;i--){
        if(lca[i][x] != lca[i][y]){
            ans += lca_len[i][x];
            ans += lca_len[i][y];
            x = lca[i][x];
            y = lca[i][y];
        }
    }
    if(x != y){
        ans += lca_len[0][x];
        ans += lca_len[0][y];
    }
    //printf("lca %d\n", lca[0][x]);
    return ans;
}
void init(){
    new_node.clear();
    djs_init();
    lca_init();
    for(int i=0;i<N;i++)
        vc[i].clear();
}
void Solve(){
    unordered_set<int> center;
    vector<Edge> ed;
    scanf("%d%d%d", &N, &M, &Q);
    init();
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        vc[a].push_back({b, c});
        vc[b].push_back({a, c});
        ed.push_back({c, {a, b}});
    }
    for(auto e : ed){
        if(find(e.second.first) != find(e.second.second)){
            lca_add(e.second.first, e.second.second, e.first);
            merge(e.second.first, e.second.second);
        }else{
            //center.insert(e.second.first);
            center.insert(e.second.second);
        }
    }
    for(auto x : center){
        int nx = relabel(x);
        memset(dist[nx], 0x3f, sizeof(dist[nx]));
        memset(inqueue, false, sizeof(inqueue));
        dist[nx][x] = 0;
        queue<int> q;
        q.push(x);
        inqueue[x] = true;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            inqueue[x] = false;
            for(auto e : vc[x]){
                if(dist[nx][e.first] > dist[nx][x] + e.second){
                    dist[nx][e.first] = dist[nx][x] + e.second;
                    if(inqueue[e.first] == false){
                        inqueue[e.first] = true;
                        q.push(e.first);
                    }
                }
            }
        }
    }
    lca_build();
    //for(int i=0;i<4;i++)
        //for(int j=0;j<N;j++)
            //printf("%d %d %d\n", i, j, lca_len[i][j]);
    for(int i=0;i<Q;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        //int ans = 0;
        int ans = lca_query(a, b);
        //printf("  %d\n", ans);
        for(int x : center){
            //printf("%d: %d %d\n", x, dist[relabel(x)][a], dist[relabel(x)][b]);
            ans = min(ans, dist[relabel(x)][a] + dist[relabel(x)][b]);
        }
        printf("%d\n", ans);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case %d:\n", t);
        Solve();
    }
    return 0;
}
