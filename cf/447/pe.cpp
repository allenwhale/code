#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
typedef long long ll;
typedef pair<int, ll> PIL;
int N, M;
vector<PIL> ed[MAXN];
int stk[MAXN], top, dfn[MAXN], low[MAXN], scc[MAXN], vis[MAXN], scc_cnt, d;
void _SCC(int x){
	stk[++top] = x;
	dfn[x] = low[x] = ++d;
	vis[x] = 1;
	for(auto &to:ed[x]){
		if(dfn[to.first] != -1){
			if(vis[to.first] == 1)
				low[x] = min(low[x], dfn[to.first]);
		}else{
			_SCC(to.first);
			low[x] = min(low[x], low[to.first]);
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
    d = 0;
	for(int i=0;i<N;i++)
		if(dfn[i] == -1)
			_SCC(i);
}
vector<PIL> n_ed[MAXN];
ll node[MAXN];
int S;
ll dp[MAXN];
ll dfs(int x){
    if(dp[x] != -1) return dp[x];
    dp[x] = 0;
    for(auto &e : n_ed[x]){
        dp[x] = max(dp[x], dfs(e.first) + e.second);
    }
    dp[x] += node[x];
    return dp[x];
}
ll sum[2][MAXN];
ll calc(ll x){
    int pos = upper_bound(sum[0], sum[0] + 20000, x) - sum[0];
    return x * (pos) - sum[1][pos - 1];
}
int main(){
    for(int i = 1 ; i < 20000 ; i++){
        sum[0][i] = sum[0][i - 1] + i;
        sum[1][i] = sum[1][i - 1] + sum[0][i];
    }
    scanf("%d%d", &N, &M);
    for(int i = 0 ; i < M ; i++){
        int a, b;
        ll c;
        scanf("%d%d%lld", &a, &b, &c);
        a--, b--;
        ed[a].push_back({b, c});
    }
    scanf("%d", &S);
    SCC();
    memset(node, 0, sizeof(node));
    for(int i = 0 ; i < N ; i++){
        for(auto &e : ed[i]){
            if(scc[i] == scc[e.first]){
                node[scc[i]] += calc(e.second);
            }else{
                n_ed[scc[i]].push_back({scc[e.first], e.second});
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%I64d\n", dfs(scc[S - 1]));
    return 0;
}
