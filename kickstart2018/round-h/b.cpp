#include <bits/stdc++.h>
using namespace std;
int b[5000005];
void Solve(){
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%1d", &b[i]);
    }
    int r = (N + 1) / 2 - 1, l = 0;
    int sum = 0, ans = 0;
    for (int i = 0; i < r; i++) {
        sum += b[i];
    }
    while (r < N) {
        sum += b[r];
        ans = max(ans, sum);
        r++;
        sum -= b[l];
        l++;
    }
    printf("%d\n", ans);
}
int main(){
    int T;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
