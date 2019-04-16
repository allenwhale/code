#include <bits/stdc++.h>
using namespace std;
void flush()
{
    fflush(stdout);
}
typedef long long ll;
ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0ll)
    {
        d = ext_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
        x = 1ll, y = 0ll;
    return d;
}
ll mod_inverse(ll n, ll p)
{
    ll x, y;
    ll d = ext_gcd(n, p, x, y);
    return (p + x % p) % p;
}
int CRT(vector<int> a, vector<int> m)
{
    if (a.size() != m.size())
        return -1;
    int M = 1;
    for (int i = 0; i < (int)m.size(); i++)
        M *= m[i];
    int res = 0;
    for (int i = 0; i < (int)a.size(); i++)
        res = (res + (M / m[i]) * mod_inverse(M / m[i], m[i]) * a[i]) % M;
    return (res + M) % M;
}
vector<int> ps = {16, 9, 5, 7, 11, 13, 17};
bool Solve()
{
    vector<int> a;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            printf("%d ", ps[i]);
        }
        printf("\n");
        flush();
        int sum = 0;
        for (int j = 0; j < 18; j++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        sum %= ps[i];
        a.push_back(sum);
        // printf("a=%d\n", sum);
    }
    int ans = CRT(a, ps);
    printf("%d\n", ans);
    flush();
    int v;
    scanf("%d", &v);
    return v == 1;
}
int main()
{
    int T;
    scanf("%d%*d%*d", &T);
    for (int t = 1; t <= T; t++)
    {
        if (Solve() == false)
            break;
    }
}