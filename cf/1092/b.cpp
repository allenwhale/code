#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    int ans = 0;
    for (int i = 0; i < N; i += 2) {
        ans += a[i + 1] - a[i];
    }
    printf("%d\n", ans);
    return 0;
}
