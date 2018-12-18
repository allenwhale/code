#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll x[200010];
bool check(ll last, ll x){
	// printf("ck %lld %lld\n", last, x);
	// getchar();
    ll a = 1, b = last - 1, c = -x;
    ll k = sqrt(b * b - 4 * a * c) + 0.1;
    ll k1 = (double)(-b + k) / (double)(2 * a) + 0.1, k2 = (double)(-b - k) / (double)(2 * a) + 0.1;

	// printf("abc %lld %lld %lld\n", a, b, c);
	// printf("k %lld %lld\n", k1, k2);

    if (a * k1 * k1 + b * k1 + c == 0) {
        return true;
    }
    if (a * k2 * k2 + b * k2 + c == 0) {
        return true;
    }
    return false;
}
int main(){
    scanf("%d", &N);
    for (int i = 1; i < N; i += 2) {
        scanf("%lld", &x[i]);
    }
    ll now = 0;
    ll last = 1;
    bool ans = true;
    for (int i = 1; i < N; i += 2) {
        ll l = last, s = 0;
        while (s < x[i]) {
            s += l;
            l += 2;
        }
        while (l <= 10000000ll) {
			// printf("cck %lld %lld %lld\n", last, l, s, x[i]);
            if (check(last, s - x[i])) {
                x[i - 1] = s - x[i];
                last = l;
                break;
            }
            s += l;
            l += 2;
        }
		// printf(" %lld\n", x[i - 1]);
    }
    for (int i = 0; i < N; i++) {
        if (x[i] <= 0 || x[i] > 10000000000000ll) {
            ans = false;
        }
    }
    if (ans) {
        printf("Yes\n");
        for (int i = 0; i < N; i++) {
            printf("%lld ", x[i]);
        }
        printf("\n");
    }else{
        printf("No\n");
    }
}
