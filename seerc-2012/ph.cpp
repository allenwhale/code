#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ext_gcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0ll){
		d = ext_gcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else x = 1ll, y = 0ll;
	return d;
}
ll mod_inverse(ll n, ll p){
	ll x, y;
	ll d = ext_gcd(n, p, x, y);
	return (p + x % p) % p;
}
int CRT(vector<int> a, vector<int> m) {
	if(a.size() != m.size()) return -1;
	int M = 1;
	for(int i=0;i<(int)m.size();i++)
		M *= m[i];
	int res = 0;
	for(int i=0;i<(int)a.size();i++)
		res = (res + (M/m[i])*mod_inverse(M/m[i], m[i])*a[i]) % M;
	return (res + M) % M;
}

int main(){
    vector<int> a={4, 3};
    vector<int> b={1, 0};
    int ans = CRT(b, a);
    printf("%d\n", ans);
    return 0;
}
