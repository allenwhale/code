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
int g[110][110];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
bool isok(int x, int y){
    return x >=0 && y >= 0 && x < N && y < M;
}
void Solve(){
    scanf("%d%d", &N, &M);
    int sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &g[i][j]);
            sum += g[i][j];
        }
    }
    Dinic d(2 + N * M);
    int source = N * M, target = source + 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if((i + j) & 1){
                d.add_edge(source, i * M + j, g[i][j]);
            }else{
                d.add_edge(i * M + j, target, g[i][j]);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                int ti = i + dx[k], tj = j + dy[k];
                if(isok(ti, tj)){
                    if((i + j) & 1){
                        d.add_edge(i * M + j, ti * M + tj, INT_MAX);
                    }
                }
            }
        }
    }
    printf("%d\n", sum - d.Solve(source, target));
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
