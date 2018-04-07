#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
int A, R, C;
pair<int, int> calc(int x, int y, int d){
    int mnR = d, mnC = d, mxR = R - d + 1, mxC = C - d + 1;
    if(x == mnR && y == mnC){
        return {x + 1, y + 1};
    }else if(x == mnR && y == mxC){
        return {x + 1, y - 1};
    }else if(x == mxR && y == mnC){
        return {x - 1, y + 1};
    }else if(x == mxR && y == mxC){
        return {x - 1, y - 1};
    }else if(x == mnR){
        return {x + 1, y};
    }else if(x == mxR){
        return {x - 1, y};
    }else if(y == mnC){
        return {x, y + 1};
    }else if(y == mxC){
        return {x, y - 1};
    }
    return {-1, -1};
}
bool dig(int x, int y, int d){
    int tx, ty, rx, ry;
    tie(tx, ty) = calc(x, y, d);
    //printf("%d %d / %d %d\n", x, y, tx, ty);
    //return false;
    while(vis[x][y] == false){
        printf("%d %d\n", tx, ty);
        fflush(stdout);
        scanf("%d%d", &rx, &ry);
        vis[rx][ry] = true;
        if(rx == 0 && ry == 0)return true;
    }
    return false;
}
void Solve(){
    memset(vis, false, sizeof(vis));
    scanf("%d", &A);
    if(A == 20)R = 4, C = 5;
    else R = 20, C = 10;
    for(int d = 1 ; d <= R / 2 ; d++){
        for(int i = d ; i < R - d + 1 ; i++){
            //printf("1 %d: ", d);
            if(dig(i, d, d))return;
        }
        for(int i = d ; i < C - d + 1 ; i++){
            //printf("2 %d: ", d);
            if(dig(R - d + 1, i, d))return;
        }
        for(int i = R - d + 1 ; i > d ; i--){
            //printf("3 %d: ", d);
            if(dig(i, C - d + 1, d))return;
        }
        for(int i = C - d + 1 ; i > d ; i--){
            //printf("4 %d: ", d);
            if(dig(d, i, d))return;
        }
    }
    //printf("done\n");
    fflush(stdout);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        Solve();
    }
    return 0;
}
