#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
#define f first
#define s second
int H, W, C;
int mp[10][10];
bool vis[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < H && y < W;
}
int ans;
vector<PI> bfs(){
    vector<PI> vc;
    memset(vis, false, sizeof(vis));
    vc.push_back({0, 0});
    queue<PI> q;
    q.push({0, 0});
    vis[0][0] = true;
    while(!q.empty()){
        auto now = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int x = now.f + dx[i], y = now.s + dy[i];
            if(isin(x, y) && !vis[x][y] && mp[x][y] == mp[0][0]){
                q.push({x, y});
                vis[x][y] = true;
                vc.push_back({x, y});
            }
        }
    }
    return vc;
}
void dfs(int dep){
    vector<PI> vc = bfs();
    if(dep == 5){
        if(mp[0][0] == C){
            ans = max(ans, (int)vc.size());
        }
    }else{
        int ori = mp[0][0];
        for(int i=1;i<=6;i++){
            for(auto n: vc)
                mp[n.f][n.s] = i;
            dfs(dep + 1);
        }
        for(auto n: vc)
            mp[n.f][n.s] = ori;
    }
}
int Solve(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            scanf("%d", &mp[i][j]);
        }
    }
    ans = 0;
    dfs(0);
    return ans;
}

int main(){
    while(~scanf("%d%d%d", &H, &W, &C) && H && W && C){
        printf("%d\n", Solve());
    }
}
