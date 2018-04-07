#include <bits/stdc++.h>
using namespace std;

int pow2[40];

void Solve(){
    int D;
    char P[50];
    scanf("%d%s", &D, P + 1);
    int len = strlen(P + 1), cnt = 0;
    for(int i = 1 ; i <= len ; i++)
        cnt += (P[i] == 'S');
    if(cnt > D){
        printf("IMPOSSIBLE\n");
        return;
    }
    int sum[50];
    sum[0] = 0;
    for(int i = 1 ; i <= len ; i++)
        sum[i] = sum[i - 1] + (P[i] == 'C');
    int now = 0;
    for(int i = 1 ; i <= len ; i++){
        if(P[i] == 'S')
            now += pow2[sum[i - 1]];
    }
    int ans = 0;
    while(now > D){
        int idx = -1;
        for(int i = len - 1 ; i >= 1 ; i--){
            if(P[i] == 'C' && P[i + 1] == 'S'){
                idx = i;
                break;
            }
        }
        if(idx == -1)break;
        sum[idx]--;
        swap(P[idx], P[idx + 1]);
        now -= pow2[sum[idx]];
        ans++;
    }
    if(now > D)printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
}

int main(){
    pow2[0] = 1;
    for(int i = 1 ; i <= 30 ; i++)
        pow2[i] = pow2[i - 1] * 2;
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
