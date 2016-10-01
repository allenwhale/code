#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    ll x, y;
    bool operator < (const Point &n) const{
        if(x == n.x)
            return y < n.y;
        return x < n.x;
    }

    Point operator - (const Point &n) const {
        return {x - n.x, y - n.y};
    }
    ll Cross(const Point &n) const {
        return x * n.y - y * n.x;
    }
};
ll ans_area[2][100010];
int main(){
    int N;
    scanf("%d", &N);
    vector<Point> p(N);
    for(int i=0;i<N;i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    {
        sort(p.begin(), p.end());
        vector<Point> w[2];
        int last[2] = {0};
        ll area[2] = {0};
        for(int k=0;k<(int)p.size();k++){
            for(int &i=last[0];i<(int)p.size();i++){
                if(p[i].x > p[k].x)break;
                int sz = w[0].size();
                while((sz = w[0].size()), sz > 1 && (w[0][sz-1]-w[0][sz-2]).Cross(p[i]-w[0][sz-2]) >= 0){
                    area[0] -= (w[0][sz-1] - w[0][0]).Cross(w[0][sz-2] - w[0][0]);
                    w[0].pop_back();
                }
                w[0].push_back(p[i]);
                sz = w[0].size();
                if(sz > 1){
                    area[0] += (w[0][sz-1] - w[0][0]).Cross(w[0][sz-2] - w[0][0]);
                }
            }
            //printf("k %d\n", k);
            for(int &i=last[1];i<(int)p.size();i++){
                if(p[i].x > p[k].x)break;
                int sz = w[1].size();
                while((sz = w[1].size()), sz > 1 && (w[1][sz-1]-w[1][sz-2]).Cross(p[i]-w[1][sz-2]) <= 0){
                    area[1] += (w[1][sz-1] - w[1][0]).Cross(w[1][sz-2] - w[1][0]);
                    //printf("pop %lld %lld %lld\n", w[1][sz-1].x, w[1][sz-1].y, area[1]);
                    w[1].pop_back();
                }
                w[1].push_back(p[i]);
                sz = w[1].size();
                if(sz > 1)
                    area[1] -= (w[1][sz-1] - w[1][0]).Cross(w[1][sz-2] - w[1][0]);
                //printf("aa %lld\n", area[1]);
            }
            ans_area[0][k] = area[0] + area[1];
            //printf(" %d %lld %lld %lld\n", k, area[0], area[1], ans_area[0][k]);
        }
    }
    for(auto &x:p)
        x.x = -x.x;
    {
        sort(p.begin(), p.end());
        vector<Point> w[2];
        int last[2] = {0};
        ll area[2] = {0};
        for(int k=0;k<(int)p.size();k++){
            for(int &i=last[0];i<(int)p.size();i++){
                if(p[i].x >= p[k].x)break;
                int sz = w[0].size();
                while((sz = w[0].size()), sz > 1 && (w[0][sz-1]-w[0][sz-2]).Cross(p[i]-w[0][sz-2]) >= 0){
                    area[0] -= (w[0][sz-1] - w[0][0]).Cross(w[0][sz-2] - w[0][0]);
                    w[0].pop_back();
                }
                w[0].push_back(p[i]);
                sz = w[0].size();
                if(sz > 1){
                    area[0] += (w[0][sz-1] - w[0][0]).Cross(w[0][sz-2] - w[0][0]);
                }
            }
            for(int &i=last[1];i<(int)p.size();i++){
                if(p[i].x >= p[k].x)break;
                int sz = w[1].size();
                while((sz = w[1].size()), sz > 1 && (w[1][sz-1]-w[1][sz-2]).Cross(p[i]-w[1][sz-2]) <= 0){
                    area[1] += (w[1][sz-1] - w[1][0]).Cross(w[1][sz-2] - w[1][0]);
                    w[1].pop_back();
                }
                w[1].push_back(p[i]);
                sz = w[1].size();
                if(sz > 1)
                    area[1] -= (w[1][sz-1] - w[1][0]).Cross(w[1][sz-2] - w[1][0]);
            }
            ans_area[1][k] = area[0] + area[1];
            //printf(" %d %lld\n", k, ans_area[1][k]);
        }
    }
    ll ans = LLONG_MAX;
    for(int i=0;i<N;i++)
        ans = min(ans, ans_area[0][i] + ans_area[1][N-i-1]);
    printf("%lld\n", (ans+1)/ 2);
    return 0;
}
