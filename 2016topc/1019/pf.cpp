#include <bits/stdc++.h>
using namespace std;
int mp[4500][4500];
char in[2100];
int f[4500*4500+10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int a, int b){
    f[find(b)] = find(a);
}
void Solve(){
    memset(mp, 0, sizeof(mp));
    int x = 0, y = 0;
    int l = 0, r = 0, u = 0, d = 0;
    fgets(in, 2100, stdin);
    int len = strlen(in);
    for(int i=0;i<len - 1;i++){
        if(in[i] == 'L'){
            y-=2;
        }else if(in[i] == 'R'){
            y+=2;
        }else if(in[i] == 'U'){
            x-=2;
        }else if(in[i] == 'D'){
            x+=2;
        }
        l = min(l, y);
        r = max(r, y);
        u = min(u, x);
        d = max(d, x);
    }
    x = -u + 4;
    y = -l + 4;
    l = r = y; u = d = x;
    mp[x][y] = 1;
    for(int i=0;i<len - 1;i++){
        if(in[i] == 'L'){
            mp[x][y-1] = mp[x][y-2] = 1;
            y-=2;
        }else if(in[i] == 'R'){
            mp[x][y+1] = mp[x][y+2] = 1;
            y+=2;
        }else if(in[i] == 'U'){
            mp[x-1][y] = mp[x-2][y] = 1;
            x-=2;
        }else if(in[i] == 'D'){
            mp[x+1][y] = mp[x+2][y] = 1;
            x+=2;
        }
        l = min(l, y);
        r = max(r, y);
        u = min(u, x);
        d = max(d, x);
    }
    //printf("%d %d %d %d\n", u, d, l, r);
    for(int i=u-3;i<=d+3;i++){
        for(int j=l-3;j<=r+3;j++){
            f[i * 4500 + j] = i * 4500 + j;
        }
    }
    for(int i=u-1;i<=d+1;i++){
        for(int j=l-1;j<=r+1;j++){
            if(mp[i][j] != 0) continue;
            for(int k=0;k<4;k++){
                int tx = i + dx[k], ty = j + dy[k];
                if(mp[tx][ty] == 0){
                    //printf("m %d %d\n", i * 4500 + j, tx * 4500 + ty);
                    merge(i * 4500 + j, tx * 4500 + ty);
                }
            }
        }
    }
    int ans = 0;
    for(int i=u-1;i<=d+1;i++){
        for(int j=l-1;j<=r+1;j++){
            if(mp[i][j] == 0){
                //printf("%d %d\n", i * 4500 + j, find(i * 4500 + j));
                ans += (i * 4500 + j) == find(i * 4500 + j);
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int T;
    scanf("%d%*c", &T);
    while(T--)
        Solve();
    return 0;
}
