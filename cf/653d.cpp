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
int N, M, X;
int a[510], b[510], c[510];

bool check(double mid){
    Dinic d(N);
    for(int i=0;i<M;i++)
        d.add_edge(a[i], b[i], min((double)c[i] / mid, (double)X));
    return d.Solve(0, N - 1) >= X;
}

int main(){
    scanf("%d%d%d", &N, &M, &X);
    for(int i=0;i<M;i++){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        a[i]--, b[i]--;
    }
    double l = 0, r = 1000000;
    for(int i=0;i<100;i++){
        double mid = (l + r) / 2.0;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    printf("%.10f\n", l * X);
    return 0;
}
