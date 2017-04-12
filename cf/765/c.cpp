#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    ll wina = a / k, winb = b / k;
    ll ans = ll(wina) + ll(winb);
    if((b % k && !wina) || (a % k && !winb))
        printf("-1\n");
    else cout << ans << endl;
    return 0;
}
