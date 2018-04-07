#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to, c, d;
};
vector<Edge> ed[1010];
int S, T;
bool vis[1010];
bool bsf(int l, int r){
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == T)return true;
        for(auto &e : ed[now]){
            if(!vis[e.to] && e.c <= l && r <= e.d){
                q.push(e.to);
                vis[e.to] = true;
            }
        }
    }
    return false;
} 
int main(){
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    scanf("%d%d", &S, &T);
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(K);
    for(int i = 0 ; i < M ; i++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ed[a].push_back({b, c, d});
        pos.push_back(c);
        pos.push_back(d);
    }
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    int ans = 0;
    for(int i = 0 ; i < (int)pos.size() - 1 ; i++){
        if(bsf(pos[i] + 1, pos[i + 1] - 1))ans += pos[i + 1] - pos[i] - 1;
    }
    for(int i = 0 ; i < (int)pos.size() ; i++){
        if(bsf(pos[i], pos[i]))ans++;
    }
    printf("%d\n", ans);
    return 0;
}
