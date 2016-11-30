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
    /*
     * range: 0 ~ 2*PI
     */
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
    double Dist(const Point &rhs) const {
        return (*this - rhs).Abs();
    }
    /*
     * unit of d is radian(counterclockwise)
     */
    Point Rotate(double d) const {
        return Rotate(cos(d), sin(d));
    }
    Point Rotate(double cost, double sint) const {
        return Point(x * cost - y * sint, x * sint + y * cost);
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
    Point& update(){
        if(cmp(x) == 0) x = 0;
        if(cmp(y) == 0) y = 0;
        return *this;
    }
}nilPoint(INF, INF);
struct Line{
    Point a, b;
    Line(Point _a=Point(), Point _b=Point()): a(_a), b(_b) {}
    double Dist(const Point &rhs){
        if(cmp((rhs - a).Dot(b - a)) < 0) return (rhs - a).Abs();
        if(cmp((rhs - b).Dot(a - b)) < 0) return (rhs - b).Abs();
        return fabs((a - rhs).Cross(b - rhs) / a.Dist(b));
    }
    /*
     * the pedal of rhs on line
     */
    Point Proj(const Point &rhs){
        double r = (a - b).Dot(rhs - b) / (a - b).Dot(a - b);
        return b + (a - b) * r;
    }
    bool OnLine(const Point &rhs){
        return cmp((rhs - b).Cross(a - b)) == 0;
    }
    bool OnSegment(const Point &rhs){
        return cmp((rhs - b).Cross(a - b)) == 0 && cmp((rhs - b).Dot(rhs - a)) <= 0;
    }
    bool Parallel(const Line &rhs){
        return !cmp((a - b).Cross(rhs.a - rhs.b));
    }
    //for segment
    bool IsIntersect(const Line &rhs){
        if(cmp((rhs.a - a).Cross(rhs.b - a) * (rhs.a - b).Cross(rhs.b - b)) > 0) 
            return false;
        if(cmp((a - rhs.a).Cross(b - rhs.a) * (a - rhs.b).Cross(b - rhs.b)) > 0) 
            return false;
        return true;
    }
    /* default is line */
    Point Intersection(const Line &rhs, bool flag=false){
        if(Parallel(rhs)) return nilPoint;
        /* for segment */
        if(flag && IsIntersect(rhs) == false) return nilPoint;
        /* end */
        double s1 = (a - rhs.a).Cross(rhs.b - rhs.a);
        double s2 = (b - rhs.a).Cross(rhs.b - rhs.a);
        return (b * s1 - a * s2) / (s1 - s2);
    }
    /*
     * move d units along the direction of line
     * example: {(0, 0) -> (1, 1)} move _/2 becomes {(1, 1) -> (2, 2)}
     */
    Line Move(const double &d){
        Point tmp = b - a;
        tmp = tmp / tmp.Abs();
        return Line(a + tmp * d, b + tmp * d);
    }

    friend ostream& operator << (ostream &out, const Line &rhs){
        out << "[" << rhs.a << ", " << rhs.b << "]";
        return out;
    }
}nilLine(nilPoint, nilPoint);
/*
 * default is counterclockwise
 */
