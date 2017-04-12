#include <bits/stdc++.h>
using namespace std;

char in[2010];
int K;
int Solve() {
    scanf("%s", in);
    scanf("%d", &K);
    int len = strlen(in);
    int cnt = 0;
    for(int i = 0 ; i <= len - K ; i++) {
        if(in[i] == '-') {
            for(int j = 0 ; j < K ; j ++) {
                if(in[i + j] == '-') in[i + j] = '+';
                else in[i + j] = '-';
            }
            cnt++;
        }
    }
    bool ans = true;
    for(int i = 0 ; i < len ; i++) {
        ans &= (in[i] == '+');
    }
    if(ans) return cnt;
    else return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1 ; t <= T ; t++) {
        printf("Case #%d: ", t);
        int ans = Solve();
        if(ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
