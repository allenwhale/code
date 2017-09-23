#include <bits/stdc++.h>
using namespace std;
#define INF 1e10

typedef long long ll;

struct Point{
    ll x ,y;
    Point(ll _x=0, ll _y=0): x(_x), y(_y) {}
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (const ll &rhs) const {
        return Point(x * rhs, y * rhs);
    }
    Point operator / (const ll &rhs) const {
        return Point(x / rhs, y / rhs);
    }
    bool operator == (const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    ll Abs() const {
        return (Dot(*this));
    }
    ll Dot(const Point &rhs) const {
        return (x * rhs.x + y * rhs.y);
    }
    ll Cross(const Point &rhs) const {
        return (x * rhs.y - y * rhs.x);
    }
    ll Dist(const Point &rhs) const {
        return (*this - rhs).Abs();
    }
    bool operator < (const Point &rhs) const {
        if(x == rhs.x)
            return y < rhs.y;
        return x < rhs.x;
    }
    friend ostream& operator << (ostream &out, const Point &rhs){
        out << "(" << rhs.x << ", " << rhs.y << ")";
        return out;
    }
}nilPoint(INF, INF);
/*
 * default is counterclockwise
 */
struct Polygon{
#define COUNTERCLOCKWISE 1
#define CLOCKWISE       -1
    int N;
    vector<Point> s;
    vector<ll> A;
    Polygon(int n=0): N(n) {}
    Polygon& add(const Point &n){
        s.push_back(n);
        return *this;
    }
    Polygon ConvexHull(){
        //it is clockwise
        Polygon res, that = *this;
        sort(that.s.begin(), that.s.end());
        that.s.erase(unique(that.s.begin(), that.s.end()), that.s.end());
        vector<Point> &w = res.s;
        for(int i=0;i<(int)that.s.size();i++){
            int sz;
            while((sz=w.size()), 
                    sz > 1 && (w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2]) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        int k = w.size();
        for(int i=(int)that.s.size()-2;i>=0;i--){
            int sz;
            while((sz=w.size()), 
                    sz > k && (w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2]) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        if((int)that.s.size() > 1) w.pop_back();
        res.N = w.size();
        return res;
    }
};
void Solve(){
    int N;
    scanf("%d", &N);
    Polygon p(2 * N);
    for(int i = 0 ; i < N ; i++){
        ll x, y, w;
        scanf("%lld%lld%lld", &x, &y, &w);
        p.add({x, y}).add({x + w, y + w}).add({x + w, y}).add({x, y + w});
    }
     p = p.ConvexHull();
     N = p.N;
     ll ans = 0;
     for(int i = 0, j = 1 ; i < N ; i++){
        while(p.s[i].Dist(p.s[(j + 1) % N]) > p.s[i].Dist(p.s[j]))
            j = (j + 1) % N;
        ans = max(ans, p.s[i].Dist(p.s[j]));
     }
     printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
