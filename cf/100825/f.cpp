#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int sn = 0;
int S, R, F, T;
char in[1010];
int get(const string &x){
    if(mp.find(x) == mp.end())
        mp[x] = sn++;
    return mp[x];
}
struct Dinic{
    struct Edge{
        int v1, v2, f, c;
    };
    int N;
    vector<vector<int> >vc;
    vector<Edge> E;
    vector<int> dep;

    Dinic(int n=0): N(n), vc(vector<vector<int> >(N+1)), dep(vector<int>(N+1)) {}
    void add_edge(int a, int b, int c){
        vc[a].push_back(E.size());
        E.push_back({a, b, c, c});
        vc[b].push_back(E.size());
        E.push_back({b, a, 0, c});
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
    scanf("%d%d%d%d", &S, &R, &F, &T);
    int source = S + 2 * T, target = S + 2 * T + 1;
    Dinic dinic(S + 2 * T + 2);
    for(int i=0;i<R;i++){
        scanf("%s", in);
        dinic.add_edge(source, get(in), 1);
    }
    for(int i=0;i<F;i++){
        scanf("%s", in);
        dinic.add_edge(get(in), target, 1);
    }
    for(int i=0;i<T;i++){
        dinic.add_edge(S + i, S + T + i, 1);
        int num;
        scanf("%d", &num);
        while(num--){
            scanf("%s", in);
            dinic.add_edge(get(in), S + i, 1);
            dinic.add_edge(S + T + i, get(in), 1);
        }
    }
    printf("%d\n", dinic.Solve(source, target));
    return 0;
}
