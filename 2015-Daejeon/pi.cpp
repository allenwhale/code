#include <bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010];
void Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);
    b[N - 1] = a[N - 1];
    for(int i=N-2;i>=0;i--){
        b[i] = max(a[i], b[i + 1]);
    }
    long long ans = 0;
    for(int i=0;i<N;i++)
        ans += (long long)(b[i] - a[i]);
    printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
