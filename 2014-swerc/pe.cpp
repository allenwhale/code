#include <bits/stdc++.h>
using namespace std;
#define ID(i, j) ((i) * W + (j))
typedef long long ll;
int N, W, H, L;
int ex, ey;
char mp[15][15], mp2[15][15];
int robots[10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
unordered_map<ll, int> dist;
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < H && y < W;
}
ll encode(){
    ll res = 0;
    for(int i=0;i<N;i++)
        res = res * 100ll + (ll)robots[i];
    return res;
}
void decode(ll x){
    for(int i=N-1;i>=0;i--){
        robots[i] = x % 100;
        x /= 100;
    }
}
int get(ll x){
    if(dist.find(x) == dist.end())
        return INT_MAX;
    return dist[x];
}
int main(){
    scanf("%d%d%d%d", &N, &W, &H, &L);
    for(int i=0;i<H;i++)
        scanf("%s", mp[i]);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if('0' <= mp[i][j] && mp[i][j] <= '9'){
                robots[mp[i][j] - '1'] = ID(i, j);
            }else if(mp[i][j] == 'X'){
                ex = i, ey = j;
            }
        }
    }
    ll state = encode();
    dist[state] = 0;
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
    pq.push({0, state});
    int ans = -1;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(now.first > get(now.second))
            continue;
        decode(now.second);
        if(robots[0] == ID(ex, ey)){
            ans = now.first;
            break;
        }
        if(now.first == L)continue;
        //printf("step: %d\n", now.first);
        //for(int i=0;i<N;i++){
            //printf("%d: %d %d\n", i, robots[i] / W, robots[i] % W);
        //}
        //puts("");
        memset(mp2, '.', sizeof(mp2));
        for(int i=0;i<N;i++)
            mp2[robots[i] / W][robots[i] % W] = i;
        for(int i=0;i<N;i++){
            for(int j=0;j<4;j++){
                int x = robots[i] / W, y = robots[i] % W;
                while(1){
                    int tx = x + dx[j], ty = y + dy[j];
                    if(isin(tx, ty) && mp[tx][ty] != 'W' && mp2[tx][ty] == '.'){
                        x = tx, y = ty;
                    }else break;
                }
                int old = robots[i];
                robots[i] = ID(x, y);
                ll new_state = encode();
                if(get(new_state) > now.first + 1){
                    dist[new_state] = now.first + 1;
                    pq.push({dist[new_state], new_state});
                }
                robots[i] = old;
            }
        }
    }
    if(ans == -1)printf("NO SOLUTION\n");
    else printf("%d\n", ans);
    return 0;
}
