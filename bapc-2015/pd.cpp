#include <bits/stdc++.h>
using namespace std;
int dir[100010][4];
bool vis[100010][2];
void dfs(int p, int x){
    int id = 0;
    for(int i = 0 ; i < 4 ; i++){
        if(dir[x][i] == p)
            id = i;
    }
    if(vis[x][id & 1])return;
    vis[x][id & 1] = true;
    dfs(x, dir[x][(id + 2) % 4]);
}
void Solve(){
    int N, G;
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &N, &G);
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < 4 ; j++)
            scanf("%d", &dir[i][j]);
    }
    int ans = 0;

    dfs(G, dir[G][0]);
    dfs(G, dir[G][1]);
    for(int i = 1; i <= N ; i++){
        if(!vis[i][0]){
            dfs(i, dir[i][0]);
            ans++;
        }
        if(!vis[i][1]){
            dfs(i, dir[i][1]);
            ans++;
        }
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}

