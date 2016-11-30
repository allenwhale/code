#include <bits/stdc++.h>
using namespace std;
int cnt[64] = {0};
int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i=0;i<N;i++){
        int x;
        scanf("%d", &x);
        for(int j=0;j<32;j++){
            if(x & 1)cnt[j]++;
            if(cnt[j] == K) cnt[j] = 0;
            x>>=1;
        }
    }
    int ans = 0;
    for(int i=31;i>=0;i--){
        ans = ((ans << 1) | (cnt[i] != 0 ? 1 : 0));
    }
    printf("%d\n", ans);
    return 0;
}
