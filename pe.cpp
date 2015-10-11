#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
#define FF first
#define SS second
class Edge {
public:
    int to, w;
    Edge(int t=0, int _w=0): to(t), w(_w) {}
};
class Graph {
public:
    int N, M;
    vector<vector<Edge> > vc;
    Graph(int n=0): N(n), M(0), vc(vector<vector<Edge> >(N)){}
    vector<int> vis;
    /* for dijkstra */
    vector<int> dis;

    void add_edge(int f, Edge e){
        vc[f].push_back(e);
        M++;
    }
    int Dijkstra(int s, int t){
        const int INF = 0x3f3f3f3f;
        dis = vector<int>(N+1, INF);
        priority_queue<PI, vector<PI>, greater<PI>> pq;
        dis[s] = 0;
        pq.push(PI(0, s));
        while(!pq.empty()){
            PI v = pq.top();
            pq.pop();
            if(v.FF > dis[v.SS])continue;
            if(v.SS == t)return dis[t];
            for(int i=0;i<(int)vc[v.SS].size();i++){
                Edge e = vc[v.SS][i];
                if(dis[e.to] > dis[v.SS] + e.w){
                    dis[e.to] = dis[v.SS] + e.w;
                    pq.push(PI(dis[e.to], e.to));
                }
            }
        }
        return -1;
    }
    void AllDijkstra(int s){
        const int INF = 0x3f3f3f3f;
        dis = vector<int>(N+1, INF);
        priority_queue<PI, vector<PI>, greater<PI>> pq;
        dis[s] = 0;
        pq.push(PI(0, s));
        while(!pq.empty()){
            PI v = pq.top();
            pq.pop();
            if(v.FF > dis[v.SS])continue;
            for(int i=0;i<(int)vc[v.SS].size();i++){
                Edge e = vc[v.SS][i];
                if(dis[e.to] > dis[v.SS] + e.w){
                    dis[e.to] = dis[v.SS] + e.w;
                    pq.push(PI(dis[e.to], e.to));
                }
            }
        }
    }
    int KthShortestPath(int s, int t, int k){
        Graph RG(N);
        for(int i=0;i<N;i++)
            for(int j=0;j<(int)vc[i].size();j++){
                Edge e = vc[i][j];
                RG.add_edge(e.to, Edge(i, e.w));
            }
        RG.AllDijkstra(t);
        dis = RG.dis;
        priority_queue<PI> pq;
        pq.push(PI(-dis[s], s));
        int ans[2];
        while(!pq.empty()){
            PI v = pq.top();
            pq.pop();
            int real = -v.FF - dis[v.SS];
            if(v.SS == t){
                ans[--k] = real;
                if(!k)return ans[0] == ans[1];
            }
            for(int i=0;i<(int)vc[v.SS].size();i++){
                Edge e = vc[v.SS][i];
                pq.push(PI(-(real+e.w+dis[e.to]), e.to));
            }
        }
        return 0;
    }
};
int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    while(K--)scanf("%*d");
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        G.add_edge(a,{b,c});
        G.add_edge(b,{a,c});
    }
    if(G.KthShortestPath(0,N-1,2))
        puts("yes");
    else puts("no");
    return 0;
}
