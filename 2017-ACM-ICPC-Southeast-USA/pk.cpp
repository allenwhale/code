#include <bits/stdc++.h>
using namespace std;
#define MAXN 5000
/*
 * solve the strongly connected component(SCC)
 * store answer in scc
 * the value of scc[i] means the id of the SCC which i-th node in (id is based 0)
 * scc_cnt is the number of SCC
 */
vector<int> ed[MAXN];
int N, stk[MAXN], top, dfn[MAXN], low[MAXN], scc[MAXN], vis[MAXN], scc_cnt;
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
	for(int i=1;i<=N;i++)
		if(dfn[i] == -1)
			_SCC(i, 0);
}
int norm(int x, int n){
    if(x < 0)x = n + abs(x);
    return x;
}
int inv(int x, int n){
    if(x > n)return x - n;
    return x + n;
}
set<int> f[MAXN], t[MAXN];
unordered_set<int> ned[MAXN];
bool fv[MAXN];
void dfs(int x){
    if(fv[x])return;
    fv[x] = true;
    for(int to : ned[x]){
        dfs(to);
        for(auto y : f[to])
            f[x].insert(y);
        for(auto y : t[x])
            t[to].insert(y);
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    N = n * 2;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(abs(a) == abs(b)){
            if(a == b)
                ed[inv(norm(a, n), n)].push_back(norm(b, n));
        }else{
            ed[inv(norm(a, n), n)].push_back(norm(b, n));
            ed[inv(norm(b, n), n)].push_back(norm(a, n));
        }
    }
    SCC();
    for(int i = 1; i <= n ; i++){
        if(scc[i] == scc[inv(i, n)]){
            printf("0\n");
            return 0;
        }
    }
    for(int i = 1 ; i <= N ; i++){
        for(int to : ed[i]){
            ned[scc[i]].insert(scc[to]);
            f[scc[i]].insert(to);
            t[scc[to]].insert(i);
        }
    }
    for(int i = 1 ; i <= N ; i++)
        dfs(scc[i]);
    vector<int> work(N);
    for(int i = 1; i <= n ; i++){
        int a = - 1, b = -1;
        auto eit = set_intersection(f[scc[i]].begin(), f[scc[i]].end(), f[scc[inv(i, n)]].begin(), f[scc[inv(i, n)]].end(), work.begin());
        for(auto it = work.begin() ; it != eit ; ++it){
            if(*it > n){
                a = *it;
                break;
            }
        }
        if(a == -1)continue;
        eit = set_intersection(t[scc[i]].begin(), t[scc[i]].end(), t[scc[inv(i, n)]].begin(), t[scc[inv(i, n)]].end(), work.begin());
        for(auto it = work.begin() ; it != eit ; ++it){
            if(*it <= n){
                b = *it;
                break;
            }
        }
        if(b == -1)continue;
        printf("1\n");
        //printf("%d %d\n", a - n, b);
        return 0;
    }
    for(int i = 1 ; i <= n ; i++){
        int a = -1, b = -1, c = -1, d = -1;
        for(int x : f[scc[i]]){
            if(x > n){
                a = x;
                break;
            }
        }
        if(a == -1)continue;
        for(int x : f[scc[inv(i, n)]]){
            if(x > n){
                b = x;
                break;
            }
        }
        if(b == -1)continue;
        for(int x : t[scc[i]]){
            if(x <= n){
                c = x;
                break;
            }
        }
        if(c == -1)continue;
        for(int x : t[scc[inv(i, n)]]){
            if(x <= n){
                d = x;
                break;
            }
        }
        if(d == -1)continue;
        printf("2\n");
        //printf("%d %d\n", a - n, d);
        //printf("%d %d\n", b - n, c);
        return 0;
    }
    printf("-1\n");
    return 0;
}
