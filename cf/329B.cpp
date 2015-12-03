#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
char mp[1010][1010];
int dis[1010][1010];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
bool isin(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < M;
}
int main(){
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)
        scanf("%s", mp[i]);
    PI s;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(mp[i][j] == 'E')
                s = {i, j};
    queue<PI> q;
    q.push(s);
    dis[s.f][s.s] = 0;
    int max_dis = 0x3f3f3f3f;
    int ans = 0;
    while(!q.empty()){
        PI now = q.front(); q.pop();
        if(dis[now.f][now.s] > max_dis)
            break;
        if(isdigit(mp[now.f][now.s]))
            ans += mp[now.f][now.s] - '0';
        for(int i=0;i<4;i++){
            int tx = now.f + dx[i], ty = now.s + dy[i];
            if(!isin(tx, ty)) continue;
            if(mp[tx][ty] == 'T') continue;
            if(dis[tx][ty] > dis[now.f][now.s]){
                dis[tx][ty] = dis[now.f][now.s] + 1;
                q.push({tx, ty});
            }
            if(mp[tx][ty] == 'S')
                max_dis = dis[tx][ty];
        }
    }
    printf("%d\n", ans);
    return 0;
}
