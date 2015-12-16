#include <stdio.h>
#include <string.h>
bool vis[10010];
int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    int ans = 0;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        if(vis[x] == false){
            vis[x] = true;
            cnt++;
            if(cnt == K){
                cnt = 0;
                ans++;
                memset(vis, false, sizeof(vis));
            }
        }
    }
    printf("%d\n", ans+1);
}
