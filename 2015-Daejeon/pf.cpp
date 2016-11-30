#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

vector<int> ed[MAXN];
int N, M, stk[MAXN], top, dfn[MAXN], low[MAXN], scc[MAXN], vis[MAXN], scc_cnt;
vector<int> scc_graph[MAXN];
int C[MAXN];
void _SCC(int x, int d){
	stk[++top] = x;
	dfn[x] = low[x] = d;
	vis[x] = 1;
	for(int to:ed[x]){
		if(dfn[to] != -1){
			if(vis[to] == 1)
				low[x] = min(low[x], dfn[to]);
		}else{
			_SCC(to, d+1);
			low[x] = min(low[x], low[to]);
		}
	}
	if(low[x] == dfn[x]){
		while(stk[top] != x){
			scc[stk[top]] = scc_cnt;
			vis[stk[top]] = 2;
			top--;
		}
		scc[stk[top]] = scc_cnt++;
		vis[stk[top]] = 2;
		top--;
	}
}
void SCC(){
	memset(dfn, -1, sizeof(dfn));
	memset(low, -1, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(scc, -1, sizeof(scc));
	scc_cnt = 0;
	top = -1;
	for(int i=0;i<N;i++)
		if(dfn[i] == -1)
			_SCC(i, 0);
}
bool flag, flag2;
vector<int> ans;
bool dfs2vis[MAXN];
void DFS2(int p, int s){
    ans.push_back(p);
    dfs2vis[p] = 1;
    for(int i = 0 ; i < (int)ed[p].size() ; i++){
        int u = ed[p][i];
        if(u == s && (ans.size() & 1)){
            flag2 = true;
            return;
        }
        if(scc[u] != scc[p]) continue;
        if(C[u] == -1) continue;
        if(dfs2vis[u] == 1) continue;
        DFS2(u, s);
        if(flag2) return;
    }
    ans.pop_back();
}
void DFS(int p, int color = 0){
    C[p] = color;
    for(int i = 0 ; i < (int)ed[p].size() ; i++){
        int u = ed[p][i];
        if(scc[u] != scc[p]) continue;
        if(C[u] == -1){
            DFS(u, color ^ 1);
        } else {
            if(C[u] == C[p]){
                DFS2(p, p);
                flag = true;
            } else {
                continue;
            }
        }
        if(flag) return;
    }
}
void Solve(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)
        ed[i].clear();
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        ed[a].push_back(b);
    }
    SCC();
    ans.clear();
    flag = flag2 = false;
    for(int i=0;i<scc_cnt;i++)
        scc_graph[i].clear();
    for(int i=0;i<N;i++){
        scc_graph[scc[i]].push_back(i);
    }
    memset(C, -1, sizeof(C));
    memset(dfs2vis, 0, sizeof(dfs2vis));
    for(int i=0;i<scc_cnt;i++){
        if(! flag){
            DFS(scc_graph[i][0]);
        }
    }
    if(flag){
        printf("1\n");
        printf("%d\n", (int)ans.size());
        for(int i = 0 ; i < (int)ans.size() ; i++){
            printf("%d\n", ans[i] + 1);
        }
    } else {
        printf("-1\n");
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
