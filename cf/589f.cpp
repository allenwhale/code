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
int N;
vector<int> v;
int s[110], e[110];
bool check(int x){
    Dinic d(N + (v.size() - 1) + 2);
    int source = N + (v.size() - 1), target = source + 1;
    for(int i=0;i<N;i++){
        d.add_edge(source, i, x);
    }
    for(int i=0;i<(int)v.size()-1;i++){
        d.add_edge(N + i, target, v[i + 1] - v[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<(int)v.size()-1;j++){
            if(v[j] < e[i] || s[i] < v[j + 1]){
                d.add_edge(i, N + j, min(e[i], v[j + 1]) - max(s[i], v[j]));
            }
        }
    }
    return d.Solve(source, target) == x * N;
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d%d", &s[i], &e[i]);
        v.push_back(s[i]);
        v.push_back(e[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int l = 0, r = v[v.size() - 1] - v[0], ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    printf("%d\n", ans * N);
    return 0;
}
