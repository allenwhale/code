#include <bits/stdc++.h>
using namespace std;
void massert(bool x){
    if(!x)while(1);
}
vector<int> ed[100010];
int vis[100010];
int V;
bool dfs(int x){
    if(vis[x] == V)return false;
    if(vis[x] != 0)return true;
    vis[x] = V;
    for(int v : ed[x])
        if(!dfs(v))return false;
    return true;
}
void Solve(){
    int N, M;
    scanf("%d%d", &N, &M);
    massert(1 <= N);
    massert(N <= 10000);
    massert(0 <= M);
    massert(M <= 100000);
    memset(vis, 0, sizeof(vis));
    for(int i = 0 ; i <= N ; i++){
        ed[i].clear();
    }
    for(int i = 0 ; i < M ; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        massert(1 <= a);
        massert(a <= N);
        massert(1 <= b);
        massert(b <= N);
        a--, b--;
        ed[b].push_back(a);
    }
    V = 0;
    for(int i = 0 ; i < N ; i++){
        if(vis[i] == 0){
            V++;
            if(!dfs(i)){
                printf("INVALID\n");
                return;
            }
        }
    }
    printf("VALID\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
