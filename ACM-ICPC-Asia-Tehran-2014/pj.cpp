#include <bits/stdc++.h>
using namespace std;
class Dinic{
    public:
        class Edge{
            public:
                int v1, v2, f, c;
                Edge(int _v1=0, int _v2=0, int _f=0, int _c=0): v1(_v1), v2(_v2), f(_f), c(_c){}
        };
        int N;
        vector<vector<int> >vc;
        vector<Edge> E;
        vector<int> dep;

        Dinic(int n=0): N(n), vc(vector<vector<int> >(N+1)), dep(vector<int>(N+1)) {}
        void add_edge(int a, int b, int c){
            vc[a].push_back(E.size());
            E.push_back(Edge(a, b, c, c));
            vc[b].push_back(E.size());
            E.push_back(Edge(b, a, 0, c));
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
                    e.f -= f;
                    E[vc[x][i]^1].f += f;
                    df -= f;
                    res += f;
                }
            }
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
vector<int> car[510];
double expect[510];
int N, D, P;
bool check(int add){
    Dinic dinic(N+D+2);
    int source = N+D, target = N+D+1;
    for(int i=0;i<D;i++){
        dinic.add_edge(source, i, 1);
    }
    for(int i=0;i<D;i++){
        for(int p: car[i]){
            dinic.add_edge(i, D+p, 1);
        }
    }
    for(int i=0;i<N;i++){
        int afford = int((expect[i] + (double)add) / (double)P);
        dinic.add_edge(D+i, target, afford);
    }
    return dinic.Solve(source, target) >= D;
}
bool Solve(){
    if(scanf("%d%d%d", &N, &D, &P) != 3) return false;
    if(N == 0)return false;
    for(int i=0;i<N;i++)
        expect[i] = 0.;
    for(int i=0;i<D;i++){
        car[i].clear();
        int num;
        scanf("%d", &num);
        for(int j=0;j<num;j++){
            int p;
            scanf("%d", &p);
            p--;
            car[i].push_back(p);
            expect[p] += (double)P / (double)num;
        }
    }
    int l = 0, r = P*D, ans = -1;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return true;
}

int main(){
    while(Solve());
    return 0;
}
