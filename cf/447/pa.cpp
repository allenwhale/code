#include <bits/stdc++.h>
using namespace std;
char s[500];
int main(){
    scanf("%s", s);
    int Qs = 0;
    int sub = 0;
    int ans = 0;
    for(int i = 0 ; s[i] ; i++){
        if(s[i] == 'Q'){
            ans += sub;
            Qs++;
        }else if(s[i] == 'A'){
            sub += Qs;
        }
    }
    printf("%d\n", ans);
    return 0;
}
