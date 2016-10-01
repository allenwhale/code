#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
#define f first
#define s second
typedef long long ll;
PI ANS[1000];
void Solve(int x){
    vector<PI> vc;
    for(int i=0;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(i <= j && __gcd(i, j) == 1)
                vc.push_back({i, j});
        }
    }
    sort(vc.begin(), vc.end(), [](const PI &a, const PI &b){
            return (double)a.f/(double)a.s < (double)b.f/(double)b.s;
            });
    //for(auto i:vc)
        //printf("%d %d\n", i.f, i.s);
    vector<PI> ans;
    ll a = 0, b = 1;
    for(int i=0;i<(int)vc.size()-1;i++){
        ans.push_back({vc[i].s, vc[i+1].s});
        b = b / __gcd(b, (ll)vc[i+1].s) * (ll)vc[i+1].s;
    }
    //puts("---");
    //for(auto i:ans)
        //printf("%d %d\n", i.f, i.s);
    for(int i=0;i<(int)ans.size();i++){
        a += b / ans[i].s * ans[i].f;
    }
    int d = __gcd(a, b);
    a /= d; b /= d;
    printf("%lld/%lld\n", a, b);
    ANS[x] = {a, b};
}
int main(){
    for(int i=2;i<=20;i++)
        printf("   %d: ", i),
        Solve(i);
    for(int i=2;i<=19;i++){
        printf("%d %d: %d\n", i, i+1, ANS[i+1].f - ANS[i].f);
    }
    return 0;
}
