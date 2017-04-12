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

int ansGraph[110][110];

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    Dinic d(N + N + 2);
    int source = N + N, target = source + 1;
    int total1 = 0, total2 = 0;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        total1 += x;
        d.add_edge(source, i, x);
    }
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        total2 += x;
        d.add_edge(i + N, target, x);
    }
    for(int i=0;i<N;i++){
        d.add_edge(i, i + N, INT_MAX);
    }
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        d.add_edge(a, b + N, INT_MAX);
        d.add_edge(b, a + N, INT_MAX);
    }
    int flow = d.Solve(source, target);
    bool ans = flow == total1 && total1 == total2;
    if(ans){
        printf("YES\n");
        for(auto e : d.E){
            if(e.v1 != source && e.v1 != target && e.v2 != source && e.v2 != target && e.v1 < e.v2){
                ansGraph[e.v1][e.v2 - N] = e.c - e.f;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ", ansGraph[i][j]);
            }
            puts("");
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
