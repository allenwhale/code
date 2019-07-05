#include <bits/stdc++.h>
using namespace std;
char s[5010];
void Solve() {
    scanf("%s", s);
    int len = strlen(s), B = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'B')
            B++;
    }
    if (B == 0 || B == len - 1 || (B < 2 && len > 3))
        printf("N\n");
    else
        printf("Y\n");
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}