#include <bits/stdc++.h>
using namespace std;
int d[100010];
int vis[100010];
int Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &d[i]);
    int ans = 0;
    int now = 0;
    memset(vis, false, sizeof(vis));
    while(now < N){
        if(vis[now]){
            now++;
            continue;
        }
        vis[now] = true;
        //printf("now: %d\n", now);
        for(int i=2;i>=0;i--){
            //printf("ans: %d %d\n", ans, i);
            if(now == N - 1){
                //puts("1");
                ans += i + 1;
                now++;
                break;
            }else{
                if(d[now] >= d[now + 1]){
                //puts("2");
                    ans += i + 1;
                    now++;
                    break;
                }else{
                    if(d[now + 1] - d[now] <= 10){
                //puts("3");
                        now++;
                        vis[now] = true;
                    }else{
                        if(d[now + 1] - d[now] <= (i+1) * 10){
                //puts("4");
                            ans += i;
                            now++;
                            vis[now] = true;
                        }else{
                //puts("5");
                            ans += i + 1;
                            now++;
                        }
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
        printf("Case #%d: %d\n", t, Solve());
    return 0;
}
