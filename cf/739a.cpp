#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int ans = INT_MAX;
    for(int i=0;i<M;i++){
        int l, r;
        scanf("%d%d", &l, &r);
        ans = min(ans, r - l + 1);
    }
    printf("%d\n", ans);
    for(int i=0;i<N;i++)
        printf("%d ", i % ans);
    puts("");
    return 0;
}
