#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to, c;
};
vector<Edge> ed[50010];
int bad[50010];
bool done[50010];
void dfs(int x, int p){
    if(done[x])return;
    if(bad[x] == 0){
        bad[x] = p;
        for(auto &e : ed[x]){
            if(e.to != p){
                dfs(e.to, x);
            }
        }
    }else if(bad[x] != p){
        done[x] = true;
        dfs(bad[x], x);
    }
}
int main(){
    memset(bad, 0, sizeof(bad));
    memset(done, false, sizeof(done));
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N - 1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ed[a].push_back({b, c});
        ed[b].push_back({a, c});
    }
    for(int i = 1 ; i <= N ; i++){
        if(done[i])continue;
        unordered_map<int, int> mp;
        unordered_map<int, vector<Edge>> ee;
        for(auto &e : ed[i]){
            mp[e.c]++;
            ee[e.c].push_back(e);
        }
        for(auto &p : mp){
            if(p.second > 1){
                for(auto &e : ee[p.first]){
                    dfs(e.to, i);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= N ; i++){
        ans += (bad[i] == 0);
    }
    printf("%d\n", ans);
    for(int i = 1 ; i <= N ; i++){
        if(!bad[i])
            printf("%d\n", i);
    }
    return 0;
}
