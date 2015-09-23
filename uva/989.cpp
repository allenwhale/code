#include <bits/stdc++.h>
using namespace std;
int b[10][10];
bool r[10][10];
bool c[10][10];
bool s[10][10];
#define SQR(i,j) ((j/N)+(i/N)*N)
int N;
int dfs(int x,int y){
    //printf("%d %d\n", x, y);
    if(y==N*N)return dfs(x+1,0);
    if(x==N*N){
        return true;
    }
    if(b[x][y] != 0)return dfs(x,y+1);
    for(int i=1;i<=N*N;i++){
        if(!s[SQR(x,y)][i]&&!r[x][i]&&!c[y][i]){
            s[SQR(x,y)][i] = true;
            r[x][i] = true;
            c[y][i] = true;
            b[x][y] = i;
            if(dfs(x,y+1))return true;
            b[x][y] = 0;
            s[SQR(x,y)][i] = false;
            r[x][i] = false;
            c[y][i] = false;
        }
    }
    return false;
}
void Solve(){
    memset(r,false,sizeof(r));
    memset(c,false,sizeof(c));
    memset(s,false,sizeof(s));
    for(int i=0;i<N*N;i++){
        for(int j=0;j<N*N;j++){
            if(b[i][j]){
                s[SQR(i,j)][b[i][j]] = true;
                r[i][b[i][j]] = true;
                c[j][b[i][j]] = true;
            }
        }
    }
    if(!dfs(0,0)){
        puts("NO SOLUTION");
        return ;
    }
    for(int i=0;i<N*N;i++){
        for(int j=0;j<N*N;j++){
            printf("%d%c",b[i][j],j==(N*N)-1?'\n':' ');
        }
    }
}
int main(){
    bool tf=true;
    while(~scanf("%d",&N)){
        memset(b,0,sizeof(b));
        for(int i=0;i<N*N;i++){
            for(int j=0;j<N*N;j++){
                scanf("%d",&b[i][j]);
            }
        }
        if(!tf)puts("");
        tf=false;
        Solve();
    }
    return 0;
}
