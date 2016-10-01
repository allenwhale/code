#include <bits/stdc++.h>
using namespace std;
int mp[15][15];
bool hole[15][15];
bool square[15][15];
bool ball[15][15];
int S, N, M, K, Q;
char op[50];
map<char, int> dir;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool isok(int x, int y, int d){
    if(mp[x][y] & (1<<d))return false;
    x += dx[d]; y += dy[d];
    if(ball[x][y])return false;
    return true;
}
int go(int x, int y, int d){
    int res = 0;
    while(true){
        //printf("test %d %d %d\n", x, y, mp[x][y]&(1<<d));
        if(!isok(x, y, d))break;
        //printf("go %d %d %d\n", x, y, d);
        ball[x][y] = false;
        x += dx[d]; y += dy[d];
        if(hole[x][y]){
            hole[x][y] = false;
            break;
        }
        ball[x][y] = true;
        if(square[x][y]){
            square[x][y] = false;
            res++;
        }
    }
    return res;
}
int main(){
    dir['W'] = 0;
    dir['S'] = 1;
    dir['E'] = 2;
    dir['N'] = 3;
    int T;
    scanf("%d", &T);
    while(T--){
        memset(mp, 0, sizeof(mp));
        memset(hole, 0, sizeof(hole));
        memset(square, 0, sizeof(square));
        memset(ball, 0, sizeof(ball));
        scanf("%d%d%d%d%d", &S, &N, &M, &K, &Q);
        for(int i=1;i<=S;i++){
            for(int j=1;j<=S;j++){
                scanf("%1X", &mp[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            ball[x][y] = true;
        }
        for(int i=0;i<M;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            square[x][y] = true;
        }
        for(int i=0;i<K;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            hole[x][y] = true;
        }
        scanf("%s", op);
        int ans = 0;
        for(int k=0;k<Q;k++){
            //printf("before %c\n", op[k]);
            //for(int x=1;x<=S;x++){
            //for(int y=1;y<=S;y++){
            //printf("%d", ball[x][y]);
            //}
            //puts("");
            //}
            if(op[k] == 'E'){
                for(int i=1;i<=S;i++){
                    for(int j=1;j<=S;j++){
                        if(ball[i][j])
                            ans += go(i, j, 0);
                    }
                }
            }else if(op[k] == 'N'){
                for(int i=S;i>=1;i--){
                    for(int j=1;j<=S;j++){
                        if(ball[i][j])
                            ans += go(i, j, 1);
                    }
                }
            }else if(op[k] == 'W'){
                for(int i=1;i<=S;i++){
                    for(int j=S;j>=1;j--){
                        if(ball[i][j])
                            ans += go(i, j, 2);
                    }
                }
            }else if(op[k] == 'S'){
                for(int i=1;i<=S;i++){
                    for(int j=1;j<=S;j++){
                        if(ball[i][j])
                            ans += go(i, j, 3);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}

