#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int color[MAXN];
vector<int> ed[MAXN];
bool vis[MAXN];
void dfs(int x, int c, bool &w, int &sum, int &all){
    all++;
    sum += c;
    color[x] = c;
    for(auto t : ed[x]){
        if(color[t] == -1){
            dfs(t, c ^ 1, w, sum, all);
        }else if(color[t] == c){
            w = true;
        }
    }
}
int main(){
    memset(color, -1, sizeof(color));
    int N, M;
    scanf("%d%d", &N, &M);
    int fail = false;
    int ans = 0;
    for(int i = 0 ; i < M ; i++){
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        a--, b--;
        if(l == 0){
            if(color[a] == 1 || color[b] == 1)fail = true;
            color[a] = color[b] = 0;
            vis[a] = vis[b] = true;
        }else if(l == 2){
            if(color[a] == 0 || color[b] == 0)fail = true;
            color[a] = color[b] = 1;
            vis[a] = vis[b] = true;
        }else{
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
    }
    for(int i = 0 ; i < N ; i++){
        if(color[i] != -1){
            bool w = false;
            int a = 0, b = 0;
            dfs(i, color[i], w, a, b);
            if(w)fail = true;
        }
    }
    for(int i = 0 ; i < N ; i++)
        if(color[i] == 1)
            ans++;
    for(int i = 0 ; i < N ; i++){
        if(color[i] == -1){
            bool w = false;
            int sum = 0, all = 0;
            dfs(i, 0, w, sum, all);
            ans += min(sum, all - sum);
            if(w)fail = true;
        }
    }

    if(fail)printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}
