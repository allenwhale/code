#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100010];
ll Solve(){
    int N;
    ll P;
    scanf("%d %lld", &N, &P);
    for(int i=0;i<N;i++)
        scanf("%lld", &s[i]);
    ll sum = 0;
    int end = 0;
    ll ans = 0;
    for(int i=0;i<N;i++){
        while(end < N && sum + s[end] <= P)
            sum += s[end++];
        sum -= s[i];
        ans += end - i;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
        printf("Case #%d: %lld\n", t, Solve());
    return 0;
}
