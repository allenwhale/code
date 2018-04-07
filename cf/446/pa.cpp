#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010], b[100010];
int main(){
    int N;
    scanf("%d", &N);
    ll sum = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%lld", &b[i]);
    }
    sort(b, b + N);
    if(b[N - 1] + b[N - 2] >= sum)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
