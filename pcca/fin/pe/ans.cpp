#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
int N, M;
vector<int> ed[MAXN];
bool vis[MAXN];
bool Check(int x, int p){
    vis[x] = true;
    for(int v : ed[x]){
        if(vis[v] == false){
            if(Check(v, x))
                return true;
        } else if(p != v)
            return true;
    }
    return false;
}
bool Solve(){
    scanf("%d%d", &N, &M);
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<N;i++)
        ed[i].clear();
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for(int i=0;i<N;i++)
        if(vis[i] == false)
            if(Check(i, -1))
                return true;
    return false;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        printf("%s\n", Solve() ? "Yes": "No");
    return 0;
}
