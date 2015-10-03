#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)&&a&&b){
        printf("%lld\n",(b-a+1)/5ll+1ll);
    }
    return 0;
}
