#include <bits/stdc++.h>
using namespace std;
struct status{
    int x, y, time;
};
struct position{
    int x, y;
    bool operator < (const position &n) const {
        if(x == n.x)
            return y < n.y;
        return x < n.x;
    }
    int operator () (const position &n) const {
        return n.x * 61 + n.y;
    }
    bool operator == (const position &n) const {
        return x == n.x && y == n.y;
    }
};
int R, C;
int dp[61][61][1024];
position master[210][32];
int master_step[210];
int master_num;
char mp[70][70];
int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 0};
bool isin(int x, int y){
    return x > 0 && y > 0 && x <= R && y <= C;
}
int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}
unordered_set<position, position> now_master[1024];
int max_time;
bool isalive(const status &s){
    for(int i=0;i<4;i++){
        int x = s.x, y = s.y;
        while(isin(x, y) && mp[x][y] == '.'){
            if(now_master[s.time % max_time].find({x, y}) != now_master[s.time % max_time].end()){
                return false;
            }
            x += dx[i], y += dy[i];
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &R, &C);
    int sx, sy, ex, ey;
    scanf(" (%d %d) ", &sx, &sy);
    scanf(" (%d %d) ", &ex, &ey);
    for(int i=1;i<=R;i++){
        scanf("%s", mp[i] + 1);
    }
    scanf("%d", &master_num);
    max_time = 1;
    for(int i=0;i<master_num;i++){
        scanf("%d", &master_step[i]);
        for(int j=0;j<master_step[i];j++){
            scanf(" (%d %d) ", &master[i][j].x, &master[i][j].y);
        }
        for(int j=0;j<master_step[i]-2;j++){
            master[i][master_step[i] + j] = master[i][master_step[i] - j - 2];
        }
        if(master_step[i] != 1)
            master_step[i] = master_step[i] * 2 - 2;
        max_time = lcm(max_time, master_step[i]);
    }
    for(int i=0;i<max_time;i++){
        for(int j=0;j<master_num;j++){
            now_master[i].insert(master[j][i % master_step[j]]);
        }
    }
    if(!isalive({sx, sy, 0})){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    queue<status> q;
    memset(dp, 0x3f, sizeof(dp));
    q.push({sx, sy, 0});
    dp[sx][sy][0] = 0;
    while(!q.empty()){
        status now = q.front();
        q.pop();
        if(now.x == ex && now.y == ey){
            printf("%d\n", dp[now.x][now.y][now.time]);
            return 0;
        }
        if(!isalive(now))continue;
        for(int i=0;i<5;i++){
            status next = {now.x + dx[i], now.y + dy[i], (now.time + 1) % max_time};
            if(isin(next.x, next.y) && mp[next.x][next.y] == '.' && dp[next.x][next.y][next.time] > dp[now.x][now.y][now.time] + 1){
                dp[next.x][next.y][next.time] = dp[now.x][now.y][now.time] + 1;
                q.push(next);
            }
        }
    }
    printf("IMPOSSIBLE\n");

    return 0;
}
