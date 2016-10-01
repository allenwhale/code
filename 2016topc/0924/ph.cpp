#include <bits/stdc++.h>
using namespace std;
struct Dinic{
    struct Edge{
        int v1, v2, f, c;
    };
    int N;
    vector<vector<int> >vc;
    vector<Edge> E;
    vector<int> dep;

    Dinic(int n=0): N(n), vc(vector<vector<int> >(N+1)), dep(vector<int>(N+1)) {}
    void add_edge(int a, int b, int c, int d=0){
        vc[a].push_back(E.size());
        E.push_back({a, b, c, c});
        vc[b].push_back(E.size());
        E.push_back({b, a, !d?c:0, c});
    }
    int Bfs(int s, int t){
        fill(dep.begin(), dep.end(), -1);
        dep[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int i=0;i<(int)vc[v].size();i++){
                Edge e = E[vc[v][i]];
                if(e.f > 0 && dep[e.v2] == -1){
                    dep[e.v2] = dep[v] + 1;
                    q.push(e.v2);
                }
            }
        }
        return dep[t];
    }
    int Dfs(int x, int df, int t){
        if(x == t) return df;
        int res = 0;
        for(int i=0;i<(int)vc[x].size();i++){
            Edge &e = E[vc[x][i]];
            if(e.f > 0 && dep[e.v2] == dep[x] + 1){
                int f = Dfs(e.v2, min(df, e.f), t);
                e.f -= f; df -= f; res += f;
                E[vc[x][i] ^ 1].f += f;
                if(df == 0) return res;
            }
        }
        if(res == 0) dep[x] = -1;
        return res;
    }
    int Solve(int s, int t){
        int flow = 0;
        while(Bfs(s, t) != -1){
            flow += Dfs(s, 0x3f3f3f3f, t);
        }
        return flow;
    }
};

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int V, E;
        scanf("%d%d", &V, &E);
        Dinic d(V);
        for(int i=0;i<E;i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            d.add_edge(a, b, c);
        }
        int sum = d.Solve(0, V-1);
        Dinic d2(V);
        for(auto e:d.E){
            if(e.f < e.c)
                //printf("%d %d\n", e.v1, e.v2),
                d2.add_edge(e.v1, e.v2, e.c, 1);
        }
        d2.Solve(0, V-1);
        Dinic d3(V);
        for(auto e:d2.E){
            if(e.f == 0)
                d3.add_edge(e.v1, e.v2, 1, 1);
            else
                d3.add_edge(e.v1, e.v2, 0x3f3f3f3f ,1);
        }
        int cnt = d3.Solve(0, V-1);
        printf("%d %d\n", sum, cnt);
    }
}
