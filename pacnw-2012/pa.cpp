#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[] = {1, 2, 3, 3, 4, 10};
ll b[] = {1, 2, 2, 2, 3, 5, 10};
void Solve(){
    ll A = 0, B = 0;
    for(int i=0;i<6;i++){
        ll x;
        scanf("%lld", &x);
        A += x * a[i];
    }
    for(int i=0;i<7;i++){
        ll x;
        scanf("%lld", &x);
        B += x * b[i];
    }
    if(A > B)
        printf("Good triumphs over Evil\n");
    else if(B > A)
        printf("Evil eradicates all trace of Good\n");
    else
        printf("No victor on this battle field\n");
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Battle %d: ", t);
        Solve();
    }
    return 0;
}
