#include <bits/stdc++.h>
using namespace std;
char mp[110][110];
int ans[110][110];
int N, M;
int isin(int i, int j){
    return i >= 0 && j >= 0 && i < N && j < M;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool contain(int x, int y, int v){
    for(int i=0;i<4;i++){
        int tx = x + dx[i], ty = y + dy[i];
        if(!isin(tx, ty) && v == 0) return true;
        if(isin(tx, ty) && ans[tx][ty] == v)
            return true;
    } 
    return false;
}
int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)
        scanf("%s", mp[i]);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mp[i][j] == 'T')
                ans[i][j] = -1;
        }
    }
    int mx = 0;
    for(int k=0;k<100;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(ans[i][j] == -1 && contain(i, j, k)){
                    ans[i][j] = k + 1;
                    mx = k + 1;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mx < 10){
                if(ans[i][j] == 0)printf("..");
                else cout << setw(2) << setfill('.') << ans[i][j];
            }else{
                if(ans[i][j] == 0)printf("...");
                else cout << setw(3) << setfill('.') << ans[i][j];
            }
        }
        puts("");
    }
}
