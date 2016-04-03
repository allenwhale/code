#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100000
char s[2][MAXN+10];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        scanf("%s%s", s[0], s[1]);
        int len = strlen(s[0]);
        ll ans = 0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                int k;
                for(k=0;k<N;k++){
                    if(s[0][(i+k)%len] != s[1][(j+k)%len])
                        break;
                }
                ans += (k == N);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
