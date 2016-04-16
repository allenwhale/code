#include <bits/stdc++.h>
using namespace std;
int cnt[3000];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        memset(cnt, 0, sizeof(cnt));
        int N;
        scanf("%d", &N);
        for(int i=0;i<N*2-1;i++){
            for(int j=0;j<N;j++){
                int a;
                scanf("%d", &a);
                cnt[a]++;
            }
        }
        printf("Case #%d:", t);
        for(int i=1;i<=2500;i++){
            if(cnt[i] & 1)printf(" %d", i);
        }
        puts("");
    }
    return 0;
}
