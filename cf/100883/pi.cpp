#include <bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
typedef long long ll;
struct circle{
    ll x, y, r;
};
circle c[110];
ll dist[110][110];
ll Solve(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%I64d%I64d%I64d", &c[i].x, &c[i].y, &c[i].r);
    ll sx, sy, ex, ey;
    scanf("%I64d%I64d%I64d%I64d", &sx, &sy, &ex, &ey);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sqr(c[i].x-c[j].x) + sqr(c[i].y-c[j].y) <= sqr(c[i].r)){
                dist[i][j] = 2;
            }else dist[i][j] = LLONG_MAX;
            dist[i][j] = min(dist[i][j], abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y));
        }
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    ll ans = abs(sx - ex) + abs(sy - ey);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans = min(ans, dist[i][j] + abs(sx - c[i].x) + abs(sy - c[i].y) + abs(ex - c[j].x) + abs(ey - c[j].y));
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        printf("%I64d\n", Solve());
    }
    return 0;
}
