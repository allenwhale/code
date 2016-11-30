#include <bits/stdc++.h>
using namespace std;
int N, S, T;
double Q;
#define sqr(x) ((x)*(x))
struct hill{
    double x, y, z;
    hill operator - (const hill &n) const {
        return {x - n.x, y - n.y, z - n.z};
    }
    double abs() const {
        return sqrt(sqr(x) + sqr(y) + sqr(z));
    }
}h[510];
int s[50], t[50];
struct Dinic{
	struct Edge{
		int v1, v2, f, c;
        double w;
	};
	int N;
	vector<vector<int> >vc;
	vector<Edge> E;
	vector<int> dep;
    vector<double> dis;

	Dinic(int n=0): N(n), vc(vector<vector<int> >(N+1)), dep(vector<int>(N+1)), dis(vector<double>(N+1)) {}
	void add_edge(int a, int b, int c, double w){
		vc[a].push_back(E.size());
		E.push_back({a, b, c, c, w});
		vc[b].push_back(E.size());
		E.push_back({b, a, 0, c, -w});
	}
	int Bfs(int s, int t){
		fill(dep.begin(), dep.end(), -1);
		fill(dis.begin(), dis.end(), 1e15);
		dep[s] = -1;
        dis[s] = 0;
        vector<bool> inq(N+1, false);
        queue<int> q;
		q.push(s);
        inq[s] = true;
		while(!q.empty()){
			auto v = q.front(); q.pop();
            inq[v] = false;
            //printf("f %f\n", v.first);
			for(int i=0;i<(int)vc[v].size();i++){
				Edge e = E[vc[v][i]];
				if(e.f > 0 && dis[e.v2] > dis[v] + e.w){
                    dis[e.v2] = dis[v] + e.w;
					dep[e.v2] = vc[v][i];
                    if(!inq[e.v2]){
                        inq[e.v2]=true;
                        q.push(e.v2);
                    }
				}
			}
		}
		return dep[t];
	}
	pair<double, int> Solve(int s, int t){
		pair<double, int> flow = {0, 0};
		while(Bfs(s, t) != -1){
            int df = INT_MAX;
            int now = t;
            while(now != s){
                df = min(df, E[dep[now]].f);
                now = E[dep[now]].v1;
            }
            now = t;
            while(now != s){
                E[dep[now]].f -= df;
                E[dep[now] ^ 1].f += df;
                now = E[dep[now]].v1;
            }
            flow.second += df;
            flow.first += dis[t] * df;
		}
		return flow;
	}
};
double dist[510][510];
int main(){
    scanf("%d%d%d%lf", &N, &S, &T, &Q);
    for(int i=0;i<N;i++){
        scanf("%lf%lf%lf", &h[i].x, &h[i].y, &h[i].z);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dist[i][j] = 1e100;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(h[i].z > h[j].z && (h[i] - h[j]).abs() < Q){
                dist[i][j] = (h[i] - h[j]).abs();
            }
        }
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    Dinic d(N + 2);
    int source = N, target = N + 1;
    for(int i=0;i<S;i++){
        scanf("%d", &s[i]);
        s[i]--;
        d.add_edge(source, s[i], 1, 0);
    }
    for(int i=0;i<T;i++){
        scanf("%d", &t[i]);
        t[i]--;
        d.add_edge(t[i], target, 1, 0);
    }
    for(int i=0;i<S;i++){
        for(int j=0;j<T;j++){
            if(dist[s[i]][t[j]] <= 1e15)
                d.add_edge(s[i], t[j], 1, dist[s[i]][t[j]]);
        }
    }
    auto ans = d.Solve(source, target);
    if(ans.second == T){
        printf("%.10f\n", ans.first);
    }else{
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
