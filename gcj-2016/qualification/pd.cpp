#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int K, C, S;
        scanf("%d%d%d", &K, &C, &S);
        printf("Case #%d:", t);
        if(S * C < K)puts(" IMPOSSIBLE");
        else{
            int cnt = 0;
            while(cnt < K){
                long long res = 0;
                for(int i=0;i<C;i++){
                    res = res * K + (cnt < K ? cnt : K - 1);
                    cnt++;
                }
                printf(" %lld", res + 1);
            }
            puts("");
        }
    }
    return 0;
}
