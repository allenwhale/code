#include <bits/stdc++.h>
using namespace std;
int B[3010];
int main(){
    memset(B, 0, sizeof(B));
    int N, V;
    scanf("%d%d", &N, &V);
    int mx = 0;
    for(int i=0;i<N;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        B[a] += b;
        mx = max(mx, a);
    }
    int ans = 0;
    for(int i=1;i<=mx+1;i++){
        int now = 0;
        if(B[i-1]){
            now += min(B[i-1], V);
            B[i-1] -= now;
        }
        if(now < V && B[i]){
            int tmp = min(B[i], V-now);
            now += tmp;
            B[i] -= tmp;
        }
        ans += now;
    }
    printf("%d\n", ans);
}
