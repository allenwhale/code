#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];
void Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<N;i++)
        scanf("%d", &b[i]);
    int ans = 0;
    for(int i=0;i<N;i++)
        ans += a[i] != b[i];
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}
