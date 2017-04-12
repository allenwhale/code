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
        //printf("%d %d %d\n", a, b, c);
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

pair<int, int> q[10010];
int main(){
    int N, B, Q;
    scanf("%d%d%d", &N, &B, &Q);
    for(int i=0;i<Q;i++){
        scanf("%d%d", &q[i].first, &q[i].second);
    }
    q[Q] = {B, N};
    q[Q + 1] = {0, 0};
    sort(q, q + Q + 2);
    Dinic d(Q + 1 + 5 + 2);
    int source = Q + 6, target = source + 1;
    bool ok = true;
    for(int i=0;i<5;i++){
        d.add_edge(Q + 1 + i, target, N / 5);
    }
    for(int i=0;i<=Q;i++){
        d.add_edge(source, i, q[i + 1].second - q[i].second);
        ok &= q[i + 1].second >= q[i].second;
        for(int j=0;j<5;j++){
            int l = q[i].first + 1, r = q[i + 1].first;
            l = (l / 5) * 5 + j + (l % 5 > j) * 5;
            r = (r / 5) * 5 + j - (r % 5 < j) * 5;
            if(r > B)r -= 5;
            int f = r >= l ? ((r - l) / 5 + 1) : 0;
            //printf("%d %d %d ", l, r, j);
            //printf("%d\n", f);
            d.add_edge(i, Q + 1 + j, f);
        }
    }
    int flow = d.Solve(source, target);
    //printf("%d\n", flow);
    if(flow == N && ok)
        puts("fair");
    else
        puts("unfair");
    return 0;
}
