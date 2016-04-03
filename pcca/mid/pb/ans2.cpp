#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define s second
#define f first
typedef pair<int, int> PI;
vector<PI> vc[MAXN+10];
bool vis[MAXN+10];
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vc[a].push_back({c, b});
        vc[b].push_back({c, a});
    }
    memset(vis, false, sizeof(vis));
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    pq.push({0, 0});
    int ans = 0, cnt = 0;
    while(!pq.empty()){
        PI now = pq.top(); pq.pop();
        if(vis[now.s] == true) continue;
        ans += now.f;
        cnt++;
        vis[now.s] = true;
        for(PI e: vc[now.s]){
            if(vis[e.s] == false){
                pq.push(e);
            }
        }
    }
    printf("%d\n", cnt == N ? ans : -1);
    return 0;
}
