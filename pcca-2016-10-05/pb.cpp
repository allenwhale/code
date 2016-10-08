#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6 
#define INF 1e9
const double PI = acos(-1);
int cmp(double x){
    if(fabs(x) < EPS) return 0;
    if(x > 0) return 1;
    else return -1;
}
struct Point{
    double x ,y;
    Point(double _x=0, double _y=0): x(_x), y(_y) {}
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (const double &rhs) const {
        return Point(x * rhs, y * rhs);
    }
    Point operator / (const double &rhs) const {
        return Point(x / rhs, y / rhs);
    }
    bool operator == (const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    double Abs() const {
        return sqrt(Dot(*this));
    }
    double Arg() const {
        double res = atan2(y, x);
        if(cmp(res) < 0) res += PI * 2.0;
        return res;
    }
    double Dot(const Point &rhs) const {
        return (x * rhs.x + y * rhs.y);
    }
    double Cross(const Point &rhs) const {
        return (x * rhs.y - y * rhs.x);
    }
    bool operator < (const Point &rhs) const {
        if(x == rhs.x)
            return y < rhs.y;
        return x < rhs.x;
    }
    Point& update(){
        if(cmp(x) == 0) x = 0;
        if(cmp(y) == 0) y = 0;
        return *this;
    }
}nilPoint(INF, INF);
struct Line{
    Point a, b;
    Line(Point _a=Point(), Point _b=Point()): a(_a), b(_b) {}
    bool Parallel(const Line &rhs){
        return !cmp((a - b).Cross(rhs.a - rhs.b));
    }
    bool IsIntersect(const Line &rhs){
        if(cmp((rhs.a - a).Cross(rhs.b - a) * (rhs.a - b).Cross(rhs.b - b)) > 0) 
            return false;
        if(cmp((a - rhs.a).Cross(b - rhs.a) * (a - rhs.b).Cross(b - rhs.b)) > 0) 
            return false;
        return true;
    }
    Point Intersection(const Line &rhs, bool flag=false){
        if(Parallel(rhs)) return nilPoint;
        if(flag && IsIntersect(rhs) == false) return nilPoint;
        double s1 = (a - rhs.a).Cross(rhs.b - rhs.a);
        double s2 = (b - rhs.a).Cross(rhs.b - rhs.a);
        return (b * s1 - a * s2) / (s1 - s2);
    }
}nilLine(nilPoint, nilPoint);
struct Polygon{
    int N;
    vector<Point> s;
    Polygon(int n=0): N(n) {}
    Polygon& add(const Point &n){
        s.push_back(n);
        return *this;
    }
    double Area(){
        double res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Cross(s[(i + 1) % N]);
        return fabs(res / 2.0);
    }
    Polygon ConvexHull(){
        Polygon res, that = *this;
        sort(that.s.begin(), that.s.end());
        //that.s.erase(unique(that.s.begin(), that.s.end()), that.s.end());
        vector<Point> &w = res.s;
        for(int i=0;i<(int)that.s.size();i++){
            int sz;
            while((sz=w.size()), 
                    sz > 1 && cmp((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        int k = w.size();
        for(int i=(int)that.s.size()-2;i>=0;i--){
            int sz;
            while((sz=w.size()), 
                    sz > k && cmp((w[sz - 1] - w[sz - 2]).Cross(that.s[i] - w[sz - 2])) <= 0)
                w.pop_back();
            w.push_back(that.s[i]);
        }
        if((int)that.s.size() > 1) w.pop_back();
        res.N = w.size();
        return res;
    }
};
struct HalfPlane{
    Point a, b;
    HalfPlane(const Point &_a=Point(), const Point &_b=Point()): a(_a), b(_b) {}
    double Value(const Point &rhs) const {
        return (rhs - a).Cross(b - a) ;
    }
    bool Satisfy(const Point &rhs) const {
        return cmp(Value(rhs)) <= 0;
    }
    Point Intersection(const Point &rhs1, const Point &rhs2){
        return Line(a, b).Intersection(Line(rhs1, rhs2));
    }
    Point Intersection(const HalfPlane &rhs){
        return Line(a, b).Intersection(Line(rhs.a, rhs.b));
    }
    bool operator < (const HalfPlane &rhs) const {
        int res = cmp((b - a).Arg() - (rhs.b - rhs.a).Arg());
        return res == 0 ? rhs.Satisfy(a) : (res < 0);
    }
};

struct HalfPlaneSet{
    vector<HalfPlane> s;
    HalfPlaneSet& add(const HalfPlane &rhs){
        s.push_back(rhs);
        return *this;
    }
    Polygon Solve(){
        Polygon res;
        sort(s.begin(), s.end());
        deque<HalfPlane> q;
        deque<Point> ans;
        q.push_back(s[0]);
        for(int i=1;i<(int)s.size();i++){
            if(cmp((s[i].b - s[i].a).Arg() - (s[i - 1].b - s[i - 1].a).Arg()) == 0) continue;
            while(ans.size() > 0 && s[i].Value(ans.back()) >= 0){
                ans.pop_back();
                q.pop_back();
            }
            while(ans.size() > 0 && s[i].Value(ans.front()) >= 0){
                ans.pop_front();
                q.pop_front();
            }
            ans.push_back(q.back().Intersection(s[i]));
            q.push_back(s[i]);
        }
        while(ans.size() > 0 && q.front().Value(ans.back()) >= 0){
            ans.pop_back();
            q.pop_back();
        }
        while(ans.size() > 0 && q.back().Value(ans.front()) >= 0){
            ans.pop_front();
            q.pop_front();
        }
        ans.push_back(q.back().Intersection(q.front()));
        for(int i=0;i<(int)ans.size();i++)
            res.add(ans[i]);
        res.N = res.s.size();
        return res;
    }
};
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d%d", &N, &M);
        Polygon a(N), b(M);
        for(int i=0;i<N;i++){
            double x, y;
            scanf("%lf%lf", &x, &y);
            a.add({x, y});
        }
        for(int i=0;i<M;i++){
            double x, y;
            scanf("%lf%lf", &x, &y);
            b.add({x, y});
        }
        a = a.ConvexHull();
        b = b.ConvexHull();
        HalfPlaneSet hps;
        for(int i=0;i<(int)a.s.size();i++){
            hps.add({a.s[i], a.s[(i+1)%a.s.size()]});
        }
        for(int i=0;i<(int)b.s.size();i++){
            hps.add({b.s[i], b.s[(i+1)%b.s.size()]});
        }
        printf("%.10f\n", hps.Solve().Area());
    }
    return 0;
}