struct Polygon{
#define COUNTERCLOCKWISE 1
#define CLOCKWISE       -1
    int N;
    vector<Point> s;
    vector<double> A;
    Polygon(int n=0): N(n) {}
    Polygon& add(const Point &n){
        s.push_back(n);
        return *this;
    }
    /*
     * counterclockwise or clockwise
     * defined as above
     */
    int Order(){
        int t = 0;
        for(int i=0;i<N&&t==0;i++){
            int a = i, b = (i + 1) % N, c = (i + 2) % N;
            t = cmp((s[b] - s[a]).Cross(s[c] - s[b]));
        }
        return t;
    }
    double Perimeter(){
        double res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Dist(s[(i + 1) % N]);
        return res;
    }
    double Area(){
        double res = 0;
        for(int i=0;i<N;i++)
            res += s[i].Cross(s[(i + 1) % N]);
        return fabs(res / 2.0);
    }
#define INSIDE  1
#define ONEDGE  2
#define OUTSIDE 0
    int OnPolygon(const Point &n){
        Point rfn = Point(-INF, n.y);
        Line l = Line(n, rfn);
        int cnt = 0;
        for(int i=0;i<N;i++){
            if(Line(s[i], s[(i + 1) % N]).OnSegment(n))
                return ONEDGE;
            if(cmp(s[i].y - s[(i + 1) % N].y) == 0)
                continue;
            if(l.OnSegment(s[i])){
                if(cmp(s[i].y - s[(i + 1) % N].y) >= 0)
                    cnt++;
            }else if(l.OnSegment(s[(i + 1) % N])){
                if(cmp(s[(i + 1) % N].y - s[i].y) >= 0)
                    cnt++;
            }else if(l.IsIntersect(Line(s[i], s[(i + 1) % N])))
                cnt++;
        }
        return (cnt & 1);
    }
    bool InPoly(const Point &rhs) {
        Line r = {rhs, {123456789, 234567891}};
        int cnt = 0;
        for(int i=0;i<(int)s.size();i++){
            Line l = {s[i], s[(i+1)%s.size()]};
            if(r.IsIntersect(l)){
                cnt++;
            }
        }
        return cnt & 1;
    }
    bool IsIntersect(const Line &rhs){
        int i = (upper_bound(A.begin(), A.end(), (rhs.b-rhs.a).Arg()) - A.begin()) % N;
        int j = (upper_bound(A.begin(), A.end(), (rhs.a-rhs.b).Arg()) - A.begin()) % N;
        if(cmp((rhs.b - rhs.a).Cross(s[i] - rhs.a) * (rhs.b - rhs.a).Cross(s[j] - rhs.a)) <= 0)
            return true;
        return false;
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
        //res.A = vector<double>(res.N);
        //for(int i=0;i<res.N;i++)
        //res.A[i] = (res.s[(i + 1) % res.N] - res.s[i]).Arg();
        return res;
    }
};
struct platform{
    Polygon p;
    int outside, inside;
    bool operator < (const platform &n) const {
        return inside > n.inside;
    }
}p[50010];
struct p3d{
    double x, y, z;
    p3d operator - (const p3d &n) const {
        return {x - n.x, y - n.y, z - n.z};
    }
    p3d operator * (double n)  const {
        return {x * n, y * n, z * n};
    }
    double abs() const {
        return sqrt(x * x + y * y + z * z);
    }
};

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d%d", &p[i].outside, &p[i].inside);
        int num;
        scanf("%d", &num);
        for(int j=0;j<num;j++){
            double x, y;
            scanf("%lf%lf", &x, &y);
            p[i].p.add({x, y});
        }
    }
    sort(p, p + N);
    double ans = 1e15;
    int in = false;
    for(int i=0;i<N;i++){
        int sz = p[i].p.s.size();
        for(int j=0;j<(int)p[i].p.s.size();j++){
            p3d a = {p[i].p.s[j].x, p[i].p.s[j].y, (double)min(p[i].outside, p[i].inside)};
            ans = min(ans, a.abs());
            p3d b = {p[i].p.s[(j+1)%sz].x, p[i].p.s[(j+1)%sz].y, (double)min(p[i].outside, p[i].inside)};
            p3d c = b - a;
            double t = (a.x * c.x + a.y * c.y + a.z * c.z) / (c.x * c.x + c.y * c.y + c.z * c.z);
            p3d d = a - (c * t);
            if(min(a.x, b.x) <= d.x && d.x <= max(a.x, b.x) && 
                    min(a.y, b.y) <= d.y && d.y <= max(a.y, b.y)){
                ans = min(ans, d.abs());
            }
        }
    }
    vector<platform> pp[2];
    for(int i=0;i<N;i++){
        if(p[i].inside < p[i].outside)
            pp[0].push_back(p[i]);
        else pp[1].push_back(p[i]);
    }
    sort(pp[0].begin(), pp[0].end());
    sort(pp[1].begin(), pp[1].end());
    for(int i=0;i<(int)pp[1].size();i++){
        if(in == false && pp[1][i].p.InPoly({0, 0})){
            in = true;
            ans= min(ans, (double)pp[1][i].inside);
        }
    }
    if(in == false && pp[1].size()){
        ans= min(ans, (double)pp[1][0].outside);
    }
    for(int i=pp[0].size()-1;i>=0;i--){
        if(in == false && pp[0][i].p.InPoly({0, 0})){
            in = true;
            ans= min(ans, (double)pp[0][i].inside);
        }
    }
    if(in == false && pp[0].size()){
        ans= min(ans, (double)pp[0][0].outside);
    }
    printf("%.10f\n", ans);
}
