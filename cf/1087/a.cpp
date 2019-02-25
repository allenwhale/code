#include <bits/stdc++.h>
using namespace std;
char s[100];
int main(){
    scanf("%s", s);
    int len = strlen(s);
    int l = (len - 1) / 2 - 1, r = (len - 1) / 2 + 1;
    printf("%c", s[(len - 1) / 2]);
    while (1) {
        if (r < len) printf("%c", s[r++]);
        else break;
        if (l >= 0) printf("%c", s[l--]);
        else break;
    }
    printf("\n");
    return 0;
}
