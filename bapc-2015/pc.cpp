#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-6 
#define INF 1e9
const double PI = acos(-1);
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
    ll Dot(const Point &rhs) const {
        return (x * rhs.x + y * rhs.y);
    }
    ll Cross(const Point &rhs) const {
        return (x * rhs.y - y * rhs.x);
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
    ll Area(){
        ll res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Cross(s[(i + 1) % N]);
        return abs(res);
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
                    sz > 1 && ((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        int k = w.size();
        for(int i=(int)that.s.size()-2;i>=0;i--){
            int sz;
            while((sz=w.size()), 
                    sz > k && ((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        if((int)that.s.size() > 1) w.pop_back();
        res.N = w.size();
        //res.A = vector<ll>(res.N);
        //for(int i=0;i<res.N;i++)
        //res.A[i] = (res.s[(i + 1) % res.N] - res.s[i]).Arg();
        return res;
    }
};

ll Area(const Point &a, const Point &b, const Point &c){
    return abs(a.Cross(b) + b.Cross(c) + c.Cross(a));
}


void Solve(){
    int N;
    scanf("%d", &N);
    Polygon p(N);
    for(int i = 0 ; i < N ; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        p.add({x, y});
    }
    p = p.ConvexHull();
    if(p.N <= 4){
        ll ans = p.Area();
        if(ans % 2 == 0)printf("%lld\n", ans / 2);
        else printf("%lld.5\n", ans / 2);
    }else{
        ll ans = 0;
        N = p.N;
        for(int i = 0 ; i < N ; i++){
            int k = (i + 1) % N, l = (i + 3) % N;
            for(int j = (i + 2) % N ; j != i ; j = (j + 1) % N){
                while((k + 1) % N != j && Area(p.s[i], p.s[j], p.s[(k + 1) % N]) > Area(p.s[i], p.s[j], p.s[k])) k = (k + 1) % N;
                while((l + 1) % N != i && Area(p.s[i], p.s[j], p.s[(l + 1) % N]) > Area(p.s[i], p.s[j], p.s[l])) l = (l + 1) % N;
                ans = max(ans, Area(p.s[i], p.s[j], p.s[k]) + Area(p.s[i], p.s[j], p.s[l]));
            }
        }
        if(ans % 2 == 0)printf("%lld\n", ans / 2);
        else printf("%lld.5\n", ans / 2);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
