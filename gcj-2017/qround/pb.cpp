#include <bits/stdc++.h>
using namespace std;
char in[1010];
void Solve() {
    scanf("%s", in);
    int len = strlen(in);
    if(len == 1) {
        puts(in);
        return;
    }
    int x = -1;
    for(int i = 1 ; i < len ; i++) {
        if(in[i] < in[i - 1]) {
            x = i;
            break;
        }
    }
    if(x == -1) {
        puts(in);
        return;
    }
    for(int i = x ; i >= 1 ; i--) {
        if(in[i - 1] > in[i]) {
            in[i] = '9';
            in[i - 1] = in[i - 1] - 1;
        }
    }
    int i = 0;
    while(in[i] == '0') i++;
    for(; i <= x ; i++) {
        printf("%c", in[i]);
    }
    for(; i < len ; i++) {
        printf("9");
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T ; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
