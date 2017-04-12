#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++){
        long long L, R;
        scanf("%lld%lld", &L, &R);
        long long ans = min(L, R);
        ans = (ans * (ans + 1)) / 2;
        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}
