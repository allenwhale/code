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
unordered_set<int> X;
struct Edge{
    int to, p, t;
};
vector<Edge> ed[1010];
int N;
int I, G, S;
void Solve(){
    Dinic dinic;
    dinic = Dinic(1000 * 101 + 10);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        ed[i].clear();
    scanf("%d%d%d", &I, &G, &S);
    I--;
    int M;
    scanf("%d", &M);
    X.clear();
    for(int i = 0 ; i < M ; i++){
        int x;
        scanf("%d", &x);
        x--;
        X.insert(x);
    }
    int R;
    scanf("%d", &R);
    for(int i = 0 ; i < R ; i++){
        int a, b, p, t;
        scanf("%d%d%d%d", &a, &b, &p, &t);
        a--, b--;
        for(int j = 0 ; j < S - t ; j++){
            dinic.add_edge(a + j * 1000, b + (j + t) * 1000, p);
        }
        //ed[a].push_back({b, p, t});
        //ed[b].push_back({a, p, t});
    }
    //dfs(I, -1, 0, dinic);
    int source = 1000 * 101 + 1;
    int target = source + 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < S ; j++){
            dinic.add_edge(i + j * 1000, i + (j + 1) * 1000, G);
        }
    }
    for(auto x : X)
        for(int i = 0 ; i <= S ; i++)
            dinic.add_edge(x + i * 1000, target, 10000);
    dinic.add_edge(source, I, G);
    int ans = dinic.Solve(source, target);
    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
