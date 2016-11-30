#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    ll x, y;
    ll Cross(const Point &n) const {
        return x * n.y - y * n.x;
    }
    Point operator - (const Point &n) const {
        return {x - n.x, y - n.y};
    }
}p[100010];
struct Line{
    Point a, b;
}l[100010];
int cmp(ll x){
    if(x == 0)return 0;
    if(x < 0) return -1;
    return 1;
}
void Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    for(int i=0;i<N;i++)
        l[i] = {p[i], p[(i+1)%N]};
    ll U = LLONG_MAX, D = LLONG_MIN, L = LLONG_MIN, R = LLONG_MAX;
    for(int i=0;i<N;i++){
        Line now = l[i];
        Line pre = l[(i - 1 + N) % N];
        Line nxt = l[(i + 1) % N];
        int pre2now = cmp((pre.b - pre.a).Cross(now.b - now.a));
        int now2nxt = cmp((now.b - now.a).Cross(nxt.b - nxt.a));
        int same = pre2now * now2nxt;
        if(same == 1){
            if(now.a.x == now.b.x){//ver
                if((pre2now ^ (now.a.y - now.b.y < 0)) == 1){
                    L = max(L, now.a.x);
                }else{
                    R = min(R, now.a.x);
                }
            }else{//hor
                if((pre2now ^ (now.a.x - now.b.x < 0)) == 1){
                    U = min(U, now.a.y);
                }else{
                    D = max(D, now.a.y);
                }
            }
        }else {
        }
        //printf("%d %lld %lld %lld %lld\n", i, L, R, D, U);
    }
    //printf("%lld %lld %lld %lld\n", L, R, D, U);
    if(L > R || D > U)puts("NO");
    else puts("YES");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
